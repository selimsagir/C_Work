#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{

//open a file using a relative path:
FILE *in =fopen("data.txt","r");

char c = fgetc(in);
while(c != EOC) {
	printf("read : %s\n", c);
	c = fgetc(in);
}

fclose(in);
//open a file using an absolute path:
//FILE *in =fopen("/etc/passwd","r");

// if it fails to open, NULL is return
if (in == NULL){
	printf("failed to open file\n");
}
{
	/* code */
}

return 0;
}