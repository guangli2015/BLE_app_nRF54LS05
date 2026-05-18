/*
 * Copyright (c) 2025 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <nrf_soc.h>
#include <nrf_sdh_soc.h>
#include <string.h>
#include <nrfx_cracen.h>
#include "log.h"
#define LOG_ERR


/* Extern in nrf_sdh.c */
void sdh_soc_rand_seed(uint32_t evt, void *ctx)
{
	uint32_t nrf_err;
	uint8_t seed[SD_RAND_SEED_SIZE];

	if (evt != NRF_EVT_RAND_SEED_REQUEST) {
		/* Not our business */
		return;
	}


	/* Selected when we don't have CRACEN Crypto HW available, like for nRF54LS05B
	 * In this case the cracen_psa api isn't available and we should use nrfx api
	 */
	int err = nrfx_cracen_entropy_get(seed, sizeof(seed));

	if (err) {
		LOG_ERR("Failed to generate true random number, err %d", err);
		return;
	}


	nrf_err = sd_rand_seed_set(seed);

	/* Discard seed immediately */
	memset(seed, 0, sizeof(seed));

	if (nrf_err != NRF_SUCCESS) {
		LOG_ERR("Failed to seed SoftDevice RNG, nrf_error %#x", nrf_err);
		return;
	}

	LOG_INF("SoftDevice RNG seeded");
}


NRF_SDH_SOC_OBSERVER(rand_seed, sdh_soc_rand_seed, NULL,1);