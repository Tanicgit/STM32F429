/**
  ******************************************************************************
  * @file    Template/main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    20-September-2013
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f429i_discovery.h"
#include "stm32f429i_discovery_i2c_ee.h"
#include "stm32f429i_discovery_ioe.h"
#include "stm32f429i_discovery_l3gd20.h"
#include "stm32f429i_discovery_lcd.h"

#include "FreeRTOS.h"
#include "task.h"
/** @addtogroup Template
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
L3GD20_InitTypeDef L3gd20;
extern void freeRtosInit(void);
/**
  * @brief   Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       files (startup_stm32f429_439xx.s) before to branch to application main. 
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f4xx.c file
     */  
  
  /* Add your application code here */
    STM_EVAL_LEDInit(LED3);
		STM_EVAL_LEDInit(LED4);
		STM_EVAL_PBInit(BUTTON_USER,BUTTON_MODE_GPIO);
		sEE_Init();
		IOE_Config();
		IOE_TPITConfig();
	//	L3GD20_Init(&L3gd20);
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CRC, ENABLE);
	//	SDRAM_Init();
		LCD_Init();
		LCD_LayerInit();
		LCD_SetLayer(LCD_BACKGROUND_LAYER);
		LTDC_Cmd(ENABLE);
		
		freeRtosInit();
		vTaskStartScheduler();
  /* Infinite loop */
  while (1)
  {
		
  }
}


__weak uint32_t sEE_TIMEOUT_UserCallback(void)
{
	return 0;
}
__weak uint32_t L3GD20_TIMEOUT_UserCallback(void)
{
	return 0;
}


void vApplicationIdleHook()
{

}

void vApplicationStackOverflowHook()
{

}

void vApplicationTickHook()
{

}

void vApplicationMallocFailedHook()
{

}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
