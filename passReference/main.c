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

int main()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    packet_t pack1;
    math_t math1;

    packet_t pack_list[5];

    func_list(pack_list, 5);

    for (uint8_t i = 0; i < 5; i++) {
        pack_list[i].x = i;
    }
    printf("After: %.1f\n", pack_list[2].x);

    pack1.val = arr;

    pack1.x = 90;
    pack1.y = 80;

    func(&pack1, &math1);
    printf("val: %d\n", pack1.val[0]);  // first value
    printf("sum: %.1f\n", math1.sum);
    printf("diff: %.1f\n", math1.diff);
    printf("string: %s\n", pack1.name);

    return 0;
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
