#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#include "circular_buffer.h"

struct circular_buf_t
{
    uint8_t *buffer;
    size_t head;
    size_t tail;
    size_t max; // of the buffer
    bool full;
};

static inline size_t advance_headtail_value(size_t value, size_t max)
{
	return (value + 1) % max;
// if (value + 1 == max) {
// return 0;
// } else {
// return value + 1;
// }
}

static void advance_head_pointer(cbuf_handle_t me)
{
	assert(me);

	if(circular_buf_full(me))
	{
		me->tail = advance_headtail_value(me->tail, me->max);
	}

	me->head = advance_headtail_value(me->head, me->max);
	me->full = (me->head == me->tail);
}


cbuf_handle_t circular_buf_init(uint8_t* buffer, size_t size){
    assert(buffer && size);

    cbuf_handle_t cbuf = malloc(sizeof(circular_buf_t));
    assert(cbuf);

    cbuf->buffer = buffer;
    cbuf->max = size;
    cbuf->full = false;
    circular_buf_reset(cbuf);
    assert(circular_buf_empty(cbuf));
    return cbuf;
}

void circular_buf_free(cbuf_handle_t me){
    assert(me);
    free(me);
}

 
void circular_buf_reset(cbuf_handle_t me){
    assert(me);
    me->head = 0;
    me->tail = 0;
    me->head = 0;
}

size_t circular_buf_size(cbuf_handle_t me){

    assert(me);
    size_t size = me->max;

    if(!circular_buf_full(me)){
        if(me->head >= me->tail)
        {
            size = (me->head - me->tail);
        }
        else 
        {
            size = (me->max + me->head - me->tail);
        }
    }
    return size;
}

size_t circular_buf_capacity(cbuf_handle_t me)
{
	assert(me);

	return me->max;
}
/// Put that continues to add data if the buffer is full
void circular_buf_put(cbuf_handle_t me, uint8_t data){
    assert(me && me->buffer);

    me->buffer[me->head] =data;
    advance_head_pointer(me);
}

/// Put that rejects new data if the buffer is full
int circular_buf_try_put(cbuf_handle_t me, uint8_t data){
    
    int r = -1;
    assert( me && me->buffer);

    if(!circular_buf_full(me))
	{
		me->buffer[me->head] = data;
		advance_head_pointer(me);
		r = 0;
	}

	return r;

}
/// Retrieve a value from the buffer
int circular_buf_get(cbuf_handle_t me, uint8_t* data){

    assert(me && me->buffer && data);

    int r = -1;

    if(!circular_buf_empty(me)){
        *data = me->buffer[me->tail];
        me->tail = advance_headtail_value(me->tail, me->max);
        me->full = false;
        r = 0;
    }
    return r;
}

bool circular_buf_empty(cbuf_handle_t me){
    assert(me);
    return (!circular_buf_full(me) && (me->head == me->tail));
}

bool circular_buf_full(cbuf_handle_t me){

    assert(me);
    return me->full;
}

int circular_buf_peek(cbuf_handle_t me, uint8_t* data, unsigned int look_ahead_counter){

    int r = -1;
    size_t pos;

    assert(me && data && me->buffer);

    if(look_ahead_counter > circular_buf_size(me) || circular_buf_empty(me)){
        return r;
    }

    pos = me->tail;
    for(unsigned int i = 0; i < look_ahead_counter; i++)
    {
        data[i] = me->buffer[pos];
        pos = advance_headtail_value(pos, me->max);
    }
    return 0;

}