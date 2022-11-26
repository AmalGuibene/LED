/**
  ******************************************************************************
  * @file    main.c
  * @author  Amal Guibene
  * @brief   GPIO Driver 
  * @version V1.0.0
  * @date    26-11-2022
  *****************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "GPIO.h"
#include "led.h"
/* Private function prototypes -----------------------------------------------*/

/* Macros --------------------------------------------------------------------*/

/* Private functions ---------------------------------------------------------*/


/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main()
{

  ButtonToggleLed();
  InputOutputConfig();

  while(1)
  {
      GPIO_Write_Pin(GPIOD, PIN13, SET);   //led blue Active
  }
  
}

/**************************************END OF FILE**************************************/
