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



int isAValidMove(Board* board,int x1,int y1,int x2,int y2){
    Piece OriginPiece = board->squares[x1-1][y1-1].piece;
    Piece TargetPiece = board->squares[x2-1][y2-1].piece;

    if(OriginPiece.type=='P'){
        if((y1-y2==0 && (x1-x2==2||x1-x2==-2)) && OriginPiece.timesMoved==0){
            printf("valid move, its a valid move for a pawn that moves for the first time\n");
            printf("x1:%d y1:%d x2:%d y2:%d\n",x1,y1,x2,y2);
            printf("x1-x2:%d y1-y2:%d\n",x1-x2,y1-y2);
            return 0;
        }
        if(((y1-y2==1||y1-y2==-1) && (x1-x2==1||x1-x2==-1))&& TargetPiece.player!=OriginPiece.player && TargetPiece.type!=' '){
            printf("Valid move, its a valid move for a pawn that has an enemy piece on the way diagonally\n");
            printf("x1:%d y1:%d x2:%d y2:%d\n",x1,y1,x2,y2);
            printf("x1-x2:%d y1-y2:%d\n",x1-x2,y1-y2);
            return 0;
        }
        
        if((y1-y2!=0 || (x1-x2!=1&&x1-x2!=-1))){
            printf("Invalid move, its not a valid move for a pawn\n");
            printf("x1:%d y1:%d x2:%d y2:%d\n",x1,y1,x2,y2);
            printf("x1-x2:%d y1-y2:%d\n",x1-x2,y1-y2);
            return 1;
        }
    }
    if(OriginPiece.type=='R'){
        if((y1-y2!=0 && x1-x2!=0)){
            printf("Invalid move, its not a valid move for a rook\n");
            printf("x1:%d y1:%d x2:%d y2:%d\n",x1,y1,x2,y2);
            printf("x1-x2:%d y1-y2:%d\n",x1-x2,y1-y2);
            return 1;
        }
    }

    if(OriginPiece.type=='B'){
        if((y1-y2==0 || x1-x2==0)){
            printf("Invalid move, its not a valid move for a bishop\n");
            printf("x1:%d y1:%d x2:%d y2:%d\n",x1,y1,x2,y2);
            printf("x1-x2:%d y1-y2:%d\n",x1-x2,y1-y2);
            return 1;
        }
    }

    if(OriginPiece.type=='N'){
        if(!(((y1-y2==2 || y1-y2==-2) && (x1-x2==1||x1-x2==-1) || (y1-y2==1 || y1-y2==-1) && (x1-x2==2||x1-x2==-2)))){
            printf("Invalid move, its not a valid move for a knight\n");
            printf("x1:%d y1:%d x2:%d y2:%d\n",x1,y1,x2,y2);
            printf("x1-x2:%d y1-y2:%d\n",x1-x2,y1-y2);
            return 1;
        }
    }
    
    if(OriginPiece.type=='Q'){
        if((y1-y2==0 || x1-x2==0 || y1-y2!=0 && x1-x2!=0)){
            printf("Invalid move, its not a valid move for a queen\n");
            printf("x1:%d y1:%d x2:%d y2:%d\n",x1,y1,x2,y2);
            printf("x1-x2:%d y1-y2:%d\n",x1-x2,y1-y2);
            return 1;
        }
    }


    if(OriginPiece.type=='K'){
        if(((y1-y2>1 || y1-y2<-1) || (x1-x2>1||x1-x2<-1))){
            printf("Invalid move, its not a valid move for a king\n");
            printf("x1:%d y1:%d x2:%d y2:%d\n",x1,y1,x2,y2);
            printf("x1-x2:%d y1-y2:%d\n",x1-x2,y1-y2);
            return 1;
        }
    }

    return 0;
}

