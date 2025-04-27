// Payton Garing
// Dr. Steinberg
// Section 001
// Small Program 7

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// function prototypes
void lastWordLength(char sentence1[]);
void clearBuffer();
void chomp(char word []);
void truncateSentence(char sentence2[], int n);
int strongPasswordCheck(char password[]);
int romanNumber(char roman[]);

int main()
{
    // problem 1
    char sentence1[500];
    printf("Enter a sentence: ");
    fgets(sentence1, 500, stdin);
    chomp(sentence1);
    lastWordLength(sentence1);

    // problem 2
    char sentence2[500];
    int n = 0;
    printf("Enter a sentence: ");
    fgets(sentence2, 500, stdin);
    chomp(sentence2);

    printf("Truncate sentence to how many words: ");
    scanf("%d", &n);
    truncateSentence(sentence2, n);
    clearBuffer();
    printf("Truncated sentence is \"%s\"\n", sentence2);

    // problem 3
    char password[100];
    printf("Enter your password: ");
    fgets(password, 100, stdin);
    chomp(password);

    int strongPass = strongPasswordCheck(password);
    // if statement to determine password is strong
    if(strongPass == 1)
    {
        printf("%s is a strong password.\n", password);
    }
    else
    {
        printf("%s is not a strong password.\n", password);
    }

    // problem 4
    char roman[30];
    printf("Enter a roman numeral: ");
    fgets(roman, 30, stdin);
    chomp(roman);

    int romanNum = romanNumber(roman);
    printf("%s = %d\n", roman, romanNum);
    return 0;
}

void lastWordLength(char sentence1[])
{
    int length = strlen(sentence1);
    int i = length - 1;
    int wordLength = 0;

    // loop that counts down until end of a word
    while(i >= 0 && ispunct(sentence1[i]) || sentence1[i] == ' ')
    {
        i--;
    }

    // loop to count characters in last word
    while(i >= 0 && sentence1[i] != ' ')
    {
        wordLength++;
        i--;
    }

    printf("Length of last word in \"%s\" is %d.\n", sentence1, wordLength);
}

void clearBuffer()
{
	while(getchar() != '\n');
}

void chomp(char word [])
{
	if(word[strlen(word) - 1] == '\n')
    {
	word[strlen(word) - 1] = '\0';
    }
}


void truncateSentence(char sentence2[], int n)
{
    int wordCount = 0 ;

    // loop to traverse string (left to right)
    for(int i = 0; i < strlen(sentence2); i++)
    {
         // counts a word for every whitespace
         if(sentence2[i] == ' ')
         {
            wordCount++;
         }

         // executes when finds desired amount of words(n)
         if (wordCount == n)
         {
            // loop to make sure word isn't cut short
            while (i < strlen(sentence2) && sentence2[i] != ' ')
            {
                i++;
            }
            // inserts null character to truncate sentence
            if (i < strlen(sentence2))
            {
                sentence2[i] = '\0';
                break;
            }
        }
    } 
}


int strongPasswordCheck(char password[])
{
    int charCount = 0;
    int upperCount = 0;
    int lowerCount = 0;
    int digitCount = 0;
    int repeatCount = 0;
    
    // loop to count necessary strong password components
    for(int i = 0; i < strlen(password); i++)
    {
        if (tolower(password[i]) == tolower(password[i+1]))
        {
            repeatCount++;
        }

        if(password[i] != ' ')
        {
            charCount++;
        }

        if(isdigit(password[i]))
        {
            digitCount++;
        }

        if(islower(password[i]))
        {
            lowerCount++;
        }

        if(isupper(password[i]))
        {
           upperCount++;
        }
    }
    // returns if string met strong password requirements
    if(charCount >= 6 && charCount <= 20 && digitCount >= 3 && lowerCount >= 1 && upperCount >= 2 && repeatCount < 2)
    {
        return 1; 
    }
    else 
    {
        return 0;
    }
}

int romanNumber(char roman[])
{
    int total = 0;

    for(int i = 0; i < strlen(roman); i++)
    {
        // adding roman numerals that require subtraciton
        if(roman[i] == 'I' && roman[i+1] == 'V')
        {
            total += 4;
            i++;
        }   
        else if(roman[i] == 'I' && roman[i + 1] == 'X')
        {
            total += 9;
            i++;
        }
        else if(roman[i] == 'X' && roman[i+1] == 'L')
        {
            total += 40;
            i++;
        }
        else if(roman[i] == 'X' && roman[i+1] == 'C')
        {
            total += 90;
            i++;
        }
        else if(roman[i] == 'C' && roman[i+1] == 'D')
        {
            total += 400;
            i++;
        }
        else if(roman[i] == 'C' && roman[i+1] == 'M')
        {
            total += 900;
            i++;
        }
        else 
        {
        // adding roman numerals that don't require subtraction
        switch(roman[i])
        {
            case 'I':
            total++;
            break;
            case 'V':
            total += 5;
            break;
            case 'X':
            total += 10;
            break;
            case 'L':
            total += 50;
            break;
            case 'C':
            total += 100;
            break;
            case 'D':
            total += 500;
            break;
            case 'M':
            total += 1000;
            break;  
        }
        }

    }

    return total;
}