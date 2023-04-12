#include "shape.h"


// constructor
void Shape_ctor(Shape * const me, int16_t x, int16_t y){
    me->x = x;
    me->y = y;

}

void Shape_moveBy(Shape * const me, int16_t dx, int16_t dy){
    me->x = me->x + dx;
    me->y = me->y + dy;

}

int16_t Shape_getX(Shape const * const me){
    return me->x;

}

int16_t Shape_gety(Shape const * const me){
    return me->y;

}
