

#include<stdio.h> 
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

void print_gameplay_minefield(int minefield[SIZE][SIZE]);
void initialise_field(int minefield[SIZE][SIZE]);

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
    
    
    int gameMode = 0; // 0 = Debug mode, 1 = Gameplay mode
    int input;
    int gameState = 1; // 1 = Ongoing, 0 = Lost, 2 = Win! 
    while (scanf("%d", &input) == 1){

            print_gameplay_minefield(minefield);       
        }


    // TODO: Scan in commands to play the game until the game ends.
    // A game ends when the player wins, loses, or enters EOF (Ctrl+D).
    // You should display the minefield after each command has been processed.
    

    return 0;

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
    int colSave = col;    
    int mineTotal = 0;

        while (k < SIZE) {
            l = 0;
            row = k - 1;
            while (l < SIZE) {
                
                row = k - 1;
                col = l - 1;
                mineTotal = 0;
            
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
    
    printf("\n");
    
    i = 0;
    
    while (i < SIZE) {
        j = 0;
        
        while (j < SIZE) {
            printf("%d", minesSurround[i][j]);
            j++;
        }
        i++;
    }
    
}

