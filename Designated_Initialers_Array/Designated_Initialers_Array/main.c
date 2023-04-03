

/*
* Designated initializers
*/

#include <stdio.h>
void main(void)
{
    int numbers[100] = { 1, 2, 3,[3 ... 9] = 10,
          [10] = 80, 15,[70] = 50,[42] = 400 };

    int i;
    for (i = 0; i < 20; i++)
        printf("%d ", numbers[i]);

    printf("\n%d ", numbers[70]);
    printf("%d", numbers[42]);
}

