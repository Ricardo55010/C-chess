#ifndef BOARD_H
#define BOARD_H
#include<stdio.h>
#include"Square.h"
#include"Rules.h"
typedef struct Board{
    Square squares[8][8];
    int playerTurn;
} Board;

int showBoard(Board* board);
int initBoard(Board* board);
int movePiece(Board* board,int x1,int y1,int x2,int y2);
#endif