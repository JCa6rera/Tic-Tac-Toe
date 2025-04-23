#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

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
    

    printf("Hello! Welcome to my Tic-Tac-Toe game!\n");
    int choice;
    char confirmation;
    bool condition = true;
    while(condition){
        choice = 0;
        while(choice != 1 && choice != 2){
            printf("How would you like to play?\n1. Player vs Player\n2. Player vs Computer\n");
            if(scanf("%d", &choice) != 1){
                printf("Invalid input! Please enter 1 or 2.\n");
                while(getchar() != '\n');
                choice = 0;
                continue;
            }
            switch (choice){
                case 1:
                    printf("You chose Player vs Player! Let's Begin\n");
                    playerVSplayerFlow();
                    break;
                case 2:
                    printf("You chose Player vs Computer! Let's Begin\n");
                    //playerVsComputerFlow();
                    break;
                default:
                    printf("Wrong input! Please input a number 1 or 2\n");
                    break;
            }
        }

        if(WINNER == 'X' || WINNER == 'O'){
            printf("%c has won the game! Would you like to play again?(Y/N)\n", WINNER);
            scanf(" %c", &confirmation);
            confirmation = toupper(confirmation);
            if(confirmation == 'N'){
                condition = false;
            }
        } else {
            printf("Looks like nobody one. Would you like to play again?(Y/N)\n");
            scanf(" %c", &confirmation);
            confirmation = toupper(confirmation);
            if(confirmation == 'N'){
                condition = false;
            }
        }
    }
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