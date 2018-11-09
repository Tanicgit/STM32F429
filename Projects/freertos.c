
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

#include "GUI.h"
BaseType_t xReturned1;
TaskHandle_t xHandle1 = NULL;
BaseType_t xReturned2;
TaskHandle_t xHandle2 = NULL;

//uint8_t testbuf[1024*1024]__attribute__((section("SD_RAM")));
void vTaskCode1( void * pvParameters )
{

	GUI_Init();
	GUI_SetBkColor(GUI_BLUE);
	GUI_SetColor(GUI_WHITE);
	GUI_Clear();
	
	GUI_SetFont(&GUI_Font32_1);
	//GUI_DispStringAt("Hello world!", (LCD_GetXSize()-150)/2, (LCD_GetYSize()-20)/2);
	//GUI_SetPenSize(3);
	GUI_DrawLine(10,10,10,100);
	GUI_DrawLine(10,10,100,100);
	vTaskDelay(100);

	for( ;; )
	{
		vTaskDelay(500);
		STM_EVAL_LEDToggle(LED3);

	}
}


void vTaskCode2( void * pvParameters )
{

//	LCD_SetTextColor(0);
//	LCD_SetBackColor(0xffff);
//	LCD_Clear(0xffff);
//	
//	LCD_DrawRect(50,50,100,100);
//	
//	LCD_DisplayChar(0,0,'h');
//	
//	drawHLine(0,0,50,0x1f00);
	for( ;; )
	{  
		vTaskDelay(200);
		STM_EVAL_LEDToggle(LED4);
	}
}

void freeRtosInit()
{
    xReturned1 = xTaskCreate(vTaskCode1, "TASK1",128, ( void * ) 1,2,&xHandle1 );     

		xReturned2 = xTaskCreate(vTaskCode2, "TASK2",128, ( void * ) 1,3,&xHandle2 );  	
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

