#include <stdio.h>
#include <stdlib.h>
#include "myString.h"



int main()
{
    struct string *new_string;

    struct string *myString = makeString("AB");

    printf("Len is : %d\n", stringLen(myString));
    printf("char is : %c\n", stringCharAt(myString, 2));
  //  stringPrint(myString);


/*
    printf("\n");
    stringRemoveChar(myString,'S');
    stringRemoveChar(myString,'e');
    stringRemoveChar(myString,'A');
    stringPrint(myString);
    stringJoin(myString, "X");
*/
   // stringPrint(myString);
    stringRemoveFrom(myString, BEGIN);
    stringPrint(myString);
    stringRemoveFrom(myString, END);
    stringPrint(myString);
}
