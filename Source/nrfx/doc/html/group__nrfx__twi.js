var group__nrfx__twi =
[
    [ "TWI peripheral driver configuration", "group__nrfx__twi__config.html", "group__nrfx__twi__config" ],
    [ "nrfx_twi_xfer_desc_t", "structnrfx__twi__xfer__desc__t.html", [
      [ "address", "structnrfx__twi__xfer__desc__t.html#a8325a3d43f54f0ed6c7d210840e1c10f", null ],
      [ "p_primary_buf", "structnrfx__twi__xfer__desc__t.html#acf64e125d6f0e6a0f417a6e2751c0149", null ],
      [ "p_secondary_buf", "structnrfx__twi__xfer__desc__t.html#a64eb4755832509030aa241655dc9d438", null ],
      [ "primary_length", "structnrfx__twi__xfer__desc__t.html#acf0f8fdc02260d5ec902c83c4340436d", null ],
      [ "secondary_length", "structnrfx__twi__xfer__desc__t.html#aaf2ce5a6ac5e85532ba5c74fe12c6369", null ],
      [ "type", "structnrfx__twi__xfer__desc__t.html#a3959af41675fdabe42c9207ce0bc6963", null ]
    ] ],
    [ "nrfx_twi_event_t", "structnrfx__twi__event__t.html", [
      [ "type", "structnrfx__twi__event__t.html#aac8ce98fe05ec5556d85f8ddeaabbe2f", null ],
      [ "xfer_desc", "structnrfx__twi__event__t.html#a00d9fdc36fedea37f2d43315ec92416f", null ]
    ] ],
    [ "nrfx_twi_t", "structnrfx__twi__t.html", [
      [ "cb", "structnrfx__twi__t.html#a733bf3e11e553f35df0421d84cc56da6", null ],
      [ "p_reg", "structnrfx__twi__t.html#ad0ce885c1bd3b2cddaaaf55fe7397414", null ]
    ] ],
    [ "nrfx_twi_config_t", "structnrfx__twi__config__t.html", [
      [ "frequency", "structnrfx__twi__config__t.html#aba041b6237dd90e202d91ee34914e030", null ],
      [ "hold_bus_uninit", "structnrfx__twi__config__t.html#ab9a46a34d1b00a2c98aead56c43975c4", null ],
      [ "interrupt_priority", "structnrfx__twi__config__t.html#ad695ba152dcc3c8adb2cf476fcdb89ea", null ],
      [ "scl", "structnrfx__twi__config__t.html#aefb260d2f5cdb0d93d685faa82e04902", null ],
      [ "sda", "structnrfx__twi__config__t.html#a1674b720ed81a9185c12d5e1327ac33a", null ],
      [ "skip_gpio_cfg", "structnrfx__twi__config__t.html#a9220e4bc44f74979567b885e46dd9cab", null ],
      [ "skip_psel_cfg", "structnrfx__twi__config__t.html#a00e28f92c2b696c42080ecc62b01572f", null ]
    ] ],
    [ "NRFX_TWI_DEFAULT_CONFIG", "group__nrfx__twi.html#ga06897416b475f64c397f6ac2aa0cd51b", null ],
    [ "NRFX_TWI_FLAG_NO_XFER_EVT_HANDLER", "group__nrfx__twi.html#gaff494666514193a68dbb7b43b4da256d", null ],
    [ "NRFX_TWI_FLAG_SUSPEND", "group__nrfx__twi.html#ga5684cab698a35c770a78854e348c2408", null ],
    [ "NRFX_TWI_FLAG_TX_NO_STOP", "group__nrfx__twi.html#ga3c919cd69c51f64039324fda37da1a29", null ],
    [ "NRFX_TWI_INST_HANDLER_GET", "group__nrfx__twi.html#ga4b21ab166f6bbf178c291c00bdecc16b", null ],
    [ "NRFX_TWI_INSTANCE", "group__nrfx__twi.html#ga72bc7ecc93fe6cac8409642da1e25fce", null ],
    [ "NRFX_TWI_XFER_DESC_RX", "group__nrfx__twi.html#ga9496c7354553841d40495f025f626dcf", null ],
    [ "NRFX_TWI_XFER_DESC_TX", "group__nrfx__twi.html#gaa9406d59abbc1f914a47edcb573ef683", null ],
    [ "NRFX_TWI_XFER_DESC_TXRX", "group__nrfx__twi.html#ga55f782b6a418104c143b4aafb2648e4a", null ],
    [ "NRFX_TWI_XFER_DESC_TXTX", "group__nrfx__twi.html#gae5c32acc87146cdd3de969ad60085e08", null ],
    [ "nrfx_twi_event_handler_t", "group__nrfx__twi.html#ga4a5856fcc74ac329ae6f8c565fbdc781", null ],
    [ "nrfx_twi_event_type_t", "group__nrfx__twi.html#ga59df8dc09ea6b976f8112ef264e8c1a6", [
      [ "NRFX_TWI_EVT_DONE", "group__nrfx__twi.html#gga59df8dc09ea6b976f8112ef264e8c1a6a6f50db79773a3ca43f8d78c4a7064510", null ],
      [ "NRFX_TWI_EVT_ADDRESS_NACK", "group__nrfx__twi.html#gga59df8dc09ea6b976f8112ef264e8c1a6a3ab204968c724cc0467715bdcd1f152c", null ],
      [ "NRFX_TWI_EVT_DATA_NACK", "group__nrfx__twi.html#gga59df8dc09ea6b976f8112ef264e8c1a6a4fa4f698d6c60e5a032f953ff2be61d2", null ],
      [ "NRFX_TWI_EVT_OVERRUN", "group__nrfx__twi.html#gga59df8dc09ea6b976f8112ef264e8c1a6a219f33b07b265bf3b2fc3a19043774d9", null ],
      [ "NRFX_TWI_EVT_BUS_ERROR", "group__nrfx__twi.html#gga59df8dc09ea6b976f8112ef264e8c1a6a47b8c8e31248fe102b0166f9afcb5de0", null ]
    ] ],
    [ "nrfx_twi_xfer_type_t", "group__nrfx__twi.html#gaf227c5ab481c56715097ba08a0ae2bac", [
      [ "NRFX_TWI_XFER_TX", "group__nrfx__twi.html#ggaf227c5ab481c56715097ba08a0ae2baca212037ca48f014677c8d9efd647fd72a", null ],
      [ "NRFX_TWI_XFER_RX", "group__nrfx__twi.html#ggaf227c5ab481c56715097ba08a0ae2bacac11390a9257b1036b10cd77eaee53e2a", null ],
      [ "NRFX_TWI_XFER_TXRX", "group__nrfx__twi.html#ggaf227c5ab481c56715097ba08a0ae2baca8339203b38c17da2f0793f02661b0e83", null ],
      [ "NRFX_TWI_XFER_TXTX", "group__nrfx__twi.html#ggaf227c5ab481c56715097ba08a0ae2baca81c31707f88003a02ccc7fcd7beb0e1c", null ]
    ] ],
    [ "nrfx_twi_bus_recover", "group__nrfx__twi.html#ga94460d960bcfd297a2b22d82aaf9d8c3", null ],
    [ "nrfx_twi_data_count_get", "group__nrfx__twi.html#gae8fb5691723bce5cce250e78aa9c14aa", null ],
    [ "nrfx_twi_disable", "group__nrfx__twi.html#gafba57eb00d011fdfe6d0c7e4f758d9c2", null ],
    [ "nrfx_twi_enable", "group__nrfx__twi.html#gabda5db5121a0b1807da746e2a8b909ae", null ],
    [ "nrfx_twi_init", "group__nrfx__twi.html#gaaa96fc1da44267a7a62202ccde44ae06", null ],
    [ "nrfx_twi_init_check", "group__nrfx__twi.html#ga74f9c2116576ef7e29d2bc6a08d53643", null ],
    [ "nrfx_twi_irq_handler", "group__nrfx__twi.html#ga2f31a628a4bb00eaeb30ad63716499f4", null ],
    [ "nrfx_twi_is_busy", "group__nrfx__twi.html#ga7ad4c5f8afa8fc13a02a0a67a024c67e", null ],
    [ "nrfx_twi_reconfigure", "group__nrfx__twi.html#ga3957fcbc3a2fcc471202dbfd68f5cc9e", null ],
    [ "nrfx_twi_stopped_event_get", "group__nrfx__twi.html#ga7e850f6480a6d7ff7cd430da75679922", null ],
    [ "nrfx_twi_uninit", "group__nrfx__twi.html#ga9c8e1c3b502f639a93107c51944c6d29", null ],
    [ "nrfx_twi_xfer", "group__nrfx__twi.html#gaa5924a8a9d9dfb95ff13304f9c3c0d8d", null ]
];