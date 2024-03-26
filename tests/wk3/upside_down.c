// Program that determines if 3 inputted numbers are increasing, decreasing
// or neither
// z5259780, Christopher Program

#include<stdio.h>

int main(void) {

    double inputOne;
    double inputTwo;
    double inputThree;
    
    printf("Please enter three numbers: ");
    
    scanf("%lf", &inputOne);
    scanf("%lf", &inputTwo);
    scanf("%lf", &inputThree);
    
    if(inputOne < inputTwo && inputTwo < inputThree) {
    
        printf("up\n");
    
    }
    
    else if(inputOne > inputTwo && inputTwo > inputThree) {
    
        printf("down\n");
    
    }
    
    else {
    
    printf("neither\n");
    
    }

    return 0;

}
