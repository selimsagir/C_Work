#include <stdio.h>
#include <stdlib.h>
#include "circular_buffer.h"

#define BUFFER_SIZE 10

int main() {
  uint8_t buffer[BUFFER_SIZE];
  cbuf_handle_t handle = circular_buf_init(buffer, BUFFER_SIZE);

  if (handle == NULL) {
    printf("Error: failed to create circular buffer\n");
    return -1;
  }

// static int status;
// status = circular_buf_try_put(handle, 1);
// printf("%d ", status);
// status =circular_buf_try_put(handle, 2);
// printf("%d ", status);
// status =circular_buf_try_put(handle, 3);
// printf("%d ", status);
// status =circular_buf_try_put(handle, 4);
// printf("%d ", status);


  // add data to the buffer
  for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
    int status = circular_buf_try_put(handle, i);
    if (status == -1) {
      printf("Buffer is full, can't add more data\n");
      break;
    }
  }

  // read data from the buffer
  uint8_t data;
  while (!circular_buf_empty(handle)) {
    int status = circular_buf_get(handle, &data);
    if (status == -1) {
      printf("Buffer is empty, can't read more data\n");
      break;
    }
    printf("Data: %d\n", data);
  }

  circular_buf_free(handle);

  return 0;
}
