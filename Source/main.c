/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------

File    : main.c
Purpose : Generic application start

*/



#include <hal/nrf_gpio.h>
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
/*********************************************************************
*
*       main()
*
*  Function description
*   Application entry point.
*/
int main(void) {
  int i;

  
    nrf_gpio_cfg_output(BOARD_PIN_LED_0);
  nrf_gpio_cfg_output(BOARD_PIN_LED_1);
  nrf_gpio_cfg_output(BOARD_PIN_LED_2);
  nrf_gpio_cfg_output(BOARD_PIN_LED_3);


  nrf_gpio_pin_write(BOARD_PIN_LED_0, 1);
  nrf_gpio_pin_write(BOARD_PIN_LED_1, 0);
  nrf_gpio_pin_write(BOARD_PIN_LED_3, 0);
  nrf_gpio_pin_write(BOARD_PIN_LED_2, 1);

}
void _start(void) {
main();
    
}
/*************************** End of file ****************************/
