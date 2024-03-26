// Program that accepts 3 numbers and prints the middle
// z5259780, Christopher Porgram

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
    
    if(input1 == input2 || input1 == input3){
        printf("Middle: %d\n", input1);
    }
    else if 
    ((input1 <= input2 || input3 <= input2) && 
    (input3 >= input2 || input1 >= input2)) {
        printf("Middle: %d\n", input2);
    }
    else if 
    ((input2 <= input1 || input3 <= input1) && 
    (input3 >= input1|| input2 >= input1)) {
        printf("Middle: %d\n", input1);
    }
    else {
        printf("Middle: %d\n", input3);
    }
    
    return 0;
}
