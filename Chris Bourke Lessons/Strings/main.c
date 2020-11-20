#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	/*
	char name[] = "Selim";
	printf("Hello %s\n",name);
	name[0] = 's';
	printf("Hello,%s\n",name );
	name[2] = '\0';  //se
	printf("%s\n",name);
	*/

	// create a dynamic string big enough to hold "Christopher"
	char *name = (char*)malloc(sizeof(char) * 12);
	// 11 karakter ve null terminated karakter 12 eder.
	strcpy(name, "Christopher");


	printf("Hello %s\n",name );

	int count = 0;
	int i = 0;
	while(name[i] != '\0') {
		count++;
		i++;
	}

	printf("the string '%s' is %d characters long\n",name,count );
	return 0;
}