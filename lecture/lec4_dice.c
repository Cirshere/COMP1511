//Dice Roller - Shows all the possible values of dice

#include<stdio.h>

int main (void) {
    
    int diceOne;
    int diceTwo;
    int targetNum;
    
    printf("Enter the size of your first dice:");
    scanf("%d", &diceOne);
    
    while (diceOne <= 0) {
        printf("That value is invalid, enter the size of your first dice:");
        scanf("%d", &diceOne);
    
    }
    
    printf("Enter the size of your second dice:");
    scanf("%d", &diceTwo);
    
        while (diceTwo <= 0) {
        printf("That value is invalid, enter the size of your second dice:");
        scanf("%d", &diceTwo);
    }
        
    printf("Enter a target number:");
    scanf("%d", &targetNum);
    
            while (targetNum <= 0) {
        printf("That value is invalid, enter the size of your target number:");
        scanf("%d", &targetNum);
    
    }
    int loopNumber = 0;
    int die1 = 1;
    int targetNumSus = 0;
    while (die1 <= diceOne) {
        int die2 = 1;
        
        while (die2 <= diceTwo) {
            
            if (die1 + die2 == targetNum) {
                printf("%d, %d. Total: %d\n", die1, die2, die1 + die2);
                
                targetNumSus = targetNumSus + 1; 
            }
            
            //die2++, Will add 1 to the number (Incrementing)
            die2 = die2 + 1;
            
            loopNumber = loopNumber + 1;
        }
    die1 = die1 + 1;
    }
    
    printf("The target number was hit: %d times\n", targetNumSus);
    printf ("The amount of combinations is:%d\n", loopNumber);
     
    
    return 0;
}
