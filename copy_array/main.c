#include <stdio.h>
#include <stdlib.h>

#define LENGTH(x) (sizeof(x) / sizeof(x[0]))

int *copy_array(int *arr, int len);

int main()
{
    int arr1[] = {1, 2, 23, 4, 5, 6, 6, 8};
    int arr2[] = {5, 6, 7, 234, 6, 2, 3, 47, 77};
    int len = LENGTH(arr2);
    int *ret_arr = copy_array(arr2, len);
    printf("length of the array is %d\n", len);
    for(int i = 0; i < len; i++) {
        printf("%d ", ret_arr[i]);
    }
    free(ret_arr);

    return 0;
}

int *copy_array(int *arr, int len)
{
    int *c = malloc(len * sizeof(int));
    for(int i = 0; i < len; i++) {
        c[i] = arr[i];
    }
    return c;
}
