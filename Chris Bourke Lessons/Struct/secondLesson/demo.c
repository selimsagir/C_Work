#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct 
{
	int year;
	int month;
	int day;
} Date;

typedef struct 
{
	char *firstName;
	char *lastName;
	Date dateOfBirt;
} Person;

typedef struct 
{
	char *isbn;
	char *title;
	Person author;  //TODO : reconsider
	int numberOfPages;
	Date publishDate; // format year, mont day
} Book ;

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
	b->numberOfPages = numberOfPages;
    b->isbn = deepStringCopy(isbn);
	b->title = deepStringCopy(title);
	b->author.lastName = deepStringCopy(authorLastName);
	b->author.firstName = deepStringCopy(authorFirstname);
	return b;
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

int main(int argc, char const *argv[])
{
	Book *b1 = createBook("1233-32131321312","Shakesper for Squirrels","Christopher","Moore",270);
	Book *b2 = createBook("232-123213123", "1984", "George", "Orwell", "540");
	Book *b3 = createBook("1234","Illiad","Homer","Something",100);
	
	Book *library = (Book *) malloc(sizeof(Book) * 3);
	library[0] = *b1;
	library[1] = *b2;
	library[2] = *b3;
	printBook(b1);
	printBook(b2);
	printBook(b3);



	freeBook(b1);
	freeBook(b2);
	freeBook(b3);
	return 0;
}