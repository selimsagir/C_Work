#ifndef MY_STRING_H
#define MY_STRING_H

enum position{
    BEGIN,
    END,
};

struct string *makeString(const char *s);

void destroyString(struct string* s);

int stringLen(struct string* s);

int stringCharAt(struct string* s, int index);

void stringPrint(struct string *s);

void stringJoin(struct string *s, const char *ch);

void stringRemoveChar(struct string *s,  const char ch);

void stringRemoveOccurance(struct string *s);

int stringRemoveFrom(struct string *s, enum position pos);

struct string* stringGetUser(void);

void  removeNumeric(struct string *s);
void stringChangeChar(struct string *s, char ch, int index);

void stringReverse(struct string *s);

#endif // MY_STRING_H
