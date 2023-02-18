#include <stdio.h>
#include <stdlib.h>




int find_second_highest(int arr[], int len);

int main()
{

    int array[] = { 1,2,10,3,4,5,6,7,8,9};
    int len = 10;

    printf("Second highest number is : %d ",find_second_highest(array, len) );
    return 0;
}


int find_second_highest(int arr[], int len){

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
    return max2;
}
