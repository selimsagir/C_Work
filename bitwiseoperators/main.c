#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void bprint(int val){
    char str[sizeof(int) *8+1];
    itoa(val, str, 2);
    printf("%0*s\n", sizeof(int) * 8, str);
}

int main()
{
    int x;
    printf("Bir tam sayi giriniz: ");
    scanf("%d",&x);
    bprint(x);
    bprint(~x);
    printf("x = %d\n", x);
    return 0;
}
