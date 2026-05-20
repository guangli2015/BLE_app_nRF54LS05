/*
 * GRTC system timer for bare-metal (SYSCOUNTER + 1 ms tick).
 * Required by S115 SoftDevice before sd_softdevice_enable().
 */
#ifndef GRTC_SYS_H__
#define GRTC_SYS_H__

#include <stdint.h>
#include <stdbool.h>

/** Application GRTC interrupt priority (keep above SoftDevice levels 0–4). */
#define GRTC_SYS_IRQ_PRIORITY 6U

/**
 * @brief Start LFCLK, GRTC SYSCOUNTER, and 1 ms tick.
 *
 * Call before softdevice_irq_init() / nrf_sdh_enable_request().
 *
 * @retval 0  Success.
 * @retval -1 Failure.
 */
int grtc_sys_init(void);

/** Monotonic milliseconds from GRTC tick (updated in ISR). */
uint32_t grtc_sys_get_ms(void);

/** SYSCOUNTER value in microseconds (1 MHz). */
uint64_t grtc_sys_get_us(void);

#endif /* GRTC_SYS_H__ */
