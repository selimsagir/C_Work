#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef enum
{
	ALL_OFF	= 	0,
	RED_ON	= 	1,
	RED_OFF = 	2,
	BLUE_ON = 	3,
	BLUE_OFF= 	4,
	GREEN_ON = 	5,
	GREEN_OFF = 6,
	ALL_ON	=	7

}LED_CMDS;  // uzunlugu belli degil


typedef struct Led
{
   void (*On)(  );
   void (*Off)(  );

}led_t;

void LED_Off(void);
void LED_On(void);

int8_t sendingTask(void);
void receiverTask(LED_CMDS led_status);


int main()
{
    led_t RedLed;

    RedLed.On = LED_On;
    RedLed.Off = LED_Off;
    printf("%d,",sizeof(LED_CMDS));
    RedLed.On();
    RedLed.Off();
    //

    sendingTask();

    return 0;
}

int8_t sendingTask(void){


    for(LED_CMDS i = 0; i < 2; i++)
    {
        receiverTask(i);
    }
}

void receiverTask(LED_CMDS led_status){

    switch(led_status){
        case ALL_OFF:
            printf("all off\n\r");
            break;
        case RED_ON:
            printf("red on\n\r");
        break;
    }
}

void LED_Off(){
    printf("Off\n\r");
}
void LED_On(){
    printf("On\n\r");
}
