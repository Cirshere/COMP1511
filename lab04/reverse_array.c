// Program to read integers and then prints these integers in reverse order
// z5259780, Christopher Hoang

#include<stdio.h>
#define MAX_INTEGERS 100

int main (void) {
    
    printf("Enter numbers forwards: \n");
    
    int inputValue[MAX_INTEGERS] = {};
    int i = 0;
    int result = 1;
    
    while (result == 1) {
        
        result = scanf("%d", &inputValue[i]);
        i++;
        
    }        
    
    printf("Reversed:\n");
    
    i--;
    
    while (i != 0) {
        printf("%d\n", inputValue[i - 1]);        
        i--;
    }
    
    return 0;

}
