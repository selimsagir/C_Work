#include <math.h>
#include "roundUtil.h"
double roundToCents(double amount) {
    double result =round(amount * 100.0)/100.0;
    return result;
}