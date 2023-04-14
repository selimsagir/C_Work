#include <stdlib.h>
#include <stdio.h>

#include "linked.h"

int main(){

    queue q;
    init_queue(&q,5);
    insert_val(&q, 11);
    insert_val(&q, 22);
    insert_val(&q, 33);
    insert_val(&q, 44);
    insert_val(&q, 55);
    insert_val(&q, 66);
    insert_val(&q, 77);
    print_val(&q);
    int val = remove_val(&q);
    printf("removed : %d \n",val);
    print_val(&q);
    return 0;

}