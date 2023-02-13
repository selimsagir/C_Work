#include <stdio.h>
#include <stdlib.h>



int char_occurance(char *string, char c);

int main()
{
    int number = 0;
    char test[] = "Some characters in the string.";
    number = char_occurance(test, 'L');
    printf("Occurence is: %d ", number);
    return 0;
}



int char_occurance(char *string, char c){

    if ( *string == '\n')
        return 0;
    else if (*string == c)
        return 1 + char_occurance(string + 1, c);
    else
        return char_occurance(string + 1, c);
}
