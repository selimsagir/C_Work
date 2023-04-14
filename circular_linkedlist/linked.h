#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>


void print(void);

enum size {
    EMPTY,
    NOT_EMPTY,
    FULL,
    NOT_FULL,
};

typedef struct queue{
    int *val;
    uint32_t head, tail, entries, size; 
}queue;


size_t isEmpty(queue *q);
size_t isFull(queue *q);
void init_queue(queue *q, int max_size);
bool insert_val(queue *q, int val);
int remove_val(queue *q);
void print_val(queue *q);