// switch to terminal is ctrl ~ in vscode
// switch to editor is ctrl + 1 


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include <limits.h>

#define QUEUE_EMTY INT_MIN

typedef struct {

    int *values;
    int size;
    int tail;
    int head;
    int num_etries;
}q_value; 

void q_init(q_value *q, int size){
    q->head = 0;
    q->tail = 0;
    q->size = size;
    q->values = malloc(sizeof(int) * q->size );
    q->num_etries =0;

}

bool q_list_full(q_value *q){
    return (q->num_etries == q->size );
}

bool q_list_empty(q_value *q){
    return (q->num_etries == 0 );
}

void q_list_destroy(q_value *q){
    free(q->values);
}

bool q_list_fill(q_value *q, int new_value){

    if(q_list_full(q))
        return false;
    q->values[q->tail] = new_value;
    q->num_etries ++;
    q->tail = (q->tail +1) % q->size;
    return true;
}

int q_list_decrease(q_value *q ){
    int result;
    if(q_list_empty(q)){
        return QUEUE_EMTY;
    }
    result = q->values[q->head];
    // q->head = (q->head + 1) % q->size;
    if (q->head == q->size - 1) {
        q->head = 0;
    } else {
        q->head++;
    }


    q->num_etries--;
    return result;

}


int main(){

    q_value q;
    q_init(&q, 5);
    q_list_fill(&q,100);
    q_list_fill(&q,55);
    q_list_fill(&q,44);
    q_list_fill(&q,66);
    q_list_fill(&q,33);

    int t;
    while ((t = q_list_decrease(&q)) != QUEUE_EMTY )
    {
        printf(" t = %d", t);
    }
    
 return 0;
}