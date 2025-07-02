#ifndef RULES_H
#define RULES_H
struct Board; // forward declaration to avoid circular dependency with Board.h
int isOutBounds(int x1,int y1,int x2,int y2);
int isPlayerTurn(struct Board* board,int x,int y);
int isAPiece(struct Board* board,int x,int y);
int isAValidMove(struct Board* board,int x1,int y1,int x2,int y2);
#endif