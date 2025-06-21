#include <stdio.h>
#include <stdlib.h>
#include "Board.h"
int main(){
    Board* board = (Board*) malloc(sizeof(Board));
    printf("Board is:\n");
    initBoard(board);
    showBoard(board);
    system("pause");
    return 0;
}