
#ifndef MAIN_H
#define MAIN_H

typedef struct mys{
    void (*f1[2])(int *x);
}mys_t;

typedef struct mysf{
    uint16_t v1;
    uint16_t *v2;
}mys_f;



void func(mys_f *x);
void func2(mys_f *x);

#endif /* MAIN_H */