// Payton Garing
// Dr. Steinberg
// COP 3223 Section 001
// Large Program 1

#define ROUNDS 5
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

//function prototypes
void greeting(); //display welcome message to user
void playRound(int round); //play one round
int pickOne(); //retrieve the user's guess
int computerPick(); //computer makes its pick
int battle(int player1, int player2); //battle rock...paper...scissor
void result(int player1, int player2); //overall winner of round

//main function
int main() 
{
    int seed;
    greeting();
    printf("Before we start, pick a number to determine how random I will be.\n");
    scanf("%d", &seed);
    srand(seed);
    printf("All set now!\n");

    for (int x = 0; x < ROUNDS; ++x)
    {
    playRound(x + 1);
    }

    printf("********************************************************\n");
    printf("Thank you for playing!\n");
    return 0;
}

//displays greeting message
void greeting() 
{
    printf("********************************************************\n");
    printf("Welcome to rock paper scissor game!\n");
    printf("Here are the rules.\n");
    printf("You and I will get to choose rock, paper, or scissor.\n");
    printf("After we made a decision we will reveal it and determine the winner based on these rules.\n");
    printf("Rock beats Scissor!\n");
    printf("Paper beats rock!\n");
    printf("Scissor beats Paper!\n");
    printf("If we both pick the same option, then is a tie.\n");
    printf("Ready to play?...Here we go!\n");
    printf("********************************************************\n");
}

// user selection prompt and input
int pickOne() 
{
    int userChoice;
    printf("1---Rock\n");
    printf("2---Paper\n");
    printf("3---Scissor\n");
    printf("make your selection: \n");
    scanf("%d", &userChoice);

    return userChoice;
}

// function to get random choice from computer
int computerPick() 
{
    printf("I'm making my decision now.\n");
    int computerChoice;
    int random;
    random = rand() % 3 + 1;
    computerChoice = random;
    return computerChoice;
}

// function to display and determine who won each round
int battle(int player1, int player2)
{
// if loops for draw scenarios
if (player1 == 1 &&  player2 == 1) {
    printf("Player1 and Player2 both used Rock!\nDraw!\n");
    return 0;
} else if (player1 == 2 &&  player2 == 2) {
    printf("Player1 and Player2 both used Paper!\nDraw!\n");
    return 0;
} else if (player1 == 3 &&  player2 == 3) {
    printf("Player1 and Player2 both used Scissor!\nDraw!\n");
    return 0;
// if loops for if user chooses Rock
} else if (player1 == 1 &&  player2 == 2) {
    printf("Player1 used Rock and Player2 used Paper!\nPaper beats Rock!\n");
    return 2;
} else if (player1 == 1 &&  player2 == 3) {
    printf("Player1 used Rock and Player2 used Scissor!\nScissor beats Paper!\n");
    return 1;
// if loops for if user chooses Paper
} else if (player1 == 2 &&  player2 == 1) {
    printf("Player1 used Paper and Player2 used Rock!\nPaper beats Rock!\n");
    return 1;
} else if (player1 == 2 &&  player2 == 3) {
    printf("Player1 used Paper and Player2 used Scissor!\nScissor beats Paper!\n");
    return 2;
// if loops for if user chooses scissor
} else if (player1 == 3 &&  player2 == 1) {
    printf("Player1 used Scissor and Player2 used Rock!\nRock beats Scissor!\n");
    return 2;
} else if (player1 == 3 &&  player2 == 2) {
    printf("Player1 used Scissor and Player2 used Paper!\nScissor beats Paper!\n");
    return 1;
}
    return 0;
}

// function to display result of round
void result(int player1, int player2)
{
if (player1 == 3) {
    printf("You won! I'll let you have this one.\n");
} else if (player2 == 3) {
    printf("I won! Haha better luck next time!\n");
}
}


void playRound(int round)
{
    printf("Welcome to a new round %d!\n", round);
    printf("Best out of three...Let's go!\n");

    // local variable declaration
    int p1wins = 0;
    int p2wins = 0;
    int wins;

// loop that displays and computes information for each round
while(p1wins != 3 && p2wins != 3)
{
    printf("********************************************************\n");
    printf("Player 1 has won %d time(s).\n", p1wins);
    printf("Player 2 has won %d time(s).\n", p2wins);
    int userPick = pickOne();
    int player2 = computerPick();
// if statement for invalid inputs
if (userPick < 1 || player2 < 1 ) {
    printf("someone made an invalid choice.\n");
} else if (userPick > 3 || player2 > 3) {
    printf("someone made an invalid choice.\n");
} else { 
    // nested if statement to update win total for each player
    wins = battle(userPick, player2);
        if(wins == 1) {
            ++p1wins;
        }else if (wins == 2) {
            ++p2wins;
                    }
}
    printf("********************************************************\n");
    // displays final result of round
    result(p1wins, p2wins);
}
}


