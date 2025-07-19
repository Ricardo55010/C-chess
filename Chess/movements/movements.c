#include"movements.h"
#include"../rules/rules.h"
#include"../board/board.h"
/*Objective: Validate the movement of a pawn*/
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
        
 /*Objective: Validate the movement of a rook*/  
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
/*Objective: Validate the movement of a bishop*/
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
 /*Objective: Validate the movement of a knight*/  
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
/*Objective: Validate the movement of a queen*/
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
/*Objective: Validate the movement of a king*/    
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
/*Objective: Validate if any piece is checking the king*/
    int lookForBothChecks(Payload *payload){
        Board* board = payload->board;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
               
                if(board->squares[i][j].piece.type=='P'){
                    int movsX [] = {1,1,-1,-1};
                    int movsY []= {1,-1,1,-1};
                    int numMovs = sizeof(movsX)/sizeof(movsX[0]);
                    for(int k=0;k<numMovs;k++){
                        Payload payload={board,i,j,i+movsX[k],j+movsY[k]};
                        validationFunction validationFunctions[]={isOutBounds,isPlayerTurn,isAPiece,isAValidMove,isThereAPieceOnTheWay,isAPieceBlockingTheWay,isOwnKingInCheck};
                        int numValidationFunctions=sizeof(validationFunctions)/sizeof(validationFunctions[0]);
                        
                        for(int i=0;i<numValidationFunctions;i++){
                            if(validationFunctions[i](&payload)==1){
                                if(board->squares[i+movsX[k]][j+movsY[k]].piece.type=='K' && board->squares[i][j].piece.player!=board->squares[i+movsX[k]][j+movsY[k]].piece.player){
                                    printf("Check! pawn at %d %d can check the king at %d %d \n",i+1,j+1,i+movsX[k]+1,j+movsY[k]+1);
                                }
                            }
                    }
                }

                if(board->squares[i][j].piece.type=='B'){
                    int movsX [] = {1,1,-1,-1,2,2,-2,-2};
                    int movsY []= {2,-2,2,-2,1,-1,1,-1};
                    int numMovs = sizeof(movsX)/sizeof(movsX[0]);
                    for(int k=0;k<numMovs;k++){
                        Payload payload={board,i,j,i+movsX[k],j+movsY[k]};
                        validationFunction validationFunctions[]={isOutBounds,isPlayerTurn,isAPiece,isAValidMove,isThereAPieceOnTheWay,isAPieceBlockingTheWay,isOwnKingInCheck};
                        int numValidationFunctions=sizeof(validationFunctions)/sizeof(validationFunctions[0]);
                        
                        for(int i=0;i<numValidationFunctions;i++){
                            if(validationFunctions[i](&payload)==1){
                                if(board->squares[i+movsX[k]][j+movsY[k]].piece.type=='K' && board->squares[i][j].piece.player!=board->squares[i+movsX[k]][j+movsY[k]].piece.player){
                                    printf("Check! bishop at %d %d can check the king at %d %d \n",i+1,j+1,i+movsX[k]+1,j+movsY[k]+1);
                                }
                            }
                         }
                    }  
                }

                    

                }
            }
        }
        return 0;
    }

    int switchPlaces(Payload *payload){
        Board* board = payload->board;
        int x1=payload->x1,y1=payload->y1,x2=payload->x2,y2=payload->y2;
        printf("Moving %c from %d %d to %d %d\n",board->squares[x1-1][y1-1].piece.type,x1,y1,x2,y2);
        //square in position x2 and y2 gets the piece in position x1 and y1 
        board->squares[x2-1][y2-1].piece.type=board->squares[x1-1][y1-1].piece.type;
        board->squares[x2-1][y2-1].piece.player=board->squares[x1-1][y1-1].piece.player;
        board->squares[x2-1][y2-1].piece.timesMoved=board->squares[x1-1][y1-1].piece.timesMoved+1;
        //square in position x1 and y1 gets empty
        board->squares[x1-1][y1-1].piece.type=' ';
        board->squares[x1-1][y1-1].piece.player=3;
        board->squares[x1-1][y1-1].piece.timesMoved=0;
        board->playerTurn= board->playerTurn==1?2:1;   
    }
