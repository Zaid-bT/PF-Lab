#include <stdio.h>
#define SIZE 5


void displayGrid(char grid[SIZE][SIZE]);
void updatePlayerPosition(char grid[SIZE][SIZE], int *playerX, int *playerY, char move);
int isValidMove(int x, int y);
void collectItem(char grid[SIZE][SIZE], int playerX, int playerY);

int main() {
    char grid[SIZE][SIZE] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    int playerX = 4; 
    int playerY = 4; 
    char move;

    while (1) {
        displayGrid(grid);
        printf("Enter your move (W: up, S: down, A: left, D: right, Q: quit): ");
        move = getchar(); 
        getchar(); 
		if (move == 'Q' || move == 'q') {
            printf("Thanks for playing!\n");
            break; 
        }
        updatePlayerPosition(grid, &playerX, &playerY, move);
    }

    return 0;
}

void displayGrid(char grid[SIZE][SIZE]) {
    printf("\nCurrent Grid:\n");
    int i,j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void updatePlayerPosition(char grid[SIZE][SIZE], int *playerX, int *playerY, char move) {
    int newX = *playerX;
    int newY = *playerY;
    switch (move) {
        case 'W': case 'w': newX--; break; 
        case 'S': case 's': newX++; break; 
        case 'A': case 'a': newY--; break; 
        case 'D': case 'd': newY++; break; 
        default:
            printf("Invalid move! Please enter W, S, A, D, or Q.\n");
            return; 
    }

    
    if (isValidMove(newX, newY) && grid[newX][newY] != 'X') {
        grid[*playerX][*playerY] = ' '; 
        *playerX = newX; 
        *playerY = newY; 
        collectItem(grid, *playerX, *playerY); 
        grid[*playerX][*playerY] = 'P';
    } else {
        printf("You cannot move there!\n");
    }
}

int isValidMove(int x, int y) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE);
}

void collectItem(char grid[SIZE][SIZE], int playerX, int playerY) {
    if (grid[playerX][playerY] == 'I') {
        printf("You collected an item!\n");
        grid[playerX][playerY] = ' '; 
    }
}

