// Program that sums together n amounts of numbers
// z5259780, Christopher Hoang

#include<stdio.h>

#define SIZE 100

int main (void) {

    int totalNum;
    int inputNum;
    int sum = 0;

    printf("How many numbers: ");
    scanf("%d", &totalNum);

    int i = 0;
    
    while (i < totalNum) {
    
        scanf("%d", &inputNum);
        sum += inputNum;
        i++;
    }
    
    printf("The sum is: %d\n", sum);

    return 0;
}
