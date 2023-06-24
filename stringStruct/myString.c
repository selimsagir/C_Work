#include <stdlib.h>
#include <string.h>

#include "myString.h"

struct string {
    int length;
    char *data;
};

struct string *makeString(const char *s){

    struct string *s2;
    s2 = malloc(sizeof(struct string));
    if(0 == s2) {
        return 0;
    }
    s2->length = strlen(s);
    (*s2).data = malloc(s2->length);

    if(s2->data == 0) {
        free(s2);
    }
    strncpy(s2->data, s, s2->length);
    return s2;

};

void destroyString(struct string* s){

    free(s->data);
    free(s);
}

int stringLen(struct string* s){
    return s->length;
}

int stringCharAt(struct string *s, int index){

    if(index < 0 || index >= s->length){
        return -1;
    }
    else
    {
        return s->data[index];
    }
}


//test func
 int var = 10;
 int returnVar(void){
    return var;
 }
