// Payton Garing
// Dr. Steinberg
// COP3223 Section 001
// Small Program 3
#include <stdio.h>
// function prototypes
int creditCheck(double price);
int universityAdmission(double gpa, int testScore);
void keyPad();
double carpenter();

int main()
{
//problem 1 
double price;
printf("Enter the price: ");
scanf("%lf", &price);
creditCheck(price);

//problem 2
double gpa; 
int testScore;
printf("Welcome to the University Admission System!\n");
printf("Enter the GPA: ");
scanf("%lf", &gpa);
printf("Enter the test score: ");
scanf("%d", &testScore);
universityAdmission(gpa, testScore);

//problem 3
keyPad();

//problem 4
double signCost;
signCost = carpenter();
if (signCost >= 0) {
printf("Bruce will charge $%.2lf.", signCost);
}

return 0;
}

int creditCheck(double price)
{
// if statement to approve credit 
if (price < 0) {
  printf("Error!\n");
} else if (price < 9000) {
printf("Approved!\n");
} else {
printf("Not Approved!\n");
}
return 0;
}

int universityAdmission(double gpa, int testScore)
{
// if statement to check gpa and test score to verify admission or scholarship
if (gpa >= 3.50 && testScore >= 70) {
printf("Admissions is Approved!\n");
printf("Consider for Scholarship Award!\n");
} else if ((gpa >= 3.00 && testScore >= 60) || (gpa >= 2.00 && testScore >= 80)) {
  printf("Admissions is Approved!\n");
 }
 else if (gpa <= 0.00 || testScore <= 0 || gpa >= 4.01 || testScore >= 101) {
  printf("Invalid Input!\n");
 } else {
 printf("Admissions is Denied!\n");
 }
return 0;
}

void keyPad()
{
printf("Welcome to the Crazy Keypad!\n");
printf("Select one of the following options for a message.\n");
printf("Option 1\n");
printf("Option 2\n");
printf("Option 3\n");
printf("Option 4\n");
printf("Option 5\n");
int option;
printf("Option Selected: ");
scanf("%d", &option);
// switch (aesthetically pleasing) for keypad options
switch(option) {
  case 1:
printf("Opening Vault 712...\n");
break;
 case 2:
 printf("Opening Secret Elevator...\n");
 break;
 case 3:
 printf("Calling the Boss...\n");
 break;
 case 4:
 printf("Backup on the way...\n");
 break;
 case 5:
 printf("Alarm activated...\n");
 break;
 default:
 printf("System Locked...\n");
}
}

double carpenter()
{
//variable assignment
double charge = 30; 

printf("Welcome to Bruce's Carpentry Services!\n");
printf("Would you like the sign made out of oak?\n");
char oak;
printf("Enter y for yes or n for no: ");
scanf(" %c", &oak);
//adding charges for oak sign 
if (oak == 'y' || oak == 'Y'){
charge = charge + 15;
}else if (oak == 'n' || oak == 'N'){
charge = charge; 
}else {
printf("Could not compute cost...\n");
return -1;
}


int chars;
printf("Enter the number of characters on the sign: ");
scanf("%d", &chars);
// adding charges for # of characters over 5
if (chars < 0) {
printf("Could not compute cost...\n");
return -1;
} else if (chars > 5){ 
charge = charge + (2 * (chars - 5));
} 

char gold;
printf("Would you like gold-leaf lettering?\n");
printf("Enter y for yes or n for no: ");
scanf(" %c", &gold);
// adding charges to total for gold-leaf lettering
if (gold == 'y' || gold == 'Y') {
charge = charge + 12;
}else if (gold == 'n' || gold == 'N') {
charge = charge; 
}else {
printf("Could not compute cost...\n");
return -1;
}

return charge;
}