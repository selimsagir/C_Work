#include <stdio.h>
#include <stdlib.h>
#include "myString.h"



int main()
{
    struct string *new_string;
    char data[] = "this is new version";
    struct string *myString = makeString("this is new version");

    printf("Len is : %d", stringLen(myString));
     printf("char is : %c", stringCharAt(myString, 2));

   // printf("test variable :%s\n", new_string->length);

}



/*int main()
{
    struct string s;
    struct string *sp;

    sp = &s;

    s.length = 4l;
    s.data = "This is more than four";

    puts(s.data);
    puts(sp->data);
    puts((*sp).data);


    printf("test variable :%d\n", returnVar());
    return 0;
}
*/
