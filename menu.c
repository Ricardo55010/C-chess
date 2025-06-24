#include "menu.h"
#include "Board.h"
int showMenu(Board * board, int* x1, int* y1, int* x2, int* y2, int* continueGame){
    printf("\n");
    printf("Its player %d's turn\n",board->playerTurn);
    printf("Enter start position:\n");
    printf("Enter x:\n");
    scanf("%d",x1);
    printf("Enter y:\n");
    scanf("%d",y1);
    printf("Enter end position:\n");
    printf("Enter x:\n");
    scanf("%d",x2);
    printf("Enter y:\n");
    scanf("%d",y2);
    movePiece(board,*x1,*y1,*x2,*y2);
    printf("\n");
    showBoard(board);
    printf("\n");
    printf("Continue game? 1.Yes 2.No\n");
    scanf("%d",continueGame);
}