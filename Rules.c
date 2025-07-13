#include "Rules.h"
#include "Board.h"
#include "Movements.h"
int isOutBounds(Payload* payload){
    int x1=payload->x1,y1=payload->y1,x2=payload->x2,y2=payload->y2;
    if((x2-1<0 || x2-1>7) || (y2-1<0 || y2-1>7)){
        printf("Invalid move, out of bounds\n");
        return 1;
    }
    if((x1-1<0 || x1-1>7) || (y1-1<0 || y1-1>7)){
        printf("Invalid move, out of bounds\n");
        return 1; 
    }

    return 0;
}

int isPlayerTurn(Payload* payload){
    Board* board = payload->board;
    int x1=payload->x1,y1=payload->y1;
    Piece OriginPiece = board->squares[x1-1][y1-1].piece;
    int currentPlayerTurn = board->playerTurn;
    if(OriginPiece.player!=currentPlayerTurn){
        printf("Invalid move, its not your turn, player %d\n",OriginPiece.player);
        return 1;
    }
    return 0;
}

int isAPiece(Payload* payload){
    Board* board = payload->board;
    int x1=payload->x1,y1=payload->y1;
    Piece OriginPiece = board->squares[x1-1][y1-1].piece;
    if(OriginPiece.type==' '){
        printf("Invalid move, theres no piece in %d %d\n",x1,y1);
        return 1;
    }
    return 0;
}



int isAValidMove(Payload* payload){
    
    char pieces[] = {'R', 'N', 'B', 'Q', 'K', 'P'};
    validationFunction validationFunctions[]={rookMovement,knightMovement,bishopMovement,queenMovement,kingMovement,pawnMovement};
    int x1=payload->x1,y1=payload->y1,x2=payload->x2,y2=payload->y2;
    int numValidationFunctions=sizeof(validationFunctions)/sizeof(validationFunctions[0]);
    Piece OriginPiece = payload->board->squares[x1-1][y1-1].piece;
    
    for(int i=0;i<numValidationFunctions;i++){
        if(pieces[i]==OriginPiece.type){
            if(validationFunctions[i](payload)==1){
            return 1;
        }
        }
        
    }
    
    return 0;
}

int isThereAPieceOnTheWay(Payload* payload){
    Board* board = payload->board;
    int x1=payload->x1,y1=payload->y1,x2=payload->x2,y2=payload->y2;
    if(board->squares[x2-1][y2-1].piece.player==board->playerTurn){
        printf("Invalid move, there is a friendly piece on the way\n");
        return 1;
    }
    return 0;
}
