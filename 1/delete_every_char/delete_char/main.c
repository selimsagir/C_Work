#include <stdio.h>
#include <stdlib.h>





int main()
{
    int buffer[100] = {2,1,2,3,4,5,5,6,7,7};
    int size = 10;

    printf("the list is:  ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", buffer[i]);
    }
    int selection = 0;
    printf("\nSelect a number to delete from array: ");
    scanf("%d", &selection);

    // 2,1,2,3,4,5,5,6,7,7
    int i = 0;
    while(i < size)
    {
        if(buffer[i] == selection)
        {
            // if the selection is not correspond to last index
            if(i < (size - 1))
            {
                for(int j = i; j < (size - 1); j++)
                {
                    buffer[j] = buffer[j+1];
                }
            }
            size--;
        }
        else i++;
    }
    printf("the list is:  \n\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", buffer[i]);
    }
    return 0;
}
