#include <stddef.h>
#include "stm32l1xx.h"

void delay(uint32_t time)
{
	uint32_t i;
	for(i=0;i<time;i++)
	{
	}
}

int main(void)
{
	uint32_t button;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);

  GPIO_InitTypeDef gpioInitStruc;

  /* uloha 1a */
  gpioInitStruc.GPIO_Mode = GPIO_Mode_OUT;
  gpioInitStruc.GPIO_OType = GPIO_OType_PP;
  gpioInitStruc.GPIO_Pin = GPIO_Pin_5;
  gpioInitStruc.GPIO_Speed = GPIO_Speed_400KHz;

  GPIO_Init(GPIOA, &gpioInitStruc);

  /* uloha 1b */

  GPIO_SetBits(GPIOA, GPIO_Pin_5);    //zapnutie LED
  GPIO_ResetBits(GPIOA, GPIO_Pin_5);  //vypnutie LED
  GPIO_ToggleBits(GPIOA, GPIO_Pin_5);  //zmena stavu LED
  GPIO_ToggleBits(GPIOA, GPIO_Pin_5);
  GPIO_ToggleBits(GPIOA, GPIO_Pin_5);


  /* uloha 2a */
  gpioInitStruc.GPIO_Mode = GPIO_Mode_IN;
  gpioInitStruc.GPIO_Pin  = GPIO_Pin_13;
  gpioInitStruc.GPIO_PuPd = GPIO_PuPd_UP;
  gpioInitStruc.GPIO_Speed = GPIO_Speed_40MHz;

  GPIO_Init(GPIOC, &gpioInitStruc);


while (1)
  {
	button = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);  /* uloha 2b */

	/* uloha 3a */

	GPIO_SetBits(GPIOA, GPIO_Pin_5);
	delay(1000000);
	GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	delay(1000000);

	/* uloha 3b */

	if(button == 0)
	  {
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
	  }
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	}

	/* uloha 3c */
	 if((button == 0) )
	 {
		 delay(150000);
	 }
	 if((button == 0) )
	 {
		 GPIO_ToggleBits(GPIOA, GPIO_Pin_5);
	 }
  }
  return 0;
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
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

/*
 * Minimal __assert_func used by the assert() macro
 * */
void __assert_func(const char *file, int line, const char *func, const char *failedexpr)
{
  while(1)
  {}
}

/*
 * Minimal __assert() uses __assert__func()
 * */
void __assert(const char *file, int line, const char *failedexpr)
{
   __assert_func (file, line, NULL, failedexpr);
}
