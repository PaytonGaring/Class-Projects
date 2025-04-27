/*
* Author: Payton Garing
* Course: Computer Science 1
* Assignment: Dynamic Library
* Date: Spring 2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// Book struct declaration
typedef struct book
{
    char* bookTitle;
    char* author;
    int publicationYear;

}
Book;

int main(){
    int bookCount = 0;
    printf("Enter the number of books:\n");
    scanf("%d", &bookCount);
    getchar();
    // Allocate memory in heap for array of book structs
    Book* book = malloc(sizeof(Book) * bookCount);
    
    if (book == NULL){
        printf("Memory Allocation error");
        exit(1);
    }

    // for loop that takes input for book details n times
    for (int i = 0; i < bookCount; i++){
        // Allocate memory for each book title in book array
        book[i].bookTitle = malloc(sizeof(char) * 100);

        if (book[i].bookTitle == NULL){
            printf("Error allocating memory for book titles");
        }
        // Allocate memory for each book's author in book array
        book[i].author = malloc(sizeof(char) * 100);

        if (book[i].author == NULL){
            printf("Error allocating memory for book authors");
        }

        printf("Enter details for book %d:\n", i + 1);
        printf("Title:\n");
        fgets(book[i].bookTitle, 100, stdin);

        // Replaces newline character with null terminator
        book[i].bookTitle[strcspn(book[i].bookTitle, "\n")] = '\0';

        // Empty title case
         if (strlen(book[i].bookTitle) == 0) {
            book[i].bookTitle[0] = '\0';
         }
        
        printf("Author:\n");
        fgets(book[i].author, 100, stdin);

        // Replaces newline character with null terminator
        book[i].author[strcspn(book[i].author, "\n")] = '\0';

        // Empty author case
         if (strlen(book[i].author) == 0) {
            book[i].author[0] = '\0';
         }

        printf("Year:\n");
        scanf("%d", &book[i].publicationYear);
        getchar();
        
    }
    // Sorts array in ascending order by publication year
    for (int i = 0;  i < bookCount - 1; i++){
        // Inner Loop iterations decrease every time outer loop runs
        for (int j = 0; j < bookCount - i - 1; j++){
            if (book[j].publicationYear > book[j + 1].publicationYear){
            // Swap current book with neighboring book
            Book temp = book[j];
            book[j] = book[j + 1];
            book[j + 1] = temp;
            }
        }
    }
    
    printf("Library Inventory (Sorted by Year of Publication): \n");
    // Print each book's details in ascending year order
    for (int i = 0; i < bookCount; i++){
        printf("%d. Title: %s\n", i+1,  book[i].bookTitle);
        printf("Author: %s\n", book[i].author);
        printf("Year: %d\n", book[i].publicationYear);
        printf("\n");
    }

    // Frees memory allocated for each book's author and title
    for (int i = 0; i < bookCount; i++){
        free(book[i].bookTitle);
        free(book[i].author);
    }

    // Frees memory allocated to book struct array
    free(book);

    return 0;
}

