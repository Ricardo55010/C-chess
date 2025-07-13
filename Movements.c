#include"movements.h"
#include"rules.h"
#include"board.h"

   int pawnMovement(Payload *payload){
       int x1=payload->x1,y1=payload->y1,x2=payload->x2,y2=payload->y2;
       Board* board = payload->board;
       Piece OriginPiece = board->squares[x1-1][y1-1].piece;
       Piece TargetPiece = board->squares[x2-1][y2-1].piece;
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


        return 0;
   }
        
   
   int rookMovement(Payload *payload){
    int x1=payload->x1,y1=payload->y1,x2=payload->x2,y2=payload->y2;
       if((y1-y2!=0 && x1-x2!=0)){
            printf("Invalid move, its not a valid move for a rook\n");
            printf("x1:%d y1:%d x2:%d y2:%d\n",x1,y1,x2,y2);
            printf("x1-x2:%d y1-y2:%d\n",x1-x2,y1-y2);
            return 1;
        }
        return 0;
   }

   int bishopMovement(Payload *payload){
    int x1=payload->x1,y1=payload->y1,x2=payload->x2,y2=payload->y2;
       if((y1-y2==0 || x1-x2==0)){
            printf("Invalid move, its not a valid move for a bishop\n");
            printf("x1:%d y1:%d x2:%d y2:%d\n",x1,y1,x2,y2);
            printf("x1-x2:%d y1-y2:%d\n",x1-x2,y1-y2);
            return 1;
        }
        return 0;   
   }
   
   int knightMovement(Payload *payload){
    int x1=payload->x1,y1=payload->y1,x2=payload->x2,y2=payload->y2;
       if(!(((y1-y2==2 || y1-y2==-2) && (x1-x2==1||x1-x2==-1) || (y1-y2==1 || y1-y2==-1) && (x1-x2==2||x1-x2==-2)))){
            printf("Invalid move, its not a valid move for a knight\n");
            printf("x1:%d y1:%d x2:%d y2:%d\n",x1,y1,x2,y2);
            printf("x1-x2:%d y1-y2:%d\n",x1-x2,y1-y2);
            return 1;
        }
        return 0;
   }

   int queenMovement(Payload *payload){
    int x1=payload->x1,y1=payload->y1,x2=payload->x2,y2=payload->y2;
       if((y1-y2==0 || x1-x2==0 || y1-y2!=0 && x1-x2!=0)){
            printf("Invalid move, its not a valid move for a queen\n");
            printf("x1:%d y1:%d x2:%d y2:%d\n",x1,y1,x2,y2);
            printf("x1-x2:%d y1-y2:%d\n",x1-x2,y1-y2);
            return 1;
        }
        return 0;
    }
    
    int kingMovement(Payload *payload){
        int x1=payload->x1,y1=payload->y1,x2=payload->x2,y2=payload->y2;
        if(((y1-y2>1 || y1-y2<-1) || (x1-x2>1||x1-x2<-1))){
            printf("Invalid move, its not a valid move for a king\n");
            printf("x1:%d y1:%d x2:%d y2:%d\n",x1,y1,x2,y2);
            printf("x1-x2:%d y1-y2:%d\n",x1-x2,y1-y2);
            return 1;
        }
        return 0;
    }

