
#include "light_control.h"
#include "tm_stm32_delay.h"
/* GLOBAL variables ---------------------------------------------------------*/
#include "VAR.h"


static void initMessage(void);
static void sendZero(void);
static void sendOne(void);
static void	mPort_Initialize(void);


void	mPort_Initialize(void){
  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /* Configure GPIO pin: PI1 (LD1) */
  GPIO_InitStruct.Pin   = GPIO_PIN_9;
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
}

void thread_control(void const * argument){
	short ADD[8] = { 0,1,1,0,0,1,0,0};
	short DATA_allume[8] = { 0,0,0,0,1,0,0,0 };
	short DATA_eteindre[8] = { 0,0,1,0,1,0,0,0 };
	
	mPort_Initialize();
	TM_DELAY_Init();
	
	 HAL_Delay(6); //ms
 
 while (1)
 {
//	BSP_TS_GetState(state);
//	 
//		if (state->touchDetected !=0)
//		{
//			if(state->touchX[0] < ((uint16_t)0xf0))
//			{
//				BSP_TS_ResetTouchData(state);
//				send_Message_Bin(ADD,DATA_allume);
//			}
//			else
//			{
//				BSP_TS_ResetTouchData(state);
//				send_Message_Bin(ADD,DATA_eteindre);
//			}
//		}
	 if( OnActive==1){
		 send_Message_Bin(ADD,DATA_allume);
		 OnActive = 0;
	 }
	 if( OffActive==1){
		 send_Message_Bin(ADD,DATA_eteindre);
		 OffActive = 0;
	 }
		HAL_Delay(6);
	  osDelay(5);
 }

}

 void sendZero(void)
 {
	 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
	 //HAL_Delay(22); //550us
	 Delay(550);
	 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
	 Delay(575);
	 //HAL_Delay(23);//575us
 }
 
 void sendOne(void)
 {
	 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
	 Delay(1125);
	 //HAL_Delay(45); 
	 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
	 Delay(1125);
	 //HAL_Delay(45);
 }

	void initMessage(void)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
		//HAL_Delay(360); //9 ms
		Delay(9000);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
		Delay(4500);
		//HAL_Delay(180);//4.5ms zob
	}	


void send_Message_Bin(short add[8], short data[8]) {
	short i;
	short j;
	
	initMessage(); 
	for(j=0;j<6;j++)
	{
		for(i=0; i<8; i++){
			if(add[i]==1){
				sendOne();
			}else{
				sendZero();
			}
		}
			
		for(i=0; i<8; i++){
			if(add[i]==1){
				sendZero();
			}else{
				sendOne();
			}	
		}
		
		for(i=0; i<8; i++){
			if(data[i]==1){
				sendOne();
			}else{
				sendZero();
			}
		}
		
			for(i=0; i<8; i++){
			if(data[i]==1){
				sendZero();
			}else{
				sendOne();
			}	
		}
			sendOne();
			//HAL_Delay(220);
		Delay(5500);
	}
	
	
}

