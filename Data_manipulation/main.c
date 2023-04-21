#include "stdlib.h"
#include "stdio.h"
#include "stdint.h"

#define SIZE_OF_PAYLOAD 10
typedef struct my_packet{

    uint8_t payload[SIZE_OF_PAYLOAD];
    uint8_t id;
    uint16_t length;
}packet_t;

packet_t* sender(packet_t *packet);
void receiver(void *x);

int main(){

    packet_t pack;
    sender(&pack);
    printf("%d", pack.id);
    receiver(&pack);
    printf("%d", pack.id);
}


void receiver(void *x){
    uint32_t cmd;
    (void)cmd;
 
    packet_t y = *(packet_t*)x;
    printf("%d", y.length);
    y.id = 88;


}   

packet_t* sender(packet_t * packet){

    
    
    for(size_t i = 0; i < SIZE_OF_PAYLOAD; i++){
        packet->payload[SIZE_OF_PAYLOAD] = i;
    }

    packet->id = 99;
    packet->length = 11;
    return packet;



}