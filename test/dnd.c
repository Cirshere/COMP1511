// Dice Checker
//Chris H - 20/02/20
//Dice checker using scanf, printf, define, arithmatic , if, if else and else



#include <stdio.h>
//Set what the secret nubmer is
#define SECRET_NUMBER 7

int main(void) {
    //Set variables
    int firstRoll;
    int secondRoll;
    
    printf("A goblin blocks your path! Roll to decide your fate\n");
    //Tell the user to input a value and detect the input
    printf("Please input your first roll: \n");
    scanf("%d", &firstRoll);
    //Repeat for the second value
    printf("Please input your second roll: \n");
    scanf("%d", &secondRoll);
    //Add up the two variables
    int total = firstRoll + secondRoll;
    //Output msg depending on total number
    //Success output
    if (total > SECRET_NUMBER) {
    printf("The goblin falls. You win!\n");
    //Output if total is equal
}   else if (total == SECRET_NUMBER) {
    printf("Overwhelmed by the goblin, you retreat escaping with your life\n");
    //Output if failed
}   else {
    printf("The goblin fatally wounds you. You lose... \n");
}
    
    
    return 0;
}



