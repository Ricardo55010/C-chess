#include "Board.h"

int showBoard(Board* board){
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("| %d %c %d |",board->squares[i][j].x,board->squares[i][j].piece.type,board->squares[i][j].y);
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
            board->squares[i][j].piece.type=' ';
            if(i==0 || i==7){
                if(j==0 || j==7)
                    board->squares[i][j].piece.type='R';
                if(j==1 || j==6)
                    board->squares[i][j].piece.type='N';
                if(j==2 || j==5)
                    board->squares[i][j].piece.type='B';
                if(j==3)
                    board->squares[i][j].piece.type='Q';
                if(j==4)
                    board->squares[i][j].piece.type='K';
            }
            if((i==1 || i==6))
                board->squares[i][j].piece.type='P';
            
        }
    }
    return 0;
}