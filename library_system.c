/*
* Author: Payton Garing
* Course: Computer Science 1
* Assignment:  Library System
* Date: Spring 2025
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TITLE 100
#define MAX_NAME 50

typedef struct node{

    char title[MAX_TITLE];
    char lastName[MAX_NAME];
    char firstName[MAX_NAME];


    struct node* next; 

} node_t;


// Function prototypes
node_t *borrowBook(node_t *head, char *title, char *lastName, char *firstName, FILE *output);
node_t *returnBook(node_t *head, char *title, char *lastName, char *firstName, FILE *output);
node_t* createNode(char *title, char *lastName, char *firstName);
void checkBook(node_t *head, char *title, char *lastName, char *firstName, FILE *output);
void displayBorrowedBooks(node_t *head, FILE *output);
void freeList(node_t *head, FILE *output);
// Hint: To read the book title, author's first name, and author's last name,
// you can use:
// fscanf(file, " \"%[^\"]\" %s %s", bookTitle, lastName, firstName);
// Alternatively, you can use fgets() to read the entire line and then parse it.


int main(){
    // variable declarations
    char bookTitle[MAX_TITLE];
    char lastName[MAX_NAME];
    char firstName[MAX_NAME];
    int operation = 0;
    node_t *head = NULL;

    // Open files to read and write
    FILE *input = fopen("library_records.txt", "r");
    if (input == NULL){
        printf("Input File error");
        return 1;
    }
    
    FILE *records = fopen("output.txt", "w");
    if (records == NULL){
        printf("records file error");
        return 1;
    }
    
    // scan and allocate file content for each line 
    while(fscanf(input, "%d \"%[^\"]\" %s %s", &operation, bookTitle, lastName, firstName) != EOF)
    {
        // switch statement to call each specified function
        switch(operation){
        case 1:
            head = borrowBook(head, bookTitle, lastName, firstName, records);
            break;
        case 2:
            head = returnBook(head, bookTitle, lastName, firstName, records);
            break;
        case 3:
            checkBook(head, bookTitle, lastName, firstName, records);
            break;
        case 4:
            displayBorrowedBooks(head, records);
            break;
        case 5:
            freeList(head, records);
            fclose(input);
            fclose(records);
            exit(0);
            break;
        default:
            fprintf(records, "invalid operation");
            break;
        }
    }
    fclose(input);
    fclose(records);
    return 0;
}

node_t* createNode(char *title, char *lastName, char *firstName){
    node_t* newNode = malloc(sizeof(node_t));
    if(newNode == NULL){
        printf("Memory allocation error");
        return NULL;
    }
    // copy scanned content into node
    strcpy(newNode->title, title);
    strcpy(newNode->lastName, lastName);
    strcpy(newNode->firstName, firstName);
    newNode->next = NULL;

    return newNode;
}

node_t *borrowBook(node_t *head, char *title, char *lastName, char *firstName, FILE *output){
    // add borrowed book into linked list of records
    node_t *newNode = createNode(title, lastName, firstName);
    newNode->next = head;
    head = newNode;

    fprintf(output, "Borrowed \"%s\" by %s, %s\n", title, lastName, firstName);
    return newNode;
}

node_t *returnBook(node_t* head, char *title, char *lastName, char *firstName, FILE *output){
    node_t* current = head;
    node_t* previous = NULL;

    while (current != NULL){
        if(strcmp(current->title, title) == 0 && strcmp(current->lastName, lastName) == 0)
        {
            // If book is head node (remove head)
            if(previous == NULL){
                head = current->next;
            } else {
            // link previous node to current's next node to remove
                previous->next = current->next;
            }

            free(current);

            fprintf(output, "Returned \"%s\" by %s, %s\n", title, lastName, firstName);
            return head;
        }
        previous = current;
        current = current->next;
    }

    fprintf(output, "Returned \"%s\" not in the library records \n", title);
    return head;
}

void checkBook(node_t *head, char *title, char *lastName, char *firstName, FILE *output){
    node_t* current = head;
    int bookCheck = 0;

    // traverse book records list
    while (current != NULL){
    // stops and prints borrower's name once book found
        if(strcmp(current->title, title) == 0 && strcmp(current->lastName, lastName) == 0){
            fprintf(output, "\"%s\" is borrowed by %s, %s\n", title, current->lastName, current->firstName); 
            bookCheck = 1;
            break;
        }
        current = current->next;
    }
    if(bookCheck == 0){
        fprintf(output, "\"%s\" is not currently borrowed by %s, %s\n", title, lastName, firstName);
    }
}

void displayBorrowedBooks(node_t *head, FILE *output){
    node_t* current = head;
    int index = 1;

    // print out book records
    fprintf(output,"Borrowed Books List:\n");
    
    while (current != NULL)
    {
        fprintf(output, "%d. \"%s\" - %s, %s \n", index, current->title, current->lastName, current->firstName);
        index++;
        current = current->next;
    }
}

void freeList(node_t *head, FILE *output){
    node_t *current = head;
    node_t *next;
    
    // free each book from the records
    while(current != NULL){
     next = current->next;
        free(current);
        current = next; 
    }
    fprintf(output, "Thank you for using the Library System!");
}