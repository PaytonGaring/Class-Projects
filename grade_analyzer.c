/*
* Author: Payton Garing
* Course: Computer Science 1
* Assignment: Grade Analyzer
* Date: Spring 2025
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char first[30], last[30];
    int score;
    struct Student* next;
    } Student;

Student* createNode(char *lastName, char *firstName, int score){
    Student* newNode = malloc(sizeof(Student));
        if(newNode == NULL){
            printf("Memory allocation error");
            return NULL;
        }
    // insert scanned values into Struct Node
    newNode->score = score;
    strcpy(newNode->last, lastName);
    strcpy(newNode->first, firstName);
    newNode->next = NULL;
    
    return newNode;
    }   
// merge sort functions
void merge(Student *array, int low, int mid, int high) // fix
{
    int leftSize = mid - low + 1;
    int rightSize = high - mid;
    
    // allocate memory for temporary student arrays
    Student *leftArray = malloc(sizeof(Student) * leftSize);
    Student *rightArray = malloc(sizeof(Student) * rightSize);
    
    for (int i = 0; i < leftSize; ++i)
    leftArray[i] = array[low + i];
    
    for (int j = 0; j < rightSize; ++j)
    rightArray[j] = array[mid + 1 + j];
    
    // temp array indexed
    int i = 0; 
    int j = 0; 
    int k = low; 
    // Merge arrays
    while (i < leftSize && j < rightSize){
    if (leftArray[i].score <= rightArray[j].score)
            {
            array[k] = leftArray[i];
            i++;
            }
    else    {
            array[k] = rightArray[j];
            j++;
            }
        k++;
    }

    while (i < leftSize){
        array[k] = leftArray[i];
        i++;
        k++;
    }
    
    while (j < rightSize){
        array[k] = rightArray[j];
        j++;
        k++;
    }
    // free temporary arrays
    free(leftArray);
    free(rightArray);
}
Student* convertToArray(Student *head, int *size){
    Student* current = head;
    int count = 0;
    // traverse array to count elements
    while(current != NULL){
        count++;
        current = current->next;
    }
    *size = count;
    // allocate and create struct array
    Student* students = malloc(sizeof(Student) * count);
    current = head;
    for(int i = 0; i < count; i++){
        students[i] = *current;
        current = current->next;
    }
    // returns struct array
    return students;

}
void sortStudents(Student *array, int low, int high){
    // nlogn sort

    if (low < high)
    {
    // middle of subarray
    int mid = (low + high) / 2;
    // Sort first half and second half with recursion
    sortStudents(array, low, mid);
    sortStudents(array, mid + 1, high);

    // Merge two halves of the sorted arrays
    merge(array, low, mid, high);
}
}

// Calulcation functions
double averageGrade(Student *students, int size){
    int totalScore = 0;
    double average = 0;
    for(int i =0; i< size; i++){
        totalScore += students[i].score;
    }
    average = totalScore / (double)size;
    return average;
}
double medianStudent(Student *students, int size){
    int count = 0;
    int length = 0;
    int median = 0;
    double medianScore= 0;
    
    // if size is even add up to "middle" values and divide by 2
    if(size % 2 == 0){
        return (students[size / 2 - 1].score + students[size / 2].score) / 2.0;
    } else {
        // if odd return median value
        return students[size / 2].score;
    }
}

int highScore(Student *students, int size){
    return students[size-1].score;
}
int lowScore(Student *students, int size){
    return students[0].score;
}


int main(){
    Student *head = NULL;
    char lastName[30];
    char firstName[30];
    char input[50];
    int score = 0;
    int size = 0;

    printf("Enter input file name: ");
    scanf("%s", input);

    FILE *inputFile = fopen(input, "r");
    if (inputFile == NULL){
        printf("Input File error");
        return 1;

    }
    // scan in student information to struct node
    while(fscanf(inputFile, "%s %s %d", lastName, firstName, &score) != EOF)
    {
        Student *newNode = createNode(lastName, firstName, score);
        newNode->next = head;
        head = newNode;
        // calculate size for later functions
        size++;
    }
    fclose(inputFile);
    
    Student *students = convertToArray(head, &size);
    int highestScore = 0;
    int lowestScore = 0;
    int MedianScore = 0;
    int ClassAverage = 0;
    // merge sort student grade information 
    sortStudents(students, 0, size - 1);
    /*list in descending order so traverses and prints list in reverse*/
    printf("Sorted list by Score:\n");
    for (int i = size - 1 ; i > 0; i--) { 
        printf("%s %s - %d \n", students[i].last, students[i].first ,students[i].score);
    }

    highestScore = highScore(students, size);
    lowestScore = lowScore(students, size);
    MedianScore = medianStudent(students, size);
    ClassAverage = averageGrade(students, size);
    // prints out associated scores
    printf("\nHighest Score: %d\n", highestScore);
    printf("Lowest Score: %d\n", lowestScore);
    printf("Median Score: %d\n", MedianScore );
    printf("Class Average: %d\n", ClassAverage);

    printf("\n");
    printf("Top 5 Students:\n");
    for (int i = size - 1; i > size - 6; i--) {
        printf("%s %s - %d \n", students[i].last, students[i].first ,students[i].score);
    }
   
}
