#include <stdio.h>
#include <stdlib.h>

void reverse_array(int arr[], int len);

int main()
{

    int array[] = {1,2,3,4,5,6,7,8,9,10};

    int length = sizeof(array) / sizeof(int);
    for(int i = 0; i<length; i++){
        printf("%d ", array[i]);
    }
    printf("\nsize is : %d\n", length);
    reverse_array(array, length);

    for(int i = 0; i<length; i++){
        printf("%d ", array[i]);
    }
    return 0;
}


void reverse_array(int arr[], int len){
   int temp = 0;

   for(int i = 0; i < len / 2 ; i++){
    temp = arr[i];
    arr[i] = arr[len - i -1];
    arr[len - i -1] = temp;
   }
}
