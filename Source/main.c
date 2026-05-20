/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------

File    : main.c
Purpose : Generic application start

*/



#include <hal/nrf_gpio.h>
#include "irq_connect.h"

#include <nrfx_grtc.h>
#include <nrfx_clock.h>
#include <stdbool.h>
#include "SEGGER_RTT.h"
#ifndef BOARD_PIN_LED_0
#define BOARD_PIN_LED_0 NRF_PIN_PORT_TO_PIN_NUMBER(0, 0)
#endif
#ifndef BOARD_PIN_LED_1
#define BOARD_PIN_LED_1 NRF_PIN_PORT_TO_PIN_NUMBER(1, 0)
#endif
#ifndef BOARD_PIN_LED_2
#define BOARD_PIN_LED_2 NRF_PIN_PORT_TO_PIN_NUMBER(2, 0)
#endif
#ifndef BOARD_PIN_LED_3
#define BOARD_PIN_LED_3 NRF_PIN_PORT_TO_PIN_NUMBER(3, 0)
#endif

#define GPIO_ACTIVE_HIGH 1

extern int sftdevice_test(void);
extern int softdevice_irq_init(void);

void SysTick_Configuration(void);
/*********************************************************************
*
*       main()
*
*  Function description
*   Application entry point.
*/
extern uint32_t __flash_origin;
int main(void) {
  int i;

    SysTick_Configuration();
  softdevice_irq_init();
  SEGGER_RTT_printf(0, "\n 11app in in 0x%x\n",(uint32_t)&__flash_origin);
    nrf_gpio_cfg_output(BOARD_PIN_LED_0);
  nrf_gpio_cfg_output(BOARD_PIN_LED_1);
  nrf_gpio_cfg_output(BOARD_PIN_LED_2);
  nrf_gpio_cfg_output(BOARD_PIN_LED_3);


  nrf_gpio_pin_write(BOARD_PIN_LED_0, 0);
  nrf_gpio_pin_write(BOARD_PIN_LED_1, 0);
  nrf_gpio_pin_write(BOARD_PIN_LED_3, 0);
  nrf_gpio_pin_write(BOARD_PIN_LED_2, 1);
sftdevice_test();
}
void _start(void) {
main();
    
}

/*--------------------add GRTC driver for systick by Andrew------------------------------*/
#if 1
#define SYS_CLOCK_HW_CYCLES_PER_SEC 1000000
#define SYS_CLOCK_TICKS_PER_SEC 1000
#define CYC_PER_TICK                                                                               \
	((uint64_t)SYS_CLOCK_HW_CYCLES_PER_SEC / (uint64_t)SYS_CLOCK_TICKS_PER_SEC)
static void sys_clock_timeout_handler(int32_t id, uint64_t cc_val, void *p_context);
static nrfx_grtc_channel_t system_clock_channel_data = {
	.handler = sys_clock_timeout_handler,
	.p_context = NULL,
	.channel = (uint8_t)-1,
};
static uint64_t last_count; /* Time (SYSCOUNTER value) @last sys_clock_announce() */
static inline uint64_t counter(void)
{
	uint64_t now;
	now=nrfx_grtc_syscounter_get();
	return now;
}
static inline uint64_t counter_sub(uint64_t a, uint64_t b)
{
	return (a - b);
}
/*
 * Program a new callback in the absolute time given by <value>
 */
static void system_timeout_set_abs(uint64_t value)
{
	nrfx_grtc_syscounter_cc_absolute_set(&system_clock_channel_data, value,
					     true);
}
static void sys_clock_timeout_handler(int32_t id, uint64_t cc_val, void *p_context)
{
	//ARG_UNUSED(id);
	//ARG_UNUSED(p_context);
	uint64_t dticks;
	uint64_t now = counter();

	//if (unlikely(now < cc_val)) {
	//	return;
	//}

	dticks = counter_sub(cc_val, last_count) / CYC_PER_TICK;

	last_count += dticks * CYC_PER_TICK;


	system_timeout_set_abs(last_count + CYC_PER_TICK);
        //SEGGER_RTT_printf(0, "*");
#if 0
        uint32_t ulPreviousMask;

    ulPreviousMask = portSET_INTERRUPT_MASK_FROM_ISR();
    traceISR_ENTER();
    {
        /* Increment the RTOS tick. */
        if( xTaskIncrementTick() != pdFALSE )
        {
            traceISR_EXIT_TO_SCHEDULER();
            /* Pend a context switch. */
            portNVIC_INT_CTRL_REG = portNVIC_PENDSVSET_BIT;
        }
        else
        {
            traceISR_EXIT();
        }
    }
    portCLEAR_INTERRUPT_MASK_FROM_ISR( ulPreviousMask );
    #endif
}

static void clk_event_handler(nrfx_clock_evt_type_t event){}
static void system_timeout_set_relative(uint64_t value)
{
	if (value <= NRF_GRTC_SYSCOUNTER_CCADD_MASK) {
		nrfx_grtc_syscounter_cc_relative_set(&system_clock_channel_data, value, true,
						     NRFX_GRTC_CC_RELATIVE_SYSCOUNTER);
	} else {
		nrfx_grtc_syscounter_cc_absolute_set(&system_clock_channel_data, value + counter(),
						     true);
	}
}
static int sys_clock_driver_init(void)
{
  int err_code;

  nrfx_grtc_clock_source_set(NRF_GRTC_CLKSEL_LFXO);

  err_code = nrfx_grtc_init(5);
  if (err_code != 0) {
		return -1;
  }


  err_code = nrfx_grtc_syscounter_start(true, &system_clock_channel_data.channel);
  if (err_code != 0) {
		return -1;
  }
	
  system_timeout_set_relative(CYC_PER_TICK);
  return 0;

}
void SysTick_Configuration(void)
{
  nrfx_clock_init(clk_event_handler);	
  //nrfx_clock_enable();
  sys_clock_driver_init();
  //nrfx_clock_lfclk_start();
}
#endif
/*************************** End of file ****************************/
