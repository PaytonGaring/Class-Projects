// Payton Garing
// Dr. Steinberg
// Section 001
// Large Program 3

#include <string.h>
#include <stdio.h>
#include <ctype.h>

//function prototypes
void maskWord (char starword[], int size); //mask word with stars to display
int playRound(char starword[], char answer[]); //play a round of hangman
int occurencesInWord(char userGuess, char answer[]); //times letter occurs in word
void updateStarWord(char starword[], char answer[], char userguess); //replace respective *
int guessTheWord(char answer []); //guess the word
void playAgain(int *play); //ask user to play again
void chomp(char word []);
void clearBuffer();

int main()
{
    //greeting/rules
    printf("Welcome to the Hangman Game!\n");
    printf("************************************************************************\n");
    printf("Here are the rules.\n");
    printf("I will provide you a set of * characters for each round.\n");
    printf("Each * represents a letter in the English Alphabet.\n");
    printf("You must figure out each letter of the missing word.\n");
    printf("For every correct letter guessed, I will reveal its place in the word.\n");
    printf("Each mistake will result in a strike.\n");
    printf("6 strikes will result in a loss that round.\n");
    printf("Are you ready? Here we go!\n");
    printf("************************************************************************\n");
    

    FILE * fptr;
    fptr = fopen("words.txt", "r");

    int play = 1;
    char answer[20];
    char starword[20];
    int win = 0;

    while(play == 1)
    {
    //scan respective word/answer for each round
    fscanf(fptr, "%s", answer);
    //loop to make sure newline isn't in string
    for(int i = 0; i < strlen(answer); i++)
        {
        if(!isalpha(answer[i]))
            {
                answer[i] = '\0';
            }
         }

    chomp(answer);
    int size = strlen(answer);
    strcpy(starword, answer);
    maskWord(starword, size);
    
    //determines if user won round or not
    win = playRound(starword, answer);

    

    if(win == 1)
    {
        printf("Congratulations! You won! The word was %s.\n", answer);
    }
    else if (win == 0)
    {
        printf("************************************************************************\n");
        printf("Sorry you did not win the round. The word was %s.\n", answer);
    }
    
    clearBuffer();
    //ask user to play another round 
    playAgain(&play);
    }

    fclose(fptr);
    return 0;
}


int playRound(char starword[], char answer[])
{
    int strikes = 0;
    char userguess = '\0';
    int won = 0;
    int correct = 0;
    char letters[50] = "";
    int conCount = 0;
    int size = strlen(answer);
    int i = 0;
    
    //round greeting
    printf("Welcome to the Round!\n");
    printf("The size of the word has %d letters.\n", size);

    // round components that repeat
    while(won <= 0 && strikes != 6) 
    {
        // displays strikes and guessed letters
        printf("\nYou currently have %d strike(s).\n", strikes);
        printf("letters you have guessed: %s\n", letters);

        printf("\n%s\n", starword);

        printf("\nEnter your guess:");
        scanf("%c", &userguess);
        clearBuffer();
        //stores user's guesses into array 
        letters[i] = userguess;
        i++;
        letters[i] = '\0';

        //checks if guessed letter is in answer
        correct = occurencesInWord(userguess, answer);
        //updates *s with correctly guessed letters
        updateStarWord(starword, answer, userguess);

        //if guessed letter not in answer user is striked
        if(correct >= 1)
        {
            printf("\nThe letter %c is in the word.\n", userguess);
            printf("\n%s\n", starword);
            conCount++;
        }
        else
        {
            printf("\nThe letter %c is NOT in the word.\n", userguess);
            printf("\n%s\n", starword);
            strikes++;
            conCount = 0;
        }

        /* if user has 2 consecutive correct guesses
        user is prompted to guess full word
        if  matches answer, user wins round
        */
        if((conCount % 2 == 0) && (conCount != 0))
        {
            won = guessTheWord(answer);
            if(won == 1)
            {
                return 1;
            }
        }

        // user loses after 6 strikews
        if(strikes == 6)
        {
            return 0;
        }
    }
}

void maskWord(char starword[], int size)
{
    for(int i = 0; i < size; i++)
    {
        starword[i] = '*';
    }
}


int occurencesInWord(char userguess, char answer[])
{
    int count = 0;
    //counts # of times a guessed char occurs 
    for (int i = 0; i < strlen(answer); i++)
    {
        if(tolower(answer[i]) == tolower(userguess))
        {
            count++;
        }
    }
    return count;
}

void updateStarWord(char starword[], char answer[], char userguess)
{
    //loop to make correct chars visible
    for(int i = 0; i < strlen(starword); i++)
    {
    if(tolower(answer[i]) == tolower(userguess))
        {
            starword[i] = tolower(userguess);
        }
    }
}

int guessTheWord(char answer[])
{
    int willGuess = 0;
    char guess[20];

    printf("You have made at least 2 consecutive correct guesses. Would you like to\n");
    printf("guess the word (0 for no and 1 for yes):\n");
    scanf("%d", &willGuess);
    clearBuffer();
    //compares user guess, if same return 1 for win
    if (willGuess == 1)
    {
        printf("Enter your guess:\n");
        fgets(guess, 20, stdin);
        chomp(guess);
        if(strcmp(guess, answer) == 0)
        {
            return 1;
        }
        else
        {
            printf("Sorry. That is not the word.\n");
            return 0;
        }
    }
}

void playAgain(int *play)
{
    // prompt user to play agian
    int choice;
    printf("************************************************************************\n");
    printf("Would you like to play another round?\n");
    printf("1: Yes\n");
    printf("2: No\n");
    printf("Choice:\n");
    scanf("%d", &choice);
    clearBuffer();
    printf("************************************************************************\n");
    // ends program if 0, repeats program if 1
    if(choice == 1)
    {
        *play = 1;
    }
    else
    {
        printf("Thank you for playing today!\n");
        *play = 0;
    }
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