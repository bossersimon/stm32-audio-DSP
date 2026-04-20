
#ifndef __AUDIO_H
#define __AUDIO_H

#include <stdint.h>

/* CS43L22 interface: I2S, Philips standard, 16-bit data */
#define CODEC_STANDARD 0x04U


typedef struct
{
  uint32_t (*Init)(uint16_t, uint16_t, uint8_t, uint32_t);
  void     (*DeInit)(void);
  uint32_t (*ReadID)(uint16_t);

  uint32_t (*Play)(uint16_t, uint16_t*, uint16_t);
  uint32_t (*Pause)(uint16_t);
  uint32_t (*Resume)(uint16_t);
  uint32_t (*Stop)(uint16_t, uint32_t);

  uint32_t (*SetFrequency)(uint16_t, uint32_t);
  uint32_t (*SetVolume)(uint16_t, uint8_t);
  uint32_t (*SetMute)(uint16_t, uint32_t);
  uint32_t (*SetOutputMode)(uint16_t, uint8_t);
  uint32_t (*Reset)(uint16_t);

} AUDIO_DrvTypeDef;

void      AUDIO_IO_Init(void);
void      AUDIO_IO_DeInit(void);
void      AUDIO_IO_Write(uint8_t Addr, uint8_t Reg, uint8_t Value);
uint8_t   AUDIO_IO_Read(uint8_t Addr, uint8_t Reg);

#endif
