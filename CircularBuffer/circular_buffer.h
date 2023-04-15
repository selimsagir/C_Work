#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef struct circular_buf_t circular_buf_t;

// handle to interact with API
typedef circular_buf_t* cbuf_handle_t;

cbuf_handle_t circular_buf_init(uint8_t* buffer, size_t size);

// data buffer temizlenmedi, kullanici mesul
void circular_buf_free(cbuf_handle_t me);

// head = tail olacak, data temizlenmedi
void circular_buf_reset(cbuf_handle_t me);

//  full olana kadar koy
void circular_buf_put(cbuf_handle_t me, uint8_t data);

// return 0 success, return -1 iff full
int circular_buf_try_put(cbuf_handle_t me, uint8_t data);

//0 : basarili , -1 : buffer bos ise
int circular_buf_get(cbuf_handle_t me, uint8_t *data);

//
bool circular_buf_empty(cbuf_handle_t me);

/// Checks if the buffer is full
/// Requires: me is valid and created by circular_buf_init
/// Returns true if the buffer is full
bool circular_buf_full(cbuf_handle_t me);

// max size of buff
size_t circular_buf_capacity(cbuf_handle_t me);

// current number of elements in the buffer
size_t circular_buf_size(cbuf_handle_t me);

// look ahead at values stored in the buiffer without remove values
// return 0 success, -1 if data isn't available
int circular_buf_peek(cbuf_handle_t me, uint8_t *data, unsigned int look_aheah_counter);



#endif