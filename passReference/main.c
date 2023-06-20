#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct {
    int * val;
    float x;
    float y;
}packet_t;

typedef struct {
    float sum;
    float diff;

}math_t;

int func(packet_t *pack, math_t *Imath);

int main()
{

    int arr[10] = {0,1,2,3,4,5,6,7,8,9};



    packet_t pack1;
    math_t math1;

    pack1.val = (int*)100;
    pack1.val = arr;
    pack1.x = 90;
    pack1.y = 80;

    func(&pack1,&math1);
    printf("val :%d\n", *pack1.val);  // first value

    printf("sum :%f\n", math1.sum);

    printf("diff :%f\n", math1.diff);
    return 0;
}



int func(packet_t *pack, math_t *Imath){
    //pack->val = 11;
    //pack->x = 12;
    uint8_t idx;
    for(idx = 0; idx < 10; idx++){
        printf("%d - ", pack->val[idx]);
    }
    printf("\n");
    Imath->sum = pack->y + pack->x;
    Imath->diff = pack->y - pack->x;
    return 0;
}
