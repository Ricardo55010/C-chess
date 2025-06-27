#include <stdio.h>
#include <stdlib.h>
#include "Board.h"
#include "menu.h"
int main(){
    Board* board = (Board*) malloc(sizeof(Board));
    int x1 = 0 , y1 = 0, x2 = 0, y2 = 0;
    int continueGame = 0;
    printf("Board is:\n");
    initBoard(board);
    do
    {
        showBoard(board);
        showMenu(board,&x1,&y1,&x2,&y2,&continueGame);
    } while (continueGame==1);
    

    system("pause");
    return 0;
}