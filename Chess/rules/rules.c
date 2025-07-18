#include "../rules/rules.h"
#include "../board/board.h"
#include "../movements/movements.h"

/*Objective: check if the move is out of bounds*/
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
/*Objective: check if the piece player is the same as the player turn*/
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

/*Objective: check if there is a piece in the start position*/
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


/*Objective: check if the move is valid depending on the piece*/
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

/*Objective: check if there is a piece on the piece end way*/
int isThereAPieceOnTheWay(Payload* payload){
    Board* board = payload->board;
    int x1=payload->x1,y1=payload->y1,x2=payload->x2,y2=payload->y2;
    if(board->squares[x2-1][y2-1].piece.player==board->playerTurn){
        printf("Invalid move, there is a friendly piece on the way\n");
        return 1;
    }
    return 0;
}

/*Objective: check if there is a piece blocking the way, horse can jump so its never blocked*/
int isAPieceBlockingTheWay(Payload* payload){
    Board* board = payload->board;
    int x1=payload->x1,y1=payload->y1,x2=payload->x2,y2=payload->y2;
    if(board->squares[x1-1][y1-1].piece.type=='N'){
        printf("you are a knight, you can jump over pieces!\n");
        return 0;
    }
    int dx = (x2 > x1) ? 1 : (x2 < x1) ? -1 : 0;
    int dy = (y2 > y1) ? 1 : (y2 < y1) ? -1 : 0;

    int i = x1 + dx;
    int j = y1 + dy;

    while(i != x2 || j != y2){
        if(board->squares[i-1][j-1].piece.type != ' '){
            printf("There is a piece of type %c at %d %d blocking the way\n", board->squares[i-1][j-1].piece.type, i, j);
            return 1;
        }
        if(i != x2) i += dx;
        if(j != y2) j += dy;
    }
    return 0;
}

/*Objective: check if the player own king is in check*/
int isOwnKingInCheck(Payload* payload){
    Board *board = payload->board;
    int x1=payload->x1,y1=payload->y1,x2=payload->x2,y2=payload->y2;
    if(board->playerInCheck==board->playerTurn){
        printf("Invalid move, your king is in check\n");
        return 1;
    }
    return 0;
}


/*Objective: check if the opponent's king is in check*/
int isOpponentKingInCheck(Payload* payload){
    Board *board = payload->board;
    int x1=payload->x1,y1=payload->y1,x2=payload->x2,y2=payload->y2;
    if(board->playerInCheck!=board->playerTurn){
        printf("Your opponent's king is in check\n");
        return 1;
    }
    return 0;
}

int isPawnPromotionPossible(Payload* payload){
    Board *board = payload->board;
    int x1=payload->x1,y1=payload->y1,x2=payload->x2,y2=payload->y2;
    int promotionType;
    if(board->squares[x2-1][y2-1].piece.type=='P' && (x2==8 || x2==1)){
        printf("Chose pawn promotion\n");
        printf("1 for queen\n2 for rook\n3 for bishop\n4 for knight\n");
        scanf("%d",&promotionType);
        switch(promotionType){
            case 1:
                board->squares[x2-1][y2-1].piece.type='Q';
                break;
            case 2:
                board->squares[x2-1][y2-1].piece.type='R';
                break;
            case 3:
                board->squares[x2-1][y2-1].piece.type='B';
                break;
            case 4:
                board->squares[x2-1][y2-1].piece.type='N';
                break;
            default:
                printf("Invalid promotion type\n");
                return 1;
        }
        board->squares[x2-1][y2-1].piece.timesMoved=0;
        return 1;
    }
    return 0;
}