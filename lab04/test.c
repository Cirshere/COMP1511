// Testing the result = scanf thingo
// z5259780, Christopher Hoang

#include<stdio.h>

int main (void) {

    int input = 420;
    int result = scanf("%d", &input);

    printf("Input: %d\n", input);
    printf("Result: %d\n", result);

    return 0;
    
}
