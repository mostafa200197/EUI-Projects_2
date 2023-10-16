/******************************************************************************/
/*                                                                            */
/* !Layer           : Hardware Abstraction Layer (HAL)                        */
/*                                                                            */
/* !Module          : LCD                                                     */
/* !Description     : LCD implementation                                      */
/*                                                                            */
/* !File            : LCD.c                                                   */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Robot Car @EME - EUI                                    */
/*                                                                            */
/* !Target          : TIVA-C TM4C123GH6PM                                     */
/*                                                                            */
/* !Compiler        : Code Composer Studio 8.3.1                              */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/*                                                                            */
/* !Designed by     : Ahmed ABDULAZEEM                    !Date : SEP 9, 2023 */
/* !Coded by        : Ahmed ABDULAZEEM                    !Date : SEP 9, 2023 */
/*                                                                            */
/* Ver 1.0    SEP 13, 2023     Initial release                                */
/******************************************************************************/

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/

#include <HAL/LCD/LCD.h>

/*! Include the module header file                                            */

/******************************************************************************/
/******************************** GLOBAL VARIABLES ****************************/
/******************************************************************************/

/*This global variable is used To automatic reach the second line when the first line is full*/
uint8_t g_u8counter;

/******************************************************************************/
/*! \Description : Initialize the LCD Module and GPIO Pins used in LCD        */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void LCD_vidInit(void)
{
    /*SET THE CONFIGRATION FOR THE GPIO PINS THAN WILL BE CONNECTED TO THE LCD*/
    Enable_Peripheral_Clock(GPIOB_CLOCK_OFFSET);

    GPIO_InitTypeDef LCD_GPIOInit = { 0U };
    LCD_GPIOInit.Pin = LCD_D0 | LCD_D1 | LCD_D2 | LCD_D3 | LCD_EN | LCD_RS;
    LCD_GPIOInit.Mode = Output;
    LCD_GPIOInit.Pull = FLOATING;
    GPIO_Init(GPIOB, &LCD_GPIOInit);

    GPIO_Write_Pins(GPIOB, ALL_GPIO_PINS, Low);

    Delay_ms(40U);

    LCD_vidSendNibbleCMD(0x2U); /*2 Line, 5*7 matrix in 4-bit mode*/
    LCD_vidSendNibbleCMD(0x2U);
    LCD_vidSendNibbleCMD(0x8U);

    LCD_vidSendNibbleCMD(0x0U); /*Display on cursor off*/
    LCD_vidSendNibbleCMD(0xCU | 0xAU | 0x9U); /*Increment cursor */

    LCD_vidSendNibbleCMD(0x0U);
    LCD_vidSendNibbleCMD(0x6U);

    LCD_vidSendNibbleCMD(0x0U);/*clear the lcd*/
    LCD_vidSendNibbleCMD(0x1U);
}

/******************************************************************************/
/*! \Description :  send nibble in the command mode                           */
/*! \return      None                                                         */
/*! \arguments   uint8_t Copy_u8NibbleCopy                                    */
/******************************************************************************/

void LCD_vidSendNibbleCMD(uint8_t Copy_u8NibbleCopy)
{

    /*clear the RS pin and set the EN pin to enter command mode*/
    GPIO_Write(LCD_CONTROL_PORT_REG, LCD_RS, Low);
    GPIO_Write(LCD_CONTROL_PORT_REG, LCD_EN, High);

    /*send the nibble to the LCD through data pins*/
    GPIO_Write_Pins(LCD_DATA_PORT_REG, LCD_D0 | LCD_D1 | LCD_D2 | LCD_D3,
                    Copy_u8NibbleCopy);

    Delay_ms(1U);

    GPIO_Write(LCD_CONTROL_PORT_REG, LCD_EN, Low);
    Delay_ms(2U);
    GPIO_Write_Pins(GPIOB, ALL_GPIO_PINS, 0U);
}

/******************************************************************************/
/*! \Description :  send nibble in the data mode                              */
/*! \return      None                                                         */
/*! \arguments   uint8_t Copy_u8NibbleCopy                                    */
/******************************************************************************/
void LCD_vidSendNibbleData(uint8_t Copy_u8NibbleCopy)
{

    /*clear the RS pin and set the EN pin to enter command mode*/

    GPIO_Write(LCD_CONTROL_PORT_REG, LCD_RS, High);
    GPIO_Write(LCD_CONTROL_PORT_REG, LCD_EN, High);

    /*send the nibble to the LCD through data pins*/
    GPIO_Write_Pins(LCD_DATA_PORT_REG, LCD_D0 | LCD_D1 | LCD_D2 | LCD_D3,
                    Copy_u8NibbleCopy);

    Delay_ms(1U);

    GPIO_Write(LCD_CONTROL_PORT_REG, LCD_EN, Low);

}

/******************************************************************************/
/*! \Description :  write a character in the LCD                              */
/*! \return         None                                                      */
/*! \arguments      uint8_t Copy_u8DataCopy                                   */
/******************************************************************************/
void LCD_vidWriteChar(uint8_t Copy_u8DataCopy)
{
    /*store the last 4 bits of the character*/
    uint8_t upper = Copy_u8DataCopy >> 4U;
    /*send the last 4bits*/
    LCD_vidSendNibbleData(upper);
    /*send the first 4bits*/

    LCD_vidSendNibbleData(Copy_u8DataCopy);
    g_u8counter++;

}

/******************************************************************************/
/*! \Description :  write string on the LCD                                   */
/*! \return         None                                                      */
/*! \arguments      uint8_t* Copy_ptr_u8StringCopy                            */
/******************************************************************************/

void LCD_vidWriteString(uint8_t *Copy_ptr_u8StringCopy)
{
    uint8_t i;
    /*loop into string till reach null*/
    for (i = 0U; Copy_ptr_u8StringCopy[i] != '\0'; i++)
    {
        /*print the each single character individually*/
        LCD_vidWriteChar(Copy_ptr_u8StringCopy[i]);
    }
}

/******************************************************************************/
/*! \Description :  move the lcd cursor to certain position                   */
/*! \return         None                                                      */
/*! \arguments      uint8_t Copy_u8column , uint8_t Copy_u8row                */
/******************************************************************************/
void LCD_vidMoveCursor(uint8_t Copy_u8column, uint8_t Copy_u8row)
{

    /*initialize a variable to store the position*/
    uint8_t Copy_u8positon;
    /*check if the column is the first column*/
    if (Copy_u8column == 0U)
    {
        /*add the row number to the address of the first row in the first column*/
        Copy_u8positon = 0x80U + Copy_u8row;
        /*check if the column is the second column*/
    }
    else if (Copy_u8column == 1U)
    {
        /*add the row number to the address of the first row in the second column*/
        Copy_u8positon = Copy_u8row + 0xC0U;
    }
    else
    {
        /* Do Nothing */
    }
    /*send the position of the cursor*/
    LCD_vidSendNibbleCMD(Copy_u8positon >> 4U);
    LCD_vidSendNibbleCMD(Copy_u8positon);
    Delay_ms(5U);

}

/******************************************************************************/
/*! \Description :  clear the lcd                                             */
/*! \return         None                                                      */
/*! \arguments      None                                                      */
/******************************************************************************/
void LCD_vidClearScreen(void)
{
    LCD_vidSendNibbleCMD(0x0U);
    LCD_vidSendNibbleCMD(0x1U);
    g_u8counter = 0U;
}

/******************************************************************************/
/*! \Description :  write number on  the LCD                                  */
/*! \return         None                                                      */
/*! \arguments      uint16_t Copy_u16num                                      */
/******************************************************************************/
void LCD_vidWriteNumber(uint16_t Copy_u16num)
{

    uint8_t arr[5U] = { 0U };
    uint8_t Local_u8iterator = 5U;
    if (Copy_u16num & 0x8000U)
    {
        Copy_u16num = ((~Copy_u16num) + 1U);
        LCD_vidWriteChar('-');
    }
    if (Copy_u16num == 0U)
    {
        LCD_vidWriteChar('0');
    }
    else
    {
        while (Copy_u16num != 0U)
        {
            Local_u8iterator--;
            arr[Local_u8iterator] = (uint8_t)Copy_u16num % 10U;
            Copy_u16num = Copy_u16num / 10U;
        }
        for (; Local_u8iterator < 5U; Local_u8iterator++)
        {
            LCD_vidWriteChar(arr[Local_u8iterator] + '0');
        }
    }

}
