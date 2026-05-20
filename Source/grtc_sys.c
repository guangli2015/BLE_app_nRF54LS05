/*
 * GRTC system timer for bare-metal (SYSCOUNTER + 1 ms tick).
 */
#include "grtc_sys.h"

#include <nrfx.h>
#include <nrfx_grtc.h>
#include <nrfx_clock.h>

#define SYSCOUNTER_HZ      1000000ULL
#define TICK_INTERVAL_US   1000ULL

static volatile uint32_t m_ticks_ms;

static void tick_handler(int32_t id, uint64_t cc_val, void * p_context);
static nrfx_grtc_channel_t m_tick_ch = {
	.handler   = tick_handler,
	.p_context = NULL,
	.channel   = (uint8_t)-1,
};

static uint64_t syscounter_now(void)
{
	return nrfx_grtc_syscounter_get();
}

static void tick_schedule_abs(uint64_t cc_abs)
{
	(void)nrfx_grtc_syscounter_cc_absolute_set(&m_tick_ch, cc_abs, true);
}

static void tick_handler(int32_t id, uint64_t cc_val, void * p_context)
{
	(void)id;
	(void)p_context;

	m_ticks_ms++;
	tick_schedule_abs(cc_val + TICK_INTERVAL_US);
}

void GRTC_2_IRQHandler(void)
{
	nrfx_grtc_irq_handler();
}

int grtc_sys_init(void)
{
	int err;
	uint64_t next_cc;

	err = nrfx_clock_init(NULL);
	if (err != 0) {
		return -1;
	}

	nrfx_clock_enable();

	while (!nrfx_clock_lfclk_running_check(NULL)) {
	}

	/* Match system LFCLK; same source family as SoftDevice NRF_CLOCK_LF_SRC_XTAL. */
	nrfx_grtc_clock_source_set(NRF_GRTC_CLKSEL_LFCLK);

	err = nrfx_grtc_init(GRTC_SYS_IRQ_PRIORITY);
	if (err != 0) {
		return -1;
	}

	err = nrfx_grtc_syscounter_start(true, &m_tick_ch.channel);
	if (err != 0) {
		return -1;
	}

	next_cc = syscounter_now() + TICK_INTERVAL_US;
	tick_schedule_abs(next_cc);

	return 0;
}

uint32_t grtc_sys_get_ms(void)
{
	return m_ticks_ms;
}

uint64_t grtc_sys_get_us(void)
{
	return syscounter_now();
}
