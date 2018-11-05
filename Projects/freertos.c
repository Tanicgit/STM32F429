
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

#include "main.h"
#include "stm32f429i_discovery.h"
#include "stm32f429i_discovery_i2c_ee.h"
#include "stm32f429i_discovery_ioe.h"
#include "stm32f429i_discovery_l3gd20.h"
#include "stm32f429i_discovery_lcd.h"

BaseType_t xReturned1;
TaskHandle_t xHandle1 = NULL;
BaseType_t xReturned2;
TaskHandle_t xHandle2 = NULL;

void vTaskCode1( void * pvParameters )
{
	configASSERT( ( ( uint32_t ) pvParameters ) == 1 );

	for( ;; )
	{
		vTaskDelay(500);
		STM_EVAL_LEDToggle(LED3);

	}
}

void vTaskCode2( void * pvParameters )
{
	configASSERT( ( ( uint32_t ) pvParameters ) == 1 );
	LCD_SetTextColor(0);
	LCD_SetBackColor(0xffff);
	LCD_Clear(0xffff);
	
	LCD_DrawRect(50,50,100,100);
	for( ;; )
	{  
		vTaskDelay(200);
		STM_EVAL_LEDToggle(LED4);
	}
}

void freeRtosInit()
{
    xReturned1 = xTaskCreate(vTaskCode1, "TASK1",128, ( void * ) 1,tskIDLE_PRIORITY,&xHandle1 );     

		xReturned2 = xTaskCreate(vTaskCode2, "TASK2",128, ( void * ) 1,tskIDLE_PRIORITY,&xHandle2 );  	
}





///* Function that creates a task. */
//void vOtherFunction( void )
//{


//    /* Create the task, storing the handle. */


//    if( xReturned == pdPASS )
//    {
//        /* The task was created.  Use the task's handle to delete the task. */
//        vTaskDelete( xHandle );
//    }
//}

