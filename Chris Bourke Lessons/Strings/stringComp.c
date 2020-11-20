#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{

	char a[] = "apple";
	char b[] = "banana";
	int r = strcmp(a,b);
	if(r < 0) {
		printf("%s comes before %s\n",a,b );
	} else if(r > 0) {
		printf("%s comes before %s \n", b, a);
	} else {
		printf("%s and %s are equal! \n",a, b );
	}
	return 0;
}