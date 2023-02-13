#include <stdio.h>
#include <stdlib.h>



#define ROWS 3
#define COLUMNS 3

int main()
{
    int array[ROWS][COLUMNS];
    // fill the array
    printf("Enter the 5 array is:\n");
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            scanf("%d",&array[i][j]);
        }
    }
    printf("The array is:\n");
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            printf("%d  ",array[i][j]);
        }
        printf("\n\n");
    }

    int sum = 0;
    for(int i = 0; i < ROWS; i++){
        sum = 0;
        for(int j = 0; j < COLUMNS; j++){
            sum += array[i][j];
        }
        printf("Row=%d Sum=%d\n", i, sum);
    }

    return 0;
}
