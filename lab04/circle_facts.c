// COMP1511 Week 5 Lab: Circle Facts
//
// This program was written by Christopher Hoang (z5259780)
// on 10/03/2020
//
// This program prints out facts about a circle given its radius,
// using functions.
//

#include <stdio.h>
#include <math.h>

double area(double radius);
double circumference(double radius);
double diameter(double radius);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(void) {
    double radius;

    printf("Enter circle radius: ");
    scanf("%lf", &radius);

    printf("Area          = %lf\n", area(radius));
    printf("Circumference = %lf\n", circumference(radius));
    printf("Diameter      = %lf\n", diameter(radius));

    return 0;
}


// Calculate the area of a circle, given its radius.
double area(double radius) {
    
    return M_PI * radius * radius;
}

// Calculate the circumference of a circle, given its radius.
double circumference(double radius) {

    return M_PI * 2 * radius;
}

// Calculate the diameter of a circle, given its radius.
double diameter(double radius) {

    return radius * 2;
}
