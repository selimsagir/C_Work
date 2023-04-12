#ifndef SHAPE_H
#define SHAPE_H

#include <stdint.h>

// Shape's attributes

typedef struct 
{
    int16_t x;
    int16_t y;
}Shape;

// Shape's interface

void Shape_ctor(Shape * const me, int16_t x, int16_t y);

void Shape_moveBy(Shape * const me, int16_t dx, int16_t dy);

int16_t Shape_getX(Shape const * const me);

int16_t Shape_gety(Shape const * const me);

#endif /* SHAPE_H */