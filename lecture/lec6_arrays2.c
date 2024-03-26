                                    // Programs for keeping player scores in a game - Lecture demo
// z5259780 Christopher Hoang

#include<stdio.h>
// Allows for flexibility for num of players
#define NUM_PLAYERS 4

// Declares display scores --> Not defined here
// Gives displayScores access to the arrays

void displayScores(int scoresArray[]); // Void is used as main function is not needed
void displayHighest(int scoresArray[]);
void displayLowest(int scoresArray[]);
void displayTotal(int scoresArray[]); 

int main (void) {
    
    int scores[NUM_PLAYERS] = {0};
        
    scores[0] = 300; //Assumes highest score between 0 and 400
    scores[1] = 250;
    scores[2] = 145;
    scores[3] = 195;

    displayScores(int scores[]); // Function will run -- Can be repeated 
    displayLowest(scores[]); // Function displays lowest score
    displayTotal(scores[]);
    return 0;
}

// Displays current scores of all players

// DisplaysScores defined here --> Can be defined either way however we rather
// the main program be closer to the top

void displayScores(int scoresArray[]) {

    int i = 0;
    while (i < NUM_PLAYERS) { // Has processed i amount of players
        
        printf("Player %d has earned %d points!\n", i, scoresArray[i]);
        i++;
    } // i = NUM_PLAYERS
    

}

void displayLowest(int scoresArray[]) {
    
    int i = 0;
    int indexLowest = 0;
    int scoreLowest = 401;
    
    
    while (i < NUM_PLAYERS) { // Will cycle through all players
    
        if (scoresArray[i] < scoreLowest) { // If score is lower than current lowest
            scoreLowest = scoresArray[i];    // Tracks new lowest score and player no.
            indexLowest = i;      
            
        }
        
        i++;
    } // i = Num_PLAYERS
    
    printf("Player %d has the lowest score of %d!\n", indexLowest, scoreLowest);
    
}

void displayHighest(int scoresArray[]) {

    int i = 0;
    int indexHighest = 0; 
    int scoreHighest = -1;
    
    while (i < NUM_PLAYERS) {
        if (scoresArray[i] > scoreHighest) {
            indexHighest = i;
            scoreHighest = scoresArray[i];
        
        }
    i++;
    }
    
    printf("Player %d has the highest score of %d!\n", indexHighest, scoreHighest);
    
}

void displayTotal(int scoresArray[]) {

    int i = 0;
    int total = 0;
    
    while (i < NUM_PLAYERS) {
    
    total += scoresArray[i];
    
    i++;
    
    }

    printf("The total score of all players is %d", total);
}
