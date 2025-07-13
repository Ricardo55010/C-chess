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

int isAPieceBlockingTheWay(Payload* payload){
    Board* board = payload->board;
    int x1=payload->x1,y1=payload->y1,x2=payload->x2,y2=payload->y2;
    if(board->squares[x1-1][y1-1].piece.type=='N'){
        printf("you are a knight, you can jump over pieces!\n");
        return 0;
    }
    if(x1 == x2 ){
        printf("You are moving horizontally\n");
        for(int i = y1+1;i<y2;i++){
            if(board->squares[x1-1][i-1].piece.type!=' '){
                printf("There is a piece of type %c at %d %d is blocking the way\n",board->squares[i-1][y1-1].piece.type,i,y1);
                return 1;
            }
        }

    }
    
    if(y1 == y2){
        printf("You are moving vertically\n");
        for(int i = x1+1;i<x2;i++){
            if(board->squares[i-1][y1-1].piece.type!=' '){
                printf("There is a piece of type %c at %d %d is blocking the way\n",board->squares[i-1][y1-1].piece.type,i,y1);
                return 1;
            }
        }
    }

    if(x1 != x2 && y1 != y2){
        printf("You are moving diagonally\n");
        if(x1<x2 && y1<y2){
            printf("Moving bishop down and right\n");
            for(int i = x1+1,j=y1+1;i<x2 && j<y2;i++,j++){
                if(board->squares[i-1][j-1].piece.type!=' '){
                    printf("There is a piece of type %c at %d %d is blocking the way\n",board->squares[i-1][j-1].piece.type,i,j);
                    return 1;
                }
            }
        }
        if(x1<x2 && y1>y2){
            printf("Moving bishop down and left\n");
            for(int i = x1+1,j=y1+1;i<x2 && j>y2;i++,j--){
                if(board->squares[i-1][j-1].piece.type!=' '){
                    printf("There is a piece of type %c at %d %d is blocking the way\n",board->squares[i-1][j-1].piece.type,i,j);
                    return 1;
                }
            }
        }
        if(x1>x2 && y1>y2){
            printf("Moving bishop up and left\n");
            for(int i = x1+1,j=y1+1;i>x2 && j>y2;i--,j--){
                if(board->squares[i-1][j-1].piece.type!=' '){
                    printf("There is a piece of type %c at %d %d is blocking the way\n",board->squares[i-1][j-1].piece.type,i,j);
                    return 1;
                }
            }
        }
        if(x1>x2 && y1<y2){
            printf("Moving bishop up and right\n");
            for(int i = x1+1,j=y1+1;i>x2 && j<y2;i--,j++){
                if(board->squares[i-1][j-1].piece.type!=' '){
                    printf("There is a piece of type %c at %d %d is blocking the way\n",board->squares[i-1][j-1].piece.type,i,j);
                    return 1;
                }
            }
        }
    }
    return 0;
}