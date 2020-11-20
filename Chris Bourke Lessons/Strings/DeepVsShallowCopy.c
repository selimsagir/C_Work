#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** 
 * Creates a new deep copy of the given string
 * and returns the new string
 */
char * deepStringCopy(const char *src) {
	if (src == NULL) {
		return NULL;
	}
char *copy = (char *) malloc(sizeof(char) * (strlen(src) + 1));
strcpy(copy,src);
return copy;
}


int main(int argc, char const *argv[])
{
	

	char *name = (char*)malloc(sizeof(char) * 100);

	strcpy(name, "Christopher");

	char * correctedName = deepStringCopy(name);

	printf("original = %s\n",name );
	printf("Copy = %s\n",correctedName);

	correctedName[0] = 'x';

	printf("original = %s\n",name );
	printf("Copy = %s\n",correctedName);	

	return 0;
}