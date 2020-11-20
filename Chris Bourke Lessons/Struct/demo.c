#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "book.h"


//TODO: create a printBooks function

int main(int argc, char const *argv[])
{
	Book b1, b2, b3;
	initBook(&b1,"1233-32131321312","Shakesper for Squirrels","Christopher","Moore",270);
	initBook(&b2,"232-123213123", "1984", "George", "Orwell", 540);
	initBook(&b3,"1234","Illiad","Homer","Something",100);
	
/*
	int n = 3;
	Book *library = (Book *) malloc(sizeof(Book)*n);
	library[0] = b1;
	library[1] = b2;
	library[2] = b3;
*/
	int n = 3; 
	Book **libraryOfPointers = (Book **) malloc(sizeof(Book*) *n);

	libraryOfPointers[0] = &b1;
	libraryOfPointers[1] = &b2;
	libraryOfPointers[2] = &b3;
	// library of pointers is a Book ** 
	// libraryOfPointers[0] is a Book *
	// b1 is a Book 

	

	printBooks(library ,n);


	return 0;
}