//Program that reads a positive integer, determines all numbers divisible by
//5 or 3, up until this integer
//z5259780 Christopher Hoang

#include<stdio.h>

int main (void) {
    
    int inputNum;
    
    printf("Enter number: ");
    scanf("%d", &inputNum);
    
    int countup = 1;

//Determines if divisible by 3 or 5  
    while (countup < inputNum) {
    
        if (countup % 3 == 0) {
            printf("%d\n", countup);
        }
        
        else if (countup % 5 == 0) {
            printf("%d\n", countup);
        }
       
        countup++;
    }
    
    return 0;    
}    
