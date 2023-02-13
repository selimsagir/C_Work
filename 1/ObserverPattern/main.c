#include <stdio.h>
#include <stdlib.h>


#define OBS_SZ 10

typedef void (*observer)(float temperature);
observer observers[OBS_SZ] = {NULL};

void display_temperature(float temperature) {
    printf("displaying temperature %.2f...\r\n", temperature);
    //actually display temperature
}
void send_temperature(float temperature) {
    printf("sending temperature %.2f ...\r\n", temperature);
}

static float temperature = 0.0f;
void notify_temperature(){
        for(int i = 0; i < OBS_SZ; i++){
            if(observers[i] != NULL) {
                observers[i](temperature);
            }
        }

}

void update_temperature(float temp) {
    temperature = temp;
    notify_temperature();
}

int main()
{
    observers[0] = display_temperature;
    observers[1] = send_temperature;
    update_temperature(25.0);
    update_temperature(10);
    return 0;

}
