#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int max1; // max value
    int max2; // second max value
}values_t;

values_t *find_second_highest(int arr[], int len);

int main()
{

    int array[] = { 1,2,10,3,4,5,6,7,8,9};
    int len = 10;
    values_t *r = find_second_highest(array, len);
    printf("Second highest number is : %d ", r->max2 );
    free(r);
    return 0;
}


values_t *find_second_highest(int arr[], int len){


    values_t *p = (values_t*)malloc(sizeof(values_t));

    int max1 = 0;
    int max2 = 0;
    if(arr[0] > arr[1])
    {
        max1 = arr[0];
        max2 = arr[1];
    }
    if(arr[1] > arr[0])
    {
        max1 = arr[1];
        max2 = arr[0];
    }

    for(int i = 2; i < len; i++){
        if(arr[i] > max1){
            max2 = max1;
            max1 = arr[i];

        }
        else if((arr[i] > max2) && (arr[i] < max1)){
            max2 = arr[i];
         }
    }

    p->max1 = max1;
    p->max2 = max2;
    return p;
}
