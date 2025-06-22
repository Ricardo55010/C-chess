#include "Rules.h"
#include "Board.h"
int isOutBounds(int x1,int y1,int x2,int y2){
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

int isPlayerTurn(Board* board,int x1,int y1){
    if(board->squares[x1-1][y1-1].piece.player!=board->playerTurn){
        printf("Invalid move, its not your turn, player %d\n",board->squares[x1-1][y1-1].piece.player);
        return 1;
    }
    return 0;
}

int isAPiece(Board* board,int x1,int y1){
    if(board->squares[x1-1][y1-1].piece.type==' '){
        printf("Invalid move, theres no piece in %d %d\n",x1,y1);
        return 1;
    }
    return 0;
}

