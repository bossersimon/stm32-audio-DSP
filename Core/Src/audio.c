

#include "audio.h"
#include "main.h"
#include "stm32f407xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_i2c.h"

extern I2C_HandleTypeDef hi2c1;

void AUDIO_IO_Init(void) {
    HAL_GPIO_WritePin(GPIOD, DAC_RESET_Pin, GPIO_PIN_RESET);
    HAL_Delay(5);
    HAL_GPIO_WritePin(GPIOD, DAC_RESET_Pin, GPIO_PIN_SET);
    HAL_Delay(5);  
}

void AUDIO_IO_DeInit(void) {
    HAL_GPIO_WritePin(GPIOD, DAC_RESET_Pin, GPIO_PIN_RESET);
    HAL_I2C_DeInit(&hi2c1);
}

void AUDIO_IO_Write(uint8_t Addr, uint8_t Reg, uint8_t Value) {
     HAL_I2C_Mem_Write(&hi2c1,
                      Addr,
                      Reg,
                      I2C_MEMADD_SIZE_8BIT,
                      &Value,
                      1,
                      100);
}

uint8_t AUDIO_IO_Read(uint8_t Addr, uint8_t Reg) {
    uint8_t value = 0;

    HAL_I2C_Mem_Read(&hi2c1,
                     Addr,
                     Reg,
                     I2C_MEMADD_SIZE_8BIT,
                     &value,
                     1,
                     100);

    return value;
}
