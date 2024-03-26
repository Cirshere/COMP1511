//Program that reads 3 integers and then orders them from smallest to largest
//z5259780, Christopher Hoang 03/03/2020

#include<stdio.h>

int main (void) {

    int input1;
    int input2;
    int input3;
    
    printf("Enter integer: ");
    scanf("%d", &input1);
    
    printf("Enter integer: ");
    scanf("%d", &input2);
    
    printf("Enter integer: ");
    scanf("%d", &input3);

   
    if (input1 <= input2 && input2 <= input3) {
        
        printf("The integers in order are: %d %d %d\n", input1, input2, input3); 
    
    }
        
    else if (input1 <= input3 && input3 <= input2) {
        
        printf("The integers in order are: %d %d %d\n", input1, input3, input2);
    }
    
    else if (input2 <= input1 && input1 <= input3) {
        
        printf("The integers in order are: %d %d %d\n", input2, input1, input3);
    } 
    
    else if (input2 <= input3 && input3 <= input1) {
    
        printf("The integers in order are: %d %d %d\n", input2, input3, input1);
    
    }
    
    else if (input3 <= input1 && input1 <= input2) {
    
        printf("The integers in order are: %d %d %d\n", input3, input1, input2);
    
    }    
    
    else {
        printf("The integers in order are: %d %d %d\n", input3, input2, input1); 
    
    }
   

    return 0;
}
