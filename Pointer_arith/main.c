
#include "main.h"

int main()
{
    int var1 = 10;
    int var2 = 20;

    mys_t s1;
    mys_f * myF = (mys_f*)malloc(sizeof(mys_f));

    myF->v1 = 100;
    myF->v2 = (uint16_t*)&var2;

    s1.f1[0] = func;
    s1.f1[1] = func2;

    s1.f1[0](myF);
    s1.f1[1](myF);
    printf("func3 : %d\n", *myF->v2);
    free(myF);
 
    return 0;
}

void func(mys_f *x){
    uint16_t val = x->v1;
    printf("func : %d\n", val);
}
void func2(mys_f *x){

    uint16_t *val = x->v2;
    printf("func2 : %d\n", *val);
    *val = 99;
}
