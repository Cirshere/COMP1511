//Program to check for negative numbers
//25/02/2020
//z5259780 Christopher Hoang


#include<stdio.h>

int main(void) {

    int numInput;

    scanf("%d", &numInput);

    if (numInput > 0) {
        printf("You have entered a positive number.\n");
    }
    
    else if (numInput < 0) {
        printf("Don't be so negative!\n");
    }
    
    else {
        printf("You have entered zero.\n"); 
    }
    
    return 0;
    
}
