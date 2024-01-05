/******************************************************************************************/
/******************************************************************************************/
/******************************     Name   :  Abir Omara     ******************************/
/******************************     Date   :  12/12/2023     ******************************/
/******************************     SWC    :  STEPPER_MOTOR  ******************************/
/******************************   Version  :  1.0            ******************************/
/******************************************************************************************/
/******************************************************************************************/

/* Lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#define F_CPU   8000000UL

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "STEPPER_MOTOR_interface.h"
#include "STEPPER_MOTOR_private.h"
#include "STEPPER_MOTOR_config.h"

void StepperMotor_Move_CW (u16 Copy_u16Degree)
{
	u32 Local_NO_OF_Steps =(Copy_u16Degree*2048UL)/360;
	u32 Local_NO_OF_Iterations=Local_NO_OF_Steps/4;
	u32 Local_Count=0;
	for (Local_Count=0;Local_Count<Local_NO_OF_Iterations;Local_Count++)
	{
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN0,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN1,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN2,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN3,DIO_u8_PIN_LOW);
		_delay_ms(100);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN0,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN1,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN2,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN3,DIO_u8_PIN_HIGH);
		_delay_ms(100);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN0,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN1,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN2,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN3,DIO_u8_PIN_HIGH);
		_delay_ms(100);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN0,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN1,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN2,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN3,DIO_u8_PIN_HIGH);
		_delay_ms(100);
	}
}
void StepperMotor_Move_CCW (u16 Copy_u16Degree)
{
	u32 Local_NO_OF_Steps =(Copy_u16Degree*2048UL)/360;
	u32 Local_NO_OF_Iterations=Local_NO_OF_Steps/4;
	u32 Local_Count=0;
	for (Local_Count=0;Local_Count<Local_NO_OF_Iterations;Local_Count++)
	{
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN0,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN1,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN2,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN3,DIO_u8_PIN_HIGH);
		_delay_ms(100);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN0,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN1,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN2,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN3,DIO_u8_PIN_HIGH);
		_delay_ms(100);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN0,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN1,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN2,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN3,DIO_u8_PIN_HIGH);
		_delay_ms(100);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN0,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN1,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN2,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT,STEPPER_MOTOR_u8_PIN3,DIO_u8_PIN_LOW);
		_delay_ms(100);
	}
}

