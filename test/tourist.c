// A heavily modified version of paint.c for Assignment 1

// This is starter code for the Tourist Program

// This program was written by Marc Chee (marc.chee@unsw.edu.au)
// in June 2019
//

#include <stdio.h>

// The dimensions of the map
#define N_ROWS 10
#define N_COLS 10
#define EXPLORED 1
#define UNEXPLORED 0

// Helper Function: Print out the map as a 2D grid
void printMap(int map[N_ROWS][N_COLS], int posR, int posC);


int main(void) {

    int map[N_ROWS][N_COLS] = {UNEXPLORED};
    int posR = 5;
    int posC = 5;
        
    int gameOver = 0;
    
    while(!gameOver) {
        
        printMap(map, posR, posC);
        
        // Movement using keypad
        printf("Please enter a direction on the numpad: ");
        
        int input;
        scanf("%d", &input);
        
        if(input == 2) { // Down
            posR++;
        }
        else if(input == 4) { // Left
            posC--;
        }
        else if(input == 6) { // Right
            posC++;
        }
        else if(input == 8) { // Up
            posR--;
        }
        else if (input == 0) { // Ends game 
            gameOver = 1;
        }
        
        // If player attempts to past the map, they will stay on the same spot
        if (posR < 0) {
            posR = 0;
        }
        else if (posR >= N_ROWS) {
            posR = N_ROWS - 1;
        }
        
        if (posC < 0) {
            posC = 0;
        }
        else if (posC >= N_COLS) {
            posC = N_COLS - 1;  
        }
        
        // Gameover if the player enters a spot they have already entered on
        // the map      
        if (map[posR][posC] == EXPLORED) {
            printf("How boring, we´ve already been here! Game over!\n");
            gameOver = 1;     
        }
        
        // Turns the spot of the player from unexplored to explored
        map[posR][posC] = EXPLORED;
        
    }

    return 0;
}


// Prints the map, by printing the integer value stored in
// each element of the 2-dimensional map array.
// Prints a T instead at the position posR, posC
void printMap(int map[N_ROWS][N_COLS], int posR, int posC) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            if(posR == row && posC == col) {
                printf("T ");               // Displays where the player is
            } else {
                printf("%d ", map[row][col]);
            }            
            col++;
        }
        row++;
        printf("\n");
    }
}

