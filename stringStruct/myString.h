#ifndef MY_STRING_H
#define MY_STRING_H


struct string *makeString(const char *s);

void destroyString(struct string* s);

int stringLen(struct string* s);

int stringCharAt(struct string* s, int index);

void stringPrint(struct string *s);

int returnVar(void);




#endif // MY_STRING_H
