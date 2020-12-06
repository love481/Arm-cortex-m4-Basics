#include"stm32f4xx_hal.h"
void ms_delay(uint32_t tim)
{ for(uint32_t i=0;i<tim*4000;i++);
}
void gpio_init()
{GPIO_InitTypeDef GPIO_InitStruct = {0};
 __HAL_RCC_SYSCFG_CLK_ENABLE();
  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();

__HAL_RCC_GPIOA_CLK_ENABLE();
 /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3|GPIO_PIN_5, GPIO_PIN_RESET);
/*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3|GPIO_PIN_5, GPIO_PIN_RESET);
/*Configure GPIO pins : PE3 PE5 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  GPIO_InitStruct.Pin=GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull=GPIO_PULLUP;
   HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
int main()
{

gpio_init();
while(1){

	  HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_3 );
    ms_delay(1000);
}
}
