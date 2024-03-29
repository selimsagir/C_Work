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

struct string* stringGetUser(void){
    char *ch;
    scanf("%s", ch);
    return ch;
};
void removeNumeric(struct string* s)
{
    int idx, i;
    for (idx = 0; idx < s->length; idx++) {
        if (s->data[idx] >= '0' && s->data[idx] <= '9') {
            printf("here :%c\n", s->data[idx]);
            for (i = idx; i < s->length; i++) {
                s->data[i] = s->data[i + 1];
            }
            s->length--;
            idx--; // Decrease the outer loop index to recheck the current position
        }
    }
    s->data[s->length] = '\0';
}



int stringRemoveFrom(struct string *s, enum position pos)
{
    if(s->length == 0){
        printf("Empty string\n");
        return -1;
    }
    if( pos == BEGIN)
    {
        for(int idx=0; idx<s->length-1; idx++)
        {
            s->data[idx] = s->data[idx+1];
        }
        s->length--;
        s->data[s->length] = '\0'; // Add the null terminator
    }
    else if(pos == END)
    {
        s->length--;
        s->data[s->length] = '\0'; // Add the null terminator
    }
    else
    {
        return -1;
    }

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
    if(s->length == 0){
        printf("Empty string...\n");
        return -1;
    }
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

void stringChangeChar(struct string *s, char ch, int index){

    s->data[index] = ch;

}
void stringReverse(struct string *s){

    int idx;
    char temp;
    int last_idx;
    last_idx = s->length;
    char *reverse = malloc(sizeof(struct string));
    
    for(idx = 0; idx < s->length; idx++){
        temp = s->data[idx];
        // printf("%c",temp);
        reverse[last_idx-1] = temp; 
        printf("%c",reverse[last_idx-1]);
        last_idx--;
        // printf("%d",last_idx);
    }
    strncpy(s->data, reverse,s->length);
    free(reverse);
}

 
void stringDoubleChars(struct string *s) {
    int doubledLength = s->length * 2;
    char *doubledData = (char*)malloc(sizeof(char) * (doubledLength + 1));
    
    for (int i = 0; i < s->length; i++) {
        doubledData[i * 2] = s->data[i];
        doubledData[i * 2 + 1] = s->data[i];
    }
    
    doubledData[doubledLength] = '\0'; // Null-terminate the new string
    free(s->data); // Free the original string
    s->data = doubledData;
    s->length = doubledLength;
}

