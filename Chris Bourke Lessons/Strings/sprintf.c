#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	char firstName[] = "Selim"; 
	char lastName[] = "Sagir";
	char buffer[100];
	sprintf(buffer, "%s,%s",lastName,firstName);
	char *fullname = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
	strcpy(fullname,buffer);
	printf("Hello, %s\n",fullname );

	return 0;
}