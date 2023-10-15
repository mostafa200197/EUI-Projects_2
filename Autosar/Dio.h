/*
 * GPIO_A.h
 *
 *  Created on: Oct 14, 2023
 *      Author: DELL G5
 */

#include "stdint.h"

typedef uint8_t Dio_ChannelType;
typedef uint8_t  Dio_LevelType;

typedef uint8_t Dio_PortLevelType;
typedef uint8_t Dio_PortType;





#define STD_LOW 0
#define STD_HIGH 1


void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level);
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);
void Dio_WritePort (Dio_PortType PortId,Dio_PortLevelType Level);




