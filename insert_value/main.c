#include <stdio.h>
#include <stdlib.h>



#define MAX_CAPACITY 100


int main()
{
    int array[MAX_CAPACITY];
    int array_size;
    // Enter the array
    printf("Enter the size of the array: \n");
    scanf("%d", &array_size);
    printf("Enter the the array: \n");

    if(array_size > MAX_CAPACITY){
        printf("Oversize");
        exit(1);
    }

    for(int i = 0; i < array_size; i++){
        scanf("%d", &array[i]);
    }
    printf("Your array is:\n");
    for(int i = 0; i < array_size; i++){
        printf("%d   ", array[i]);

    }

    // 0    1     2    3    4    5
    // 5     6   "4"   2    3     1        | size = 6      = new is 99 index = 2
    // 5     6    99   4    2     3    1   | size = 7
    int array_position = 0;
    int new_member = 0;
    printf("Enter the position");
    scanf("%d", &array_position);
    printf("Enter the number");
    scanf("%d", &new_member);
    int temp = 0;
    for(int i = array_position; i < (array_size); i++)
    {
        array[i + 1] =  array[i];
    }
    array[array_position] = new_member;
    array_size++;
    printf("New array is:\n");
    for(int i = 0; i < array_size; i++){
        printf("%d   ", array[i]);

    }

    return 0;
}
