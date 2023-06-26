#include <stdlib.h>
#include <string.h>

#include "myString.h"

struct string {
    int length;
    char *data;
};


struct string *makeString(const char *s) {
    struct string *s2;
    s2 = malloc(sizeof(struct string));
    if (s2 == 0) {
        return 0;
    }
    s2->length = strlen(s);
    s2->data = malloc(sizeof(char) * (s2->length + 1));
    if (s2->data == 0) {
        free(s2);
        return 0;
    }
    strncpy(s2->data, s, s2->length);
    s2->data[s2->length] = '\0'; // Add the null terminator
    return s2;
}


void stringRemoveOccurance(struct string *s){

    int idx = 0;
    while(s->data[idx] != '\0'){
        //aabcc
        if(s->data[idx] == s->data[idx+1]){
            for(int i = idx; i < s->length; i++){
                s->data[i] = s->data[i+1];
            }
            s->length--;
        }
        else {
            idx++;
        }
    }
}

void stringJoin(struct string *s, const char *ch){
    int len = strlen(ch);
    int len_left = strlen(s->data);
    s->length += len;
    s->data = realloc(s->data, s->length + 1);
    memcpy(&s->data[len_left], ch, len+1);
}

void stringRemoveChar(struct string *s,  const char ch) {
    int len = s->length;
    int idx = 0;
    while (s->data[idx] != '\0') {
        if(s->data[idx] == ch)
        {
            for(int i = idx; i<len; i++)
            {
                s->data[i] = s->data[i+1];
            }
        s->length--;
        }
    idx++;
    }

}

void stringPrint(struct string *s){
    int idx = 0;
    printf("\n\n");
    while(!(s->data[idx] == '\0')){
        printf("%c", s->data[idx]);
        idx++;
    }

}

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

