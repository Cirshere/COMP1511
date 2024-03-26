//Addition
//z5259780 Christopher Hoang 25/02/20

#include<stdio.h>

int main(void) {

    int numOne;
    int numTwo;
    int total;

    printf("Please enter two integers:");
    
    scanf("%d", &numOne);
    scanf("%d", &numTwo);
    
    total = (numOne + numTwo);
    
    printf("%d + %d = %d\n", numOne, numTwo, total);

    return 0;    
}
