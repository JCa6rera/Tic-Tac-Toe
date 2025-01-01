#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
const char COMPUTER = 'O';
char board[3][3];


void playerVSplayerFlow();
void resetBoard();
void printBoard();

int main(){
    //starting menu for the game
    char WINNER = ' ';
    resetBoard();
    printBoard();

    printf("Hello! Welcome to my Tic-Tac-Toe game! How would you like to play?\n");
    int choice;
    char confirmation;
    do {
        do{
            printf(" 1. Player vs Player\n 2. Player vs Computer\n");
            scanf("%d", &choice);
            switch(choice){
                case 1:
                    printf("You chose Player vs Player! Let's Begin\n");
                    playerVSplayerFlow();
                    break;
                case 2:
                    printf("You chose Player vs Computer! Let's Begin\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
        } while(choice != 1 && choice != 2);

        printf("Would you like to play again? (Y/`N`)\n");
        scanf(" %c", &confirmation);
        confirmation = toupper(confirmation);
    } while(confirmation == 'Y');
    return 0;
}

void playerVSplayerFlow(){
    printBoard();
}

void resetBoard(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

void printBoard(){
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}