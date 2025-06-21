#include"Square.h"
#include<stdio.h>
typedef struct Board{
    Square squares[8][8];
} Board;

int showBoard(Board* board);
int initBoard(Board* board);
int movePiece(Board* board,int x1,int y1,int x2,int y2);