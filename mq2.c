#include<stdio.h>
#include<wiringPi.h>
#include<string.h>
#include<time.h>

#define IO_PORT 4

void init_gpio()
{
	wiringPiSetup();
	pinMode(IO_PORT, INPUT);
}

int get_value()
{			
	if(digitalRead(IO_PORT) == 0)
	{
		printf("Digital value is %d\n", digitalRead(IO_PORT));
		return 1;
	}
	else
	{
		printf("Digital value is %d\n", digitalRead(IO_PORT));
		return 0;
	}
}

int
main()
{
	init_gpio();
	digitalWrite(IO_PORT, 1);
	 while(1)
	{
		delay(3000);
		if(get_value())
		{
			printf("Warning!!!\a\a\a\n");
		}
		else
		{
			printf("Normal\n");
		}
	}	
}
