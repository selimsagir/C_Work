#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct {
    char name[10];
    int *val;
    float x;
    float y;
} packet_t;

typedef struct {
    float sum;
    float diff;
} math_t;

void func_list(packet_t *Lpack, size_t size);
int func(packet_t *pack, math_t *Imath);
packet_t* create_struct(size_t size);

void cast_func(void *ptr);

int main()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    packet_t pack1;
    math_t math1;

    //packet_t pack_list[5];


    packet_t *pack_list;
    pack_list = create_struct(5);


    for (uint8_t i = 0; i < 5; i++) {
        pack_list[i].x = (i+5)*2;   // 10, 12, 14
    }

    cast_func(pack_list);

    printf(" \n");
    for (uint8_t i = 0; i < 5; i++) {
       printf("*%f\n", pack_list[i].x);
        //pack_list[i].x = i;
    }
    printf(" \n");

    func_list(pack_list, 5);

    printf("After: %.1f\n", pack_list[2].x);

    pack1.val = arr;

    pack1.x = 90;
    pack1.y = 80;

    func(&pack1, &math1);
    printf("val: %d\n", pack1.val[0]);  // first value
    printf("sum: %.1f\n", math1.sum);
    printf("diff: %.1f\n", math1.diff);
    printf("string: %s\n", pack1.name);

    free(pack_list);
    return 0;
}


void cast_func(void *ptr){
    packet_t *pack = (packet_t*)ptr;
    float x = (pack++)->x;
    printf("casting: %.1f\n", x);
    float y = (pack++)->x;
    printf("casting+: %.1f\n", y);
    float z = (pack++)->x;
    printf("casting++: %.1f\n", z);
}

packet_t* create_struct(size_t size){
    packet_t *pack_list = (packet_t*)malloc(size*sizeof(packet_t));
    return  pack_list;
}

void func_list(packet_t *Lpack, size_t size)
{
    printf("Before change:\n");
    for (uint8_t i = 0; i < size; i++) {
        printf("%.1f\n", Lpack[i].x);
    }
    Lpack[2].x = 222;
}

int func(packet_t *pack, math_t *Imath)
{
    snprintf(pack->name, 10, "Selim");

    for (uint8_t idx = 0; idx < 10; idx++) {
        printf("%d - ", pack->val[idx]);
    }

    printf("\n");
    Imath->sum = pack->y + pack->x;
    Imath->diff = pack->y - pack->x;

    return 0;
}
