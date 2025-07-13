#include "menu.h"
#include "Board.h"

void showPlayerTurnMessage(Board* board){
    printf("\n");
    printf("Its player %d's turn\n",board->playerTurn);
}

void getStartPositionMessage(int* x1,int* y1){
    printf("Enter start position:\n");
    printf("Enter x:\n");
    scanf("%d",x1);
    printf("Enter y:\n");
    scanf("%d",y1);
}
void getEndPositionMessage(int* x2,int* y2){
    printf("Enter end position:\n");
    printf("Enter x:\n");
    scanf("%d",x2);
    printf("Enter y:\n");
    scanf("%d",y2);
}
void showContinueMessage(int* continueGame){
    printf("\n");
    //printf("Continue game? 1.Yes 2.No\n");
    //scanf("%d",continueGame);
    *continueGame = 1;
}
int showMenu(Board * board, int* x1, int* y1, int* x2, int* y2, int* continueGame){
    showPlayerTurnMessage(board);
    getStartPositionMessage(x1,y1);
    getEndPositionMessage(x2,y2);
    movePiece(board,*x1,*y1,*x2,*y2);
    showBoard(board);
    showContinueMessage(continueGame);
}
