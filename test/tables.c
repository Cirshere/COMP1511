#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main () {
    srand(time(NULL));
    
    int num_one = rand() % 12;
    int num_two = rand() % 12;
    int answer = 0;
    
    int ans_right = 0; // 0 is false
    
    while (ans_right == 0) {
   
    printf("What is %d x %d? ", num_one, num_two);
    scanf("%d", &answer);
    
    if (answer == num_one * num_two) {
        printf("Correct!\n");
        ans_right = 1;
    } else {
        printf("Incorrect - try again!\n");
    }
    
    
    }
    

    return 0;
}  
