#include "Board.h"

int showBoard(Board* board){
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("| %d  %d |",board->squares[i][j].x,board->squares[i][j].y);
        }
        printf("\n");
    }
    return 0;
}

int initBoard(Board* board){
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            board->squares[i][j].x=i+1;
            board->squares[i][j].y=j+1;
        }
    }
    return 0;
}