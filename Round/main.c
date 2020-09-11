#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "roundUtil.h"
int main()
{
    double val = 123.456;
    double result = roundToCents(val);
    printf("%f -> %f",val, result);
    return 0;
}


