#ifndef RULES_H
#define RULES_H
//struct Board; // forward declaration to avoid circular dependency with Board.h
typedef struct Payload{
    struct Board* board;
    int x1,y1,x2,y2;
}Payload;
typedef int (*validationFunction)(Payload* payload);

int isOutBounds(Payload* payload);;
int isPlayerTurn(Payload* payload);
int isAPiece(Payload* payload);
int isAValidMove(Payload* payload);
int isThereAPieceOnTheWay(Payload* payload);
int isAPieceBlockingTheWay(Payload* payload);
int isOwnKingInCheck(Payload* payload);
int isOpponentKingInCheck(Payload* payload);
int isPawnPromotionPossible(Payload* payload);
#endif