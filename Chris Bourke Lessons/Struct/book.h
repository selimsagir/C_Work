
/**
  *  This models Date Person and Book
 */


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


char *deepStringCopy(const char *s) ;

Book *createBook(const char *isbn, 
	const char *title,
	const char *authorFirstname,
	const char *authorLastName,
	const int numberOfPages);

void freeBook(Book *b);
char *bookToString(const Book *b);
void printBook(const Book *b);
void initBook( Book *b,
	const char *isbn, 
	const char *title,
	const char *authorFirstname,
	const char *authorLastName,
	const int numberOfPages);

// TODO create a printBooks function

void printBooks(const Book *b, int size);
