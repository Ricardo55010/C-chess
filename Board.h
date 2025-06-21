#include"Square.h"
#include<stdio.h>
typedef struct Board{
    Square squares[8][8];
} Board;

int showBoard(Board* board);
int initBoard(Board* board);