#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	char data[] = "Chris, Bourke,1232131,Omaha,NE,130, Schort";
	char *token =strtok(data, ",");
	int numTokens = 0;
	printf("token = %s\n",token );
	while(token != NULL) {
		printf("token = %s\n",token );
		numTokens++;
		token = strtok(NULL,",");
	}
	if(numTokens != 6) {
		printf("bad data!\n");
	}
/*
	token = strtok(NULL, ",");
	// pass the NULL for pass to next string, here is Bourke
	printf("token = %s\n",token );
*/
	return 0;
}