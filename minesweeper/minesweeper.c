// Assignment 1 20T1 COMP1511: Minesweeper
// minesweeper.c
//
// This program was written by Christopher Hoang (z5259780)
// on 10/03/2020
//
// Version 1.0.0 (2020-03-08): Assignment released.
// Version 1.0.1 (2020-03-08): Fix punctuation in comment.
// Version 1.0.2 (2020-03-08): Fix second line of header comment to say minesweeper.c

#include <stdio.h>
#include <stdlib.h>

// Possible square states.
#define VISIBLE_SAFE    0
#define HIDDEN_SAFE     1
#define HIDDEN_MINE     2

// The size of the starting grid.
#define SIZE 8

// The possible command codes.
#define DETECT_ROW              1
#define DETECT_COL              2
#define DETECT_SQUARE           3
#define REVEAL_SQUARE           4
#define GAMEPLAY_MODE           5
#define DEBUG_MODE              6
#define REVEAL_RADIAL           7

// Add any extra #defines here.

#define REVEAL_SIZE             3

// Place your function prototyes here.

void initialise_field(int minefield[SIZE][SIZE]);
void print_debug_minefield(int minefield[SIZE][SIZE]);
void detect_Row(int minefield[SIZE][SIZE]);
void detect_Col(int minefield[SIZE][SIZE]);
void detect_Sq(int minefield[SIZE][SIZE]);
int reveal_Sq(int minefield[SIZE][SIZE]);
void print_gameplay_minefield(int minefield[SIZE][SIZE]);
void print_gameplay_lost_minefield(int minefield[SIZE][SIZE]);

int main(void) {
    int minefield[SIZE][SIZE];
    initialise_field(minefield);
    printf("Welcome to minesweeper!\n");
    printf("How many mines? ");
    
    // Detects the amounts of mines    
    int mineNum;
    scanf("%d", &mineNum);

    // Determines placement of mines and changes position of mines to 2
    printf("Enter pairs:\n");    
    int row = 0, col = 0; // Rows and Columns   
    int i = 0;
    while (i < mineNum) {
        scanf("%d %d", &row, &col);
        if (row < SIZE && row >= 0 && col < SIZE && col >= 0) {
            minefield[row][col] = HIDDEN_MINE;
        }    
        i++;
    }
    
    printf("Game Started\n");
    print_debug_minefield(minefield);
    
    int input;
    int hintCount = 0;
    int holder1 = 0;
    int holder2 = 0;
    int holder3 = 0;
    
    int gameMode = 0; // 0 = Debug mode, 1 = Gameplay mode
    
    int gameState = 1; // 1 = Ongoing, 0 = Lost, 2 = Win! 
    while ((scanf("%d", &input) == 1) && (gameState == 1)) {
        
        if (input == DETECT_ROW && hintCount < 3) {
            detect_Row(minefield);
            hintCount++;                 
        }
        else if (input == DETECT_ROW && hintCount == 3) {
            scanf("%d %d", &holder1, &holder2);
            printf("Help already used\n");
        }

        if (input == DETECT_COL && hintCount < 3) {
            detect_Col(minefield);
            hintCount++;
        }
        else if (input == DETECT_COL && hintCount == 3) {
            scanf("%d %d", &holder1, &holder2);
            printf("Help already used\n");
        }
        
        if (input == DETECT_SQUARE && hintCount < 3) {
            detect_Sq(minefield);
            hintCount++;
        }
        else if (input == DETECT_SQUARE && hintCount == 3) {
            scanf("%d %d %d", &holder1, &holder2, &holder3);
            printf("Help already used\n");
        }
        
        if (input == REVEAL_SQUARE) {
            gameState = reveal_Sq(minefield);
        }
        
        if (input == GAMEPLAY_MODE) {
            gameMode = 1;
        }
        else if (input == DEBUG_MODE) {
            gameMode = 0;
        }
        
        if (gameState == 2) {  
            printf("Game Won!\n");
        }        
        
        if (gameMode == 0) {     
            if (input == DEBUG_MODE) {
                printf("Debug mode activated\n");
            }
            print_debug_minefield(minefield);
        }
        else if (gameMode == 1) {
            if (input == GAMEPLAY_MODE) {
                printf("Gameplay mode activated\n");
            }
            if (gameState == 1 || gameState == 2) { // Prints ongoing/win minefield 
                print_gameplay_minefield(minefield);
            }
            else if (gameState == 0) {
                print_gameplay_lost_minefield(minefield);
            }       
        }
    }

    // TODO: Scan in commands to play the game until the game ends.
    // A game ends when the player wins, loses, or enters EOF (Ctrl+D).
    // You should display the minefield after each command has been processed.
    

    return 0;

}

// Set the entire minefield to HIDDEN_SAFE.
void initialise_field(int minefield[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            minefield[i][j] = HIDDEN_SAFE;
            j++;
        }
        i++;
    }
}

// Print out the actual values of the minefield.
void print_debug_minefield(int minefield[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            printf("%d ", minefield[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

// Scans the row / column inputted and counts total amount of mines
void detect_Row(int minefield[SIZE][SIZE]) {
    int i = 0;
    int inputRow;
    int mineTotal = 0;    
    
    scanf("%d ", &inputRow); // Detects Row
    while(i < SIZE) { // Counts total amount of mines in the row
        if(minefield[inputRow][i] == 2) {
            mineTotal++;
        }
        i++;
    }        
    printf("There are %d mine(s) in row %d\n", mineTotal, inputRow);
}

void detect_Col(int minefield[SIZE][SIZE]) {
    int i = 0;
    int inputCol;
    int mineTotal = 0;    
    
    scanf("%d ", &inputCol); // Detects Column
                               
    while (i < SIZE) { // Counts total amount of mines in the column
        if(minefield[i][inputCol] == 2) {
            mineTotal++;
        }
        i++;
    }
    printf("There are %d mine(s) in column %d\n", mineTotal, inputCol);

}

// Scans a nxn square and detects amounts of mines and prints for the user
void detect_Sq(int minefield[SIZE][SIZE]) {

    int inputLength;
    int inputRow;
    int inputCol; 
    int mineTotal = 0;
    
    // Detecting row, col and size of square
    scanf("%d %d %d", &inputRow, &inputCol, &inputLength);
    
    int row = inputRow - inputLength / 2;
    int col = inputCol - inputLength / 2;
    int colSave = col;
    
    int i = 0;
    
    while (i < inputLength) { // Counting mines in total nxn area 
        int j = 0;
        col = colSave;
        
        while (j < inputLength) {
            if (minefield[row][col] == HIDDEN_MINE) {
                mineTotal++;
            }
            j++;
            col++;
                        
        }
        row++;
        i++;   
    }
    
    printf(
        "There are %d mine(s) in the square centered at row %d, column %d of size %d\n"
    , mineTotal, inputRow, inputCol, inputLength);  
         
}

// Command to reveal a 3x3 Square
int reveal_Sq(int minefield[SIZE][SIZE]) {

    int inputRow;
    int inputCol;
    scanf("%d %d", &inputRow, &inputCol);
    
    int col = inputCol - 1;
    int row = inputRow - 1;
    int colSave = col;

    
    int i = 0;
    int j = 0;
    int mineTotal = 0;
    int gameState = 1; //1 = Ongoing , 0 = Lose, 2 = Win
      
    while(i < REVEAL_SIZE) { // Counts amounts of mines surrounding
        j = 0;
        col = colSave;
        while(j < REVEAL_SIZE) {

            if (row >= SIZE) {
                row = SIZE - 1;                
            }
            else if (row < 0) {
                row = 0;
                i++;        
            }
                
            if (col >= SIZE) {
                col = SIZE - 1;
            }
            else if (col < 0) {
                col = 0;
                j++;                                    
            }            
            
            if(minefield[row][col] ==  HIDDEN_MINE) {
                mineTotal++; 
            }
                                   
            col++;
            j++;
        }
        i++;
        row++;
    }    
    
    
    row = inputRow - 1;
    col = colSave;
 
// Inputted row and col will end if mine present
    if (minefield[inputRow][inputCol] == HIDDEN_MINE) {
        printf("Game over\n");
        gameState = 0;
        
    }
// If mines are nearby, only reveal inputted row and col    
    else if ( mineTotal != 0) {
        minefield[inputRow][inputCol] = VISIBLE_SAFE;
    }
// If no mines nearby, reveal 3x3 square    
    else {
        i = 0;
        while (i < REVEAL_SIZE){
            j = 0;
            col = colSave;
            while (j < REVEAL_SIZE) {
                if (row >= SIZE) {
                    row = SIZE - 1;                
                }
                else if (row < 0) {
                    row = 0;
                    i++;        
                }
                
                if (col >= SIZE) {
                    col = SIZE - 1;
                }
                else if (col < 0) {
                    col = 0;
                    j++;                                    
                }
                
                minefield[row][col] = VISIBLE_SAFE;
                 
                col++;
                j++;
            }
            row++;
            i++;
        }       
    }
    
    // Determines if the game is won or ongoing
    int safeCount = 0;
    i = 0;
    while (i < SIZE) {
        j = 0;
        while (j < SIZE) {
            if (minefield[i][j] == 1) {
                safeCount++;
            }
            j++;
        }
        i++;
    }
    
    if (safeCount == 0) {
        gameState = 2;
    }
    
    return gameState;
}

void print_gameplay_minefield(int minefield[SIZE][SIZE]) {
    
    printf("..\n");
    printf("\\/\n");
    printf("   00 01 02 03 04 05 06 07\n");
    printf("   -------------------------\n");

    int minesSurround[SIZE][SIZE];
    int i = 0;
    int j = 0;
    int k = 0; 
    int l = 0;
    int row = k - 1;
    int col = l - 1;   
    int mineTotal = 0;

    while (k < SIZE) {
        l = 0;
        row = k - 1;
        while (l < SIZE) {
            
            row = k - 1;
            mineTotal = 0;
            i = 0;
        
            while(i < REVEAL_SIZE) { // Counts amounts of mines surrounding
                j = 0;
                col = l - 1;
                
                while(j < REVEAL_SIZE) {

                    if (row >= SIZE) {
                        row = SIZE - 1;                
                    }
                    else if (row < 0) {
                        row = 0;
                        i++;        
                    }
                        
                    if (col >= SIZE) {
                        col = SIZE - 1;
                    }
                    else if (col < 0) {
                        col = 0;
                        j++;                                    
                    }            
                    
                    if(minefield[row][col] ==  HIDDEN_MINE) {
                        mineTotal++; 
                    }
                                            
                    col++;
                    j++;
                }
                i++;
                row++;
            }
            
            minesSurround[k][l] = mineTotal;
            l++;             
        }
        k++;
    }

    i = 0;
    
    while (i < SIZE) {
        j = 0;
        printf("0%d |", i);
        while (j < SIZE) {        
            if (minefield[i][j] == HIDDEN_MINE || minefield[i][j] == HIDDEN_SAFE) {
                printf("##");
            }
            
            else if (minefield[i][j] == VISIBLE_SAFE) {
                if (minesSurround[i][j] == 0) {
                    printf("  ");
                }
                else {
                    printf("0%d", minesSurround[i][j]);
                }
            }
            
            if (j < SIZE - 1) {
                printf(" ");
            }
            j++;
        }
        printf("|\n");
        i++;        
    }
    printf("   -------------------------\n");

}

void print_gameplay_lost_minefield(int minefield[SIZE][SIZE]) {
    
    printf("xx\n");
    printf("/\\\n");
    printf("   00 01 02 03 04 05 06 07\n");
    printf("   -------------------------\n");

    int minesSurround[SIZE][SIZE];
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int row = k - 1;
    int col = l - 1;   
    int mineTotal = 0;

    while (k < SIZE) {
        l = 0;
        row = k - 1;
        while (l < SIZE) {
            
        row = k - 1;
        mineTotal = 0;
        i = 0;
    
        while(i < REVEAL_SIZE) { // Counts amounts of mines surrounding
            j = 0;
            col = l - 1;
            
            while(j < REVEAL_SIZE) {

                if (row >= SIZE) {
                    row = SIZE - 1;                
                }
                else if (row < 0) {
                    row = 0;
                    i++;        
                }
                    
                if (col >= SIZE) {
                    col = SIZE - 1;
                }
                else if (col < 0) {
                    col = 0;
                    j++;                                    
                }            
                
                if(minefield[row][col] ==  HIDDEN_MINE) {
                    mineTotal++; 
                }
                                        
                col++;
                j++;
            }
            i++;
            row++;
        }
        
        minesSurround[k][l] = mineTotal;
        l++;             
    }
    k++;
}
 
    i = 0;
    
    while (i < SIZE) {
        j = 0;
        printf("0%d |", i);
        while (j < SIZE) {        
            if (minefield[i][j] == HIDDEN_SAFE) {
                printf("##");
            }
            
            else if (minefield[i][j] == HIDDEN_MINE) {
                printf("()");
            }
            
            else if (minefield[i][j] == VISIBLE_SAFE) {
                if (minesSurround[i][j] == 0) {
                    printf("  ");
                }
                else {
                    printf("0%d", minesSurround[i][j]);
                }
            }
            
            if (j < SIZE - 1) {
                printf(" ");
            }
            j++;
        }
        printf("|\n");
        i++;        
    }
    printf("   -------------------------\n");

}
