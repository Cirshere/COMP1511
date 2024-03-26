//Program to determine if inputted number is a perfect numbers
//A perfect number is an integer that is equal to the sum of all its factors
//excluding itself (e.g. 6 --> 1, 2, 3, 6 --> 1 + 2 + 3 = 6)
//z5259780 Christopher Hoang 03/03/2020

#include<stdio.h>

int main (void) {

    int inputNum;
    int factorSum = 0   ; 
    
    printf("Enter number:");
    scanf("%d", &inputNum);
    
    printf("The factors of %d are:\n", inputNum);  
    
    //Finds all factors of the number
    int i = 1;
    while (i <= inputNum) {
    
        if (inputNum % i == 0) {        
            printf("%d\n", i);
            factorSum += i;             
        }    
        
        i++;       
    }

    printf("Sum of factors = %d\n", factorSum);
    
    //States if number is a perfect number or not
    if (factorSum / 2.0 == inputNum) {
    
        printf("%d is a perfect number\n", inputNum);
    }
    
     else {
        printf("%d is not a perfect number\n", inputNum);   
    }      
    
    
    return 0;
}
