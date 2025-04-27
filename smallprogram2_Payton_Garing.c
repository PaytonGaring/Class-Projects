// Payton Garing
// Dr. Steinberg
// Cop 3223 Section 001
// Small Program 2

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//function prototypes
double calcHypotenuse(double  a, double b);
int rentalPrices();
int timeDisplay (int seconds);
double mathFunction (double n);

// main function
int main() {

// problem 1 begins..
double a, b;
printf("Enter the value for a: ");
scanf("%lf", &a);
printf("Enter the value for b: ");
scanf("%lf", &b);
double hypot = calcHypotenuse (a, b); 
printf("If a = %.3lf and b = %.3lf, then that means the hypotenuse is %.3lf. \n", a, b, hypot);
// problem 1 ends

// problem 2 begins..
rentalPrices();
// problem 2 ends..

// problem 3 begins..
int seconds;
printf("Enter the seconds: ");
scanf("%d", &seconds);
timeDisplay(seconds);
// problem 3 ends..

// problem 4 begins
double n;
printf("Enter the value for n: ");
scanf("%lf", &n);
double result = mathFunction(n);
printf("The function computes the value %.3lf.", result);
// problem 4 ends
return 0;
}

//function definition for calculating hypotenuse
double calcHypotenuse(double  a, double b) {
double squared = (a * a) + (b * b);
double hypot = sqrt(squared);  
return hypot;
}

// function definition for calculating and displaying rental car prices
int rentalPrices()
{
printf("Hello Luis!\n");
printf("Thank you for considering Hertz for your car rental needs.\n");
printf("You have asked to compare prices for three vehicles.\n");
printf("Please enter the number of days you plan to rent the vehicle: ");
int days;
scanf("%d", &days);
double teslaPrice = 46.48 * days; 
double chevyPrice = 49.53 * days; 
double nissanPrice = 50.72 * days;
printf("Here are the prices excluding tax.\n");
printf("Tesla Model 3 Standard Range: $%.2lf\n", teslaPrice);
printf("Chevrolet Malibu: $%.2lf\n", chevyPrice);
printf("Nissan Rogue: $%.2lf\n", nissanPrice); 
} 

// function to calculate hours, minutes, and seconds per # of seconds
int timeDisplay(int seconds){
int hours = seconds / 3600;
int minutes = (seconds % 3600) / 60;
int second = (seconds % 3600) % 60;
printf("%d seconds is %d hours, %d minutes, and %d seconds.\n", seconds, hours, minutes, second);  
}

// function to calculate f(n)
double mathFunction(double n) {
double numerator  = (pow(n, n) - pow(2,n));
double denominator = ((sqrt(n)) + pow(n, 4)) / ((exp(n-2)) + (9));
double calculation = ((numerator) / (denominator)) - (8 * n);
return calculation;   
}