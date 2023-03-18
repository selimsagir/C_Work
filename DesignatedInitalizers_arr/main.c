// C program to demonstrate designated initializers
// with arrays.
#include <stdio.h>
void main(void)
{
    int arr[10] = {1,2,3, [3 ... 9]=10 };
    for(int i = 0; i < 10; i++){
        printf("%d  ", arr[i]);

    }
}
