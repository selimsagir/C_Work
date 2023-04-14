#include "linked.h"

// void print(void){
//     printf("Library");
// }



void init_queue(queue *q, int max_size){

    q->size = (uint32_t)max_size;
    q->val = malloc(sizeof(queue) * q->size);
    q->head = 0;
    q->tail = 0;
    q->entries = 0;

}
size_t isEmpty(queue *q){
    if(q->size == 0){
        return EMPTY;
    }
    else return NOT_EMPTY;
}

size_t isFull(queue *q){
    if(q->entries == q->size){
        return FULL;
    }
    else return NOT_FULL;
}

bool insert_val(queue *q, int val){
    if (isFull(q) == FULL)
    {
       printf("List is full\n");
       return false;
    }
    q->val[q->tail] = val;
    q->entries++;
    if(q->tail == q->size -1){
        q->tail = 0;
    }
    else{
        q->tail++;
    }
    return true;
    
}

int remove_val(queue *q){
    if(isEmpty(q) == EMPTY ){
        return false;
    }
    int ret = q->val[q->head];
    q->entries--;
    if(q->head == q->size -1){
        q->head =0;
    }
    else{
        q->head++;
    }
    return ret;
}

void print_val(queue *q){

    for(uint32_t i = 0; i < q->entries; i++)
        printf("%d\n", q->val[i]);
    
}


