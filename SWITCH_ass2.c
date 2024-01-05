/*
 * SWITCH_ass2.c
 *
 *  Created on: Dec 22, 2023
 *      Author: Abir Omara
 */


/* Lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#define F_CPU   8000000UL

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "KPD_interface.h"
#include "LCD_interface.h"

#include "STEPPER_MOTOR_interface.h"



void Motor_cw (void);
void Motor_ccw (void);
void Stop_MOTOR (void);
u8 Angle (u8 x,u8 y, u8 z);


int main ()
{

	u8 Correct_password [4]={'1','1','1','1'};
	u8 Input_password [4];
	u8 Local_u8CounterPassword=0;
	u8 Local_u8NumOfAttempts=0;
	u8 Local_u8NumOfMaxAttempts=3;
	u8 Local_u8Flag;
	u8 Local_u8Choose_motor=0;
	u8 Local_u8Choose_motor_direction=0;
	u8 Local_u8Exit=0;
	u8 Local_u8AAngle[3];
	u8 Local_u8CounterAngle=0;
	u8 Local_u8Angle;




	u8 Local_u8Key;

	DIO_voidInit();
	LCD_voidInt();

	while (Local_u8NumOfAttempts !=Local_u8NumOfMaxAttempts)
	{
		LCD_u8GoToXY(1,0);
		LCD_voidWriteString("Enter password");
		while (Local_u8CounterPassword != 4)
		{
			KPD_u8GetKeyState(&Local_u8Key);
			//if there are no switch pressed
			//no displaying on LCD
			if (Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
			{
				LCD_u8GoToXY(2,Local_u8CounterPassword);
				LCD_voidSendData(Local_u8Key);
				_delay_ms(200);
				LCD_u8GoToXY(2,Local_u8CounterPassword);
				LCD_voidSendData('*');
				Input_password[Local_u8CounterPassword]=Local_u8Key;
				Local_u8CounterPassword++;
			}
		}
		if ((Input_password[0]==Correct_password[0]) && (Input_password[1]==Correct_password[1]) && (Input_password[2]==Correct_password[2])  &&(Input_password[3]==Correct_password[3]))
		{
			Local_u8Flag=0;
		}

		else
		{
			Local_u8Flag=1;
		}
		if (Local_u8Flag ==0)
		{
			LCD_voidClearDisplay();
			LCD_u8GoToXY(1,0);
			LCD_voidWriteString("Welcome to motor Dash Board");
			_delay_ms(3000);
			LCD_voidClearDisplay();
			LCD_u8GoToXY(1,0);
			LCD_voidWriteString("1-DC Motor3-Exit2-Stepper Motor");
			Local_u8Choose_motor=0;
			while (Local_u8Choose_motor !=1)
			{
				KPD_u8GetKeyState(&Local_u8Key);

				if (Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
				{
					LCD_voidClearDisplay();
					LCD_u8GoToXY(1,0);
					LCD_voidSendData(Local_u8Key);

					switch (Local_u8Key)
					{
					case '1':
						LCD_voidClearDisplay();
						LCD_u8GoToXY(1,0);
						LCD_voidWriteString("1-cw       2-ccw3-Stop    4-back");
						Local_u8Choose_motor_direction=0;
						while (Local_u8Choose_motor_direction!=1)
						{
							KPD_u8GetKeyState(&Local_u8Key);
							if (Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
							{
								LCD_voidClearDisplay();
								LCD_u8GoToXY(1,0);
								LCD_voidSendData(Local_u8Key);

								switch (Local_u8Key)
								{
								case '1':
									LCD_u8GoToXY(2,0);
									LCD_voidWriteString("Rotate CW");
									Motor_cw();
									break;
								case '2':
									LCD_u8GoToXY(2,0);
									LCD_voidWriteString("Rotate CCW");
									Motor_ccw();
									break;
								case '3':
									LCD_u8GoToXY(2,0);
									LCD_voidWriteString("Stop");
									Stop_MOTOR();
									break;
								default:
									Local_u8Choose_motor_direction=1;
									Local_u8Choose_motor=1;
								}
							}
						}
						break;
					case '2':
						LCD_voidClearDisplay();
						LCD_u8GoToXY(1,0);
						LCD_voidWriteString("Angle:");
						Local_u8CounterAngle=0;
						while (Local_u8CounterAngle != 3)
						{
							KPD_u8GetKeyState(&Local_u8Key);
							//if there are no switch pressed
							//no displaying on LCD
							if (Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
							{

								LCD_u8GoToXY(1,Local_u8CounterAngle+7);
								LCD_voidSendData(Local_u8Key);
								_delay_ms(200);
								Local_u8AAngle[Local_u8CounterAngle]=Local_u8Key;
								Local_u8CounterAngle++;
							}
						}
						Local_u8Angle=Angle(Local_u8AAngle[0],Local_u8AAngle[1],Local_u8AAngle[2]);
						LCD_voidClearDisplay();
						LCD_u8GoToXY(1,0);
						LCD_voidWriteString("1-cw       2-ccw3-back");
						Local_u8Choose_motor_direction=0;
						while (Local_u8Choose_motor_direction!=1)
						{
							KPD_u8GetKeyState(&Local_u8Key);
							if (Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
							{
								LCD_voidClearDisplay();
								LCD_u8GoToXY(1,0);
								LCD_voidSendData(Local_u8Key);
								switch (Local_u8Key)
								{
								case '1':
									LCD_u8GoToXY(2,0);
									LCD_voidWriteString("Rotate CW");
									StepperMotor_Move_CW(Local_u8Angle);
									LCD_u8GoToXY(2,0);
									LCD_voidWriteString("Rotate CW Done");
									break;
								case '2':
									LCD_u8GoToXY(2,0);
									LCD_voidWriteString("Rotate CCW");
									StepperMotor_Move_CCW(Local_u8Angle);
									LCD_u8GoToXY(2,0);
									LCD_voidWriteString("Rotate CCW Done");
									break;

								default:
									Local_u8Choose_motor_direction=1;
									Local_u8Choose_motor=1;
								}
							}
						}
						break;
					case '3':
						Local_u8Choose_motor=1;
						LCD_voidClearDisplay();
						Local_u8CounterPassword=0;

						break;
					}
				}
			}
		}


		else if (Local_u8Flag==1)
		{
			LCD_voidClearDisplay();
			LCD_u8GoToXY(1,0);
			LCD_voidWriteString("incorrect       password");
			_delay_ms(500);
			LCD_voidClearDisplay();
			//LCD_u8GoToXY(1,0);
			//LCD_voidWriteString("try again");
			//_delay_ms(1000);
			Local_u8CounterPassword=0;
			Local_u8NumOfAttempts++;
			if (Local_u8NumOfAttempts ==Local_u8NumOfMaxAttempts)
			{
				LCD_voidClearDisplay();
				LCD_u8GoToXY(1,0);
				LCD_voidWriteString("you tried 3     times");
				_delay_ms(500);
				LCD_voidClearDisplay();
				LCD_u8GoToXY(1,0);
				LCD_voidWriteString("wait for 5 sec  and try later");
				_delay_ms(5000);
				LCD_voidClearDisplay();
				Local_u8NumOfAttempts=0;
			}
		}
	}

	return 0;
}

void Motor_cw (void)
{
	DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_PIN_LOW);
}
void Motor_ccw (void)
{
	DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_PIN_LOW);
	DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_PIN_HIGH);
}

void Stop_MOTOR (void)
{
	DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_PIN_LOW);
	DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_PIN_LOW);
}
u8 Angle (u8 x,u8 y, u8 z)
{
	/*we subtract 48 to convert ASCII to digit*/
	u8 a=x-48,b=y-48,c=z-48;
	return a*100+b*10+c;
}

