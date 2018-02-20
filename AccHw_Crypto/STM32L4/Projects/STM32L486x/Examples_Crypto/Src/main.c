/**
  ******************************************************************************
  * @file    Examples_Crypto/Src/main.c
  * @author  MCD Application Team
  * @version V3.1.0
  * @date    30-October-2015
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
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

/** @addtogroup Examples_Crypto
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t Example_Status = 0;

/* Private function prototypes -----------------------------------------------*/
TestStatus Buffercmp(const uint8_t* pBuffer,
                     uint8_t* pBuffer1,
                     uint16_t BufferLength);
static void SystemClock_Config(void);
static void Error_Handler(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{

  /* STM32L4xx HAL library initialization:
       - Configure the Flash prefetch
       - Systick timer is configured by default as source of time base, but user 
         can eventually implement his proper time base source (a general purpose 
         timer for example or other time source), keeping in mind that Time base 
         duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and 
         handled in milliseconds basis.
       - Set NVIC Group Priority to 4
       - Low Level Initialization
     */

  HAL_Init();

  /* Configure the system clock to 64 MHz */
  SystemClock_Config();

  /* Enable CRC clock */
  __CRC_CLK_ENABLE();



#ifdef Example_AES128bitsCFB
  Example_Status = ExampleAES128bitsCFB();
  if (Example_Status == PASSED)
  {
    /* User may add application traitment in case of AES CFB encryption and decryption is passed */
  }
  else
  {
    Error_Handler();
  }
#endif

#ifdef Example_AES128bitsCCM
  Example_Status = ExampleAES128bitsCCM();
  if (Example_Status == PASSED)
  {
    /* User may add application traitment in case of AES CCM encryption and decryption is passed */
  }
  else
  {
    Error_Handler();
  }
#endif

#ifdef Example_AES128bitsOFB
  Example_Status = ExampleAES128bitsOFB();
  if (Example_Status == PASSED)
  {
    /* User may add application traitment in case of AES OFB encryption and decryption is passed */
  }
  else
  {
    Error_Handler();
  }
#endif

#ifdef Example_AES128bitsKEYWRAP
  Example_Status = ExampleAES128bitsKEYWRAP();
  if (Example_Status == PASSED)
  {
    /* User may add application traitment in case of AES KEYWRAP encryption and decryption is passed */
  }
  else
  {
    Error_Handler();
  }
#endif

#ifdef Example_AES256bitsXTS
  Example_Status = ExampleAES256bitsXTS();
  if (Example_Status == PASSED)
  {
    /* User may add application traitment in case of AES XTS encryption and decryption is passed */
  }
  else
  {
    Error_Handler();
  }
#endif

#ifdef Example_POLY1305GetMACVerifMAC
  Example_Status = ExamplePOLY1305GetMACVerifMAC();
  if (Example_Status == PASSED)
  {
    /* User may add application traitment in case of POLY1305 get and verify MAC is passed */
  }
  else
  {
    Error_Handler();
  }
#endif

#ifdef Example_ECCKeyGenSignVerif
  Example_Status = ExampleECCKeyGenSignVerif();
  if (Example_Status == PASSED)
  {
    /* User may add application traitment in case of ECC key generation, signature and verification is passed */
  }
  else
  {
    Error_Handler();
  }
#endif

#ifdef Example_ECCSignVerif
  Example_Status = ExampleECCSignVerif();
  if (Example_Status == PASSED)
  {
    /* User may add application traitment in case of ECC signature and verification encryption is passed */
  }
  else
  {
    Error_Handler();
  }
#endif

#ifdef Example_RSAEncDec
  Example_Status = ExampleRSAEncDec();
  if (Example_Status == PASSED)
  {
    /* User may add application traitment in case of RSA encryption and decryption encryption is passed */
  }
  else
  {
    Error_Handler();
  }
#endif

  /* Infinite loop */
  while (1)
  {}
}

/**
  * @brief  Compares two buffers.
  * @param  pBuffer, pBuffer1: buffers to be compared.
  * @param  BufferLength: buffer's length
  * @retval PASSED: pBuffer identical to pBuffer1
  *         FAILED: pBuffer differs from pBuffer1
  */
TestStatus Buffercmp(const uint8_t* pBuffer, uint8_t* pBuffer1, uint16_t BufferLength)
{
  while (BufferLength--)
  {
    if (*pBuffer != *pBuffer1)
    {
      return FAILED;
    }

    pBuffer++;
    pBuffer1++;
  }

  return PASSED;
}
/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follows :
  *            System Clock source            = PLL (MSI)
  *            SYSCLK(Hz)                     = 80000000
  *            HCLK(Hz)                       = 80000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 1
  *            APB2 Prescaler                 = 1
  *            MSI Frequency(Hz)              = 4000000
  *            PLL_M                          = 1
  *            PLL_N                          = 40
  *            PLL_R                          = 2
  *            PLL_P                          = 7
  *            PLL_Q                          = 4
  *            Flash Latency(WS)              = 4
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};

  /* MSI is enabled after System reset, activate PLL with MSI as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLP = 7;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    /* Initialization Error */
    while (1);
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    /* Initialization Error */
    while (1);
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RNG;
  PeriphClkInitStruct.RngClockSelection = RCC_RNGCLKSOURCE_PLL;
  HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);
}


/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* User may add here some code to deal with this error */
  while (1)
  {}
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
  {}
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/