//Check for leap year
//z5259780, Christopher Hoang 25/02/20

#include<stdio.h>

int main(void) {

    int year;
    
    printf("Enter year: ");
    
    scanf("%d", &year);
    
    if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) {
        printf("%d is not a leap year.\n", year);
        
    }
    else {
        printf("%d is a leap year.\n", year); 
    }    
   

    return 0;
}
