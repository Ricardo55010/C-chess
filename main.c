#include <stdio.h>
#include <stdlib.h>
#include "Board.h"
int main(){
    Board* board = (Board*) malloc(sizeof(Board));
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    int continueGame = 0;
    printf("Board is:\n");
    initBoard(board);
    do
    {
        showBoard(board);
        printf("\n");
        printf("Its player %d's turn\n",board->playerTurn);
        printf("Enter start position:\n");
        printf("Enter x:\n");
        scanf("%d",&x1);
        printf("Enter y:\n");
        scanf("%d",&y1);
        printf("Enter end position:\n");
        printf("Enter x:\n");
        scanf("%d",&x2);
        printf("Enter y:\n");
        scanf("%d",&y2);
        movePiece(board,x1,y1,x2,y2);
        printf("\n");
        showBoard(board);
        printf("\n");
        printf("Continue game? 1.Yes 2.No\n");
        scanf("%d",&continueGame);
       

    } while (continueGame==1);
    

    system("pause");
    return 0;
}