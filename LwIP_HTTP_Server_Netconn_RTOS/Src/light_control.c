
#include "light_control.h"


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
	
	short DATA_allume[8] = { 0,0,0,0,1,0,0,0 };
	short DATA_eteindre[8] = { 0,0,1,0,1,0,0,0 };
	
	mPort_Initialize();
	
	while(1){
		
		osDelay(250);
	}
}

 void sendZero(void)
 {
	 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
	 HAL_Delay(22); //550us
	 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
	 HAL_Delay(23);//575us
 }
 
 void sendOne(void)
 {
	 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
	 HAL_Delay(45); //9 ms
	 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
	 HAL_Delay(45);//4.5ms zob
 }

	void initMessage(void)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
		HAL_Delay(360); //9 ms
		
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
		
		HAL_Delay(180);//4.5ms zob
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
			HAL_Delay(220);
	}
	
	
}

