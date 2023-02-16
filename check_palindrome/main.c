#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool check_polindrome(char *string);

int main()
{
    char string1[] = "Selim"; // not polindrome
    char string2[] = "abccba";
    char string3[] = "abcddbca";

    bool ret;

    ret = check_polindrome(&string1);
    printf("Result is %d\n", ret);
    ret = check_polindrome(&string2);
    printf("Result is %d\n", ret);
    ret = check_polindrome(&string3);
    printf("Result is %d\n", ret);
    return 0;
}



bool check_polindrome(char *string){

    printf("String: %s Size: %d\n", string, strlen(string));
    int counter = 0 ;
    char temp;
    for(int i = 0; i < strlen(string)/2; i++){
        if(string[i] != string[strlen(string)-i-1])
            return false;
        else return true;

    }

}
