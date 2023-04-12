#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "rect.h"
#include "shape.h"


int main()
{

    Rectangle r1, r2;

    Rectangle_ctor(&r1, 0, 2, 10, 20);
    Rectangle_ctor(&r2, -1, 3, 5, 10);
    
    int16_t retA = Shape_getX(&r1.super);
    int16_t retB = Shape_gety(&r1.super);
    printf("%d, ", retA);
    printf("%d \n", retB);

    int16_t retC = Shape_getX(&r2.super);
    int16_t retD = Shape_gety(&r2.super); 
    printf("%d, ", retC);
    printf("%d \n", retD);

    Shape_moveBy((Shape*)&r1, 100, 200);
    Shape_moveBy(&r2.super, 200, 300);

    int16_t retMA = Shape_getX(&r1.super);
    int16_t retMB = Shape_gety(&r1.super);
    printf("%d, ", retMA);
    printf("%d \n", retMB);

    int16_t retMC = Shape_getX(&r2.super);
    int16_t retMD = Shape_gety(&r2.super); 
    printf("%d, ", retMC);
    printf("%d \n", retMD);


}