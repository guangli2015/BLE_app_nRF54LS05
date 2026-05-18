/*
 * Copyright (c) 2024 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/** @file
 *
 * @defgroup nrf_sdh_ble BLE support in SoftDevice Handler
 * @{
 * @ingroup  nrf_sdh
 * @brief    Declarations of types and functions required for BLE stack support.
 */

#ifndef NRF_SDH_BLE_H__
#define NRF_SDH_BLE_H__

#include <stdint.h>
#include <ble.h>
#include "nrf_section_iter.h"

#ifdef __cplusplus
extern "C" {
#endif
#define CONFIG_NRF_SDH_BLE_TOTAL_LINK_COUNT 1
#define ARG_UNUSED(x) (void)(x)
/**
 * @brief Size of the buffer for a BLE event.
 */
#define NRF_SDH_BLE_EVT_BUF_SIZE BLE_EVT_LEN_MAX(CONFIG_NRF_SDH_BLE_GATT_MAX_MTU_SIZE)

/**
 * @brief BLE stack event handler.
 */
typedef void (*nrf_sdh_ble_evt_handler_t)(const ble_evt_t *ble_evt, void *context);

/**
 * @brief BLE event observer.
 */
typedef struct  
{
	/**
	 * @brief BLE event handler.
	 */
	nrf_sdh_ble_evt_handler_t handler;
	/**
	 * @brief A parameter to the event handler.
	 */
	void *context;
} const nrf_sdh_ble_evt_observer;

/**@brief   Macro for registering @ref nrf_sdh_soc_evt_observer_t. Modules that want to be
 *          notified about SoC events must register the handler using this macro.
 *
 * @details This macro places the observer in a section named "sdh_soc_observers".
 *
 * @param[in]   _name       Observer name.
 * @param[in]   _prio       Priority of the observer event handler.
 *                          The smaller the number, the higher the priority.
 * @param[in]   _handler    BLE event handler.
 * @param[in]   _context    Parameter to the event handler.
 * @hideinitializer
 */
#define NRF_SDH_BLE_OBSERVER(_name, _handler, _context, _prio)                                      \
NRF_SECTION_SET_ITEM_REGISTER(sdh_ble_observers, _prio, static nrf_sdh_ble_evt_observer _name) =  \
{                                                                                                   \
    .handler   = _handler,                                                                          \
    .context = _context                                                                           \
}


/**
 * @brief Enable the SoftDevice Bluetooth stack.
 *
 * @param[in] conn_cfg_tag Connection configuration tag.
 *
 * @retval 0 On success.
 */
int nrf_sdh_ble_enable(uint8_t conn_cfg_tag);

/**
 * @brief Stringify a SoftDevice Bluetooth LE event.
 *
 * If :option:`CONFIG_NRF_SDH_STR_TABLES` is enabled, returns the event name.
 * Otherwise, returns the supplied integer as a string.
 *
 * @param evt A @ref BLE_GAP_EVTS, @ref BLE_GATTS_EVTS, or @ref BLE_GATTC_EVTS enumeration value.
 * @return A statically allocated string containing the event name or numerical value.
 */
const char *nrf_sdh_ble_evt_to_str(uint32_t evt);

/**
 * @brief Get the SoftDevice RAM usage.
 *
 * The value is only valid after enabling Bluetooth LE with @ref nrf_sdh_ble_enable.
 *
 * @return SoftDevice RAM usage in bytes.
 */
uint32_t nrf_sdh_ble_sd_ram_usage_get(void);

/**
 * @brief Get the assigned index for a connection handle.
 *
 * The returned value can be used for indexing into arrays where each element is associated
 * with a specific connection. Connection handles should never directly be used for indexing arrays.
 *
 * @param[in] conn_handle Connection handle.
 *
 * @return An integer in the range from 0 to (CONFIG_NRF_SDH_BLE_TOTAL_LINK_COUNT - 1) if the
 *         connection handle has been assigned to an index, otherwise -1.
 */
int nrf_sdh_ble_idx_get(uint16_t conn_handle);

/**
 * @brief Get the connection handle for an assigned index.
 *
 * @param[in] idx Assigned index.
 *
 * @return The connection handle for the given index or @c BLE_CONN_HANDLE_INVALID if not found.
 */
uint16_t nrf_sdh_ble_conn_handle_get(int idx);

#ifdef __cplusplus
}
#endif

#endif /* NRF_SDH_BLE_H__ */

/** @} */
