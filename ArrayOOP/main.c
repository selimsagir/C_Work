#include <stdio.h>
#include <stdlib.h>
 
typedef struct array{

    struct array *self;
    int *data;
    size_t size;
    
    // set value
    void (*pfnSet)(struct array*, size_t, int);
    int  (*pfnGet)(struct array*, size_t);

}array_t;

void set_array(array_t* arr, size_t size, int data){
    for(size_t i = 0; i < size; i++){
        arr->data[i] = data + i;
    }
}

int get_array(array_t *arr, size_t index){
    return arr->data[index];
}

array_t* make_array(size_t size){

    array_t* new_array = (array_t*)malloc(sizeof(array_t));

    new_array->self = new_array;
    new_array->data = (int*)malloc(sizeof(int)*size);
    new_array->size = size;

    new_array->pfnGet = get_array;
    new_array->pfnSet = set_array;

    return new_array;

}

void destroy_array(array_t *self){
    free(self->data);
    free(self);
}

int main()
{
    array_t* test = make_array(10);
    test->pfnSet(test->self, 10, 50);
    for(size_t i = 0; i< test->size; i ++ ){
        printf("%d \n", test->pfnGet(test->self,i));
    }
    destroy_array(test);
}
