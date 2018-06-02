/***************************************************************************
*
*
* ECG.c
*
* Created by Shubham Gupta 
* Copyright (c) shubhamgupta.org  and/or its affiliates.
* All rights reserved.
***************************************************************************/

#include "ECG.h"

////////////////////////// ECG SEnsore /////////////////////////////
void AB_STEM_init_ECG()
{	
	enableADC();
	setDirection(AB_P8,AB_INPUT);
	setDirection(AB_P9,AB_INPUT);
}
int AB_STEM_Read_ECG()
{	
	int e_value = 0;
	if((digitalRead(AB_P8) == 1) || (digitalRead(AB_P9) == 1))
	{
		return 0;
	}
	else
	{
		e_value=readAnalogValue(AB_CHANNEL_2, AB_INTERNAL);
		return e_value;
	}
}


int main()
{
	int ecgValue=0;
	AB_STEM_init_ECG();
	
	while(1)
	{
		ecgValue=AB_STEM_Read_ECG()	;	///// gives The ECG pulse Analog value to graph
	}

		return 0;
}