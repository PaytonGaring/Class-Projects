// Payton Garing
// Dr. Steinberg
// Section 001
// Large Program 4

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct{

    char name[25];
    double hwAvg;
    double qAvg;
    double eAvg;
    int id;

}student_t;

//function prototypes
void addStudent(student_t grades[], int *curStudent);
void removeStudent(student_t grades[], int *curStudent);
void updateStudent(student_t grades[], int curStudent);
void printStudent(student_t grades[], int *curStudent);
void missingStudent(student_t grades[], int *curStudent);
void displayStudent(student_t grades[], int curStudent);
void chomp(char word[]);
void clearBuffer();



int main()
{
    student_t grades[5];
    int curStudent = 0;
    char choice = 'h';
    printf("Welcome to your gradebook management system!\n");

    //repeats menu selection
    while(tolower(choice) != 'e')
    {
        printf("************************************\n");
        printf("What would you like to do in the gradebook?\n");
        printf("A: Add a Student to the Gradebook\n");
        printf("R: Remove a Student from the Gradebook\n");
        printf("P: Print Grades from the Gradebook\n");
        printf("U: Update a Student's Grade\n");
        printf("M: Determine who is missing Grades\n");
        printf("D: Display all names and associated IDs.\n");
        printf("E: Exit\n");
        printf("************************************\n");
        printf("Selection: \n");
        scanf("%c", &choice);
        clearBuffer();

        //switch values to call respective function
        switch(choice)
        {
            case 'A':
            case 'a':
            addStudent(grades, &curStudent);
            break;
            case 'R':
            case 'r':
            removeStudent(grades, &curStudent);
            break;
            case 'P':
            case 'p':
            printStudent(grades, &curStudent);
            break;
            case 'U':
            case 'u':
            updateStudent(grades, curStudent);
            break;
            case 'M':
            case 'm':
            missingStudent(grades, &curStudent);
            break;
            case 'D':
            case 'd':
            displayStudent(grades, curStudent);
            break;
            case 'E':
            case 'e':
            printf("Exiting the Gradebook System and exporting all records into a file called\n");
            printf("gradebook.txt\n");
            break;
        }
    }
    return 0;
}

void chomp(char word [])
{
    //removes newline characters from strings
	if(word[strlen(word) - 1] == '\n')
    {
	    word[strlen(word) - 1] = '\0';
    }
}

void clearBuffer()
{
    //clears input buffer string
    int c;
	while((c = getchar()) != '\n' && c != EOF);
}

void addStudent(student_t grades[], int *curStudent)
{
    int spaces = 0;
    int id = 0;

    //inputs student name and sets grades to 0
    if(*curStudent < 5)
    {
        printf("Enter the Student's Full Name: \n");
        fgets(grades[*curStudent].name, sizeof(grades[*curStudent].name), stdin);
        chomp(grades[*curStudent].name);
        grades[*curStudent].id = rand() % 98;
        (*curStudent)++;
        grades[*curStudent].hwAvg = 0.0;  
        grades[*curStudent].qAvg = 0.0;
        grades[*curStudent].eAvg = 0.0;
    }
    else
    {
        printf("Your gradebook is full!\n");
    }
}

void removeStudent(student_t grades[], int *curStudent)
{
    int idCheck = 0;
    int found = 0;
    printf("Here are the list of students and their IDs.\n");

    //prints student names and respectives grades
    for(int i = 0;i < *curStudent; i++)
    {
        printf("Name: %s\tID: %d\n", grades[i].name, grades[i].id);
    }

    printf("Enter the ID of the student to remove: \n");
    scanf("%d", &idCheck);
    
    if(idCheck <= 0 || idCheck >= 100)
    {
        printf("Invalid ID");
    }

    // traverse struct array to remove student
    for(int i = 0; i < *curStudent; i++)
    {
        if(idCheck == grades[i].id)
        {
            printf("Removing %s from the gradebook.\n", grades[i].name);
            for (int j = i; j < *curStudent - 1; j++) 
            {
                grades[j] = grades[j + 1];
            }
            (*curStudent)--;
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("Student not found.\n");
    }
}

void displayStudent(student_t grades[], int curStudent)
{
    printf("Here are the list of students and their IDs.\n");

    // displays student names and respective grades
    for(int i = 0; i < curStudent; i++)
    {
        printf("Name: %s\tID:%d\n", grades[i].name, grades[i].id);
    }
}

void updateStudent(student_t grades[], int curStudent)
{
    int idCheck2 = 0;
    int found = 0;
    printf("Here are the list of students and their IDs.\n");

    for(int i = 0; i < curStudent; i++)
    {
        printf("Name: %s\tID:%d\n", grades[i].name, grades[i].id);
    }

    printf("Enter the ID of the student: \n");
    scanf("%d", &idCheck2);

    // loop to enter grades for student
    for(int i = 0; i < curStudent; i++)
    {
        if(idCheck2 == grades[i].id)
        {
            found = 1;
            printf("You are about to update the grades entered for %s.\n", grades[i].name);
            printf("Please enter the respective score for each assessment group.\n");
            printf("Enter the overall homework average: \n");
            scanf("%lf", &grades[i].hwAvg);
            printf("Enter the overall quiz average: \n");
            scanf("%lf", &grades[i].qAvg);
            printf("Enter the overall exam average: \n");
            scanf("%lf", &grades[i].eAvg);
            printf("Success! %s's grades entered are now updated in your gradebook!\n", grades[i].name);
        }
        if(found == 0)
        {
            printf("Student not found.\n");
        }
    }
}

void printStudent(student_t grades[], int *curStudent)
{
    /* 
    displays students names and grades
    to console and to a seperate file
    */
    for(int i = 0; i < *curStudent; i++)
    {
        if(grades[i].hwAvg != 0.00)
        {
            FILE *fptr = fopen("gradebook.txt", "a");
            double weightedAvg = (grades[i].hwAvg * .5) + (grades[i].qAvg * .2) + (grades[i].eAvg * .3);

            printf("------------------------------------------------------\n");
            printf("Name: %s\n", grades[i].name);
            printf("ID: %d\n", grades[i].id);
            printf("Homework Average: %.2lf\n", grades[i].hwAvg);
            printf("Quiz Average: %.2lf\n", grades[i].qAvg);
            printf("Exam Average: %.2lf\n", grades[i].eAvg);
            printf("Weighted Average: %.2lf\n", weightedAvg);
            printf("------------------------------------------------------\n");
            
            fprintf(fptr, "Name: %s\n", grades[i].name);
            fprintf(fptr, "ID %d\n", grades[i].id);
            fprintf(fptr, "Homework Average: %.2lf\n", grades[i].hwAvg);
            fprintf(fptr, "Quiz Average: %.2lf\n", grades[i].qAvg);
            fprintf(fptr, "Exam Average: %.2lf\n", grades[i].eAvg);
            fprintf(fptr, "Weighted Average: %.2lf\n", weightedAvg);
            fprintf(fptr, "------------------------------------------------------\n");
            fclose(fptr);
        }
        else
        {
            printf("%s does not have all grades entered entered yet.\n", grades[i].name);
            printf("------------------------------------------------------\n");
        }
    }
}

void missingStudent(student_t grades[], int *curStudent)
{
        printf("The following students have missing grades not entered into the book.\n");
        printf("---------------------------------------\n");

        // checks to see if students grade have change
        for(int i = 0; i < *curStudent; i++)
        {
            if(grades[i].hwAvg == 0.0)
            {
                printf("%s\n", grades[i].name); 
            }
        }
}

