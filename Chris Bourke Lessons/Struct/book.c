#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "book.h"


char *deepStringCopy(const char *s) {
	char *c = (char *)malloc ((strlen(s)+1) * sizeof(char));
	strcpy(c,s);
	return c;
}

Book * createBook(const char *isbn, 
	const char *title,
	const char *authorFirstname,
	const char *authorLastName,
	const int numberOfPages) {
	
	Book *b = (Book *)malloc(sizeof(Book));
	initBook(b,isbn,title, authorFirstname,authorLastName, numberOfPages);
  
    return b;
}
// TODO: change to return type to int and do error handling

void initBook( Book *b,
	const char *isbn, 
	const char *title,
	const char *authorFirstname,
	const char *authorLastName,
	const int numberOfPages) {

	b->numberOfPages = numberOfPages;
    b->isbn = deepStringCopy(isbn);
	b->title = deepStringCopy(title);
	b->author.lastName = deepStringCopy(authorLastName);
	b->author.firstName = deepStringCopy(authorFirstname);
	return;
}



void freeBook(Book *b) {
	free(b->isbn);
	free(b->title);
	free(b->author.firstName);
	free(b->author.lastName);
	free(b);
}

char * bookToString(const Book *b) {
	char temp[1000];
	sprintf(temp,"%-30s by %-15s, %s\n", b->title, b->author.lastName,b->author.firstName);
	return deepStringCopy(temp);
}

void printBook(const Book *b) {
	char *s = bookToString(b);
	printf("%s\n",s);
	
	return;
}

void printBooks(const Book *b, int size) {

	// b is... Book * (a pointer to Book!)
	//b[i]  is a ... Book(a regular structure)
	//%b[i] is a pointer to the i-th book!
	for (int i = 0; i < size; i++)
	{
		
		printBook(&b[i]);
	}
	


}