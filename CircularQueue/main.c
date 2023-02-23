#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define QUEUE_EMTY INT_MIN

typedef struct{

    int * values;
    int head, tail, num_entries, size;
} queue;

void init_queue(queue *q, int max_size){
    q->size = max_size;
    q->values = malloc(sizeof(int) * q->size);
    q->head = 0;
    q->tail = 0;
    q->num_entries = 0;
}

bool queue_emty(queue *q){
    return (q->num_entries == 0);
}
bool queue_full(queue *q){
    return (q->num_entries == q->size);
}
bool queue_destroy(queue *q){
    free(q->values);
}


bool enqueue(queue *q, int value){

    if(queue_full(q)) {
        return false;
    }
    q->values[q->tail] = value;
    q->num_entries++;
    q->tail = (q->tail +1) % q->size;
    return true;
}
int dequeue(queue *q){

    int result;
    if(queue_emty(q)){
        return QUEUE_EMTY;
    }
    result = q->values[q->head];
    q->head = (q->head + 1) % q->size;
    q->num_entries--;
    return result;
}

int main()
{
    queue q1;

    init_queue(&q1, 5);

    enqueue(&q1, 66);
    enqueue(&q1, 55);
    enqueue(&q1, 44);
    enqueue(&q1, 33);


    int t;
    while((t = dequeue(&q1)) != QUEUE_EMTY ){
        printf("t = %d\n", t);
    }


    return 0;
}







