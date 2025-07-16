#include"movements.h"
#include"../rules/rules.h"
#include"../board/board.h"

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

    int lookForBothChecks(Payload *payload){
        Board* board = payload->board;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                
                if(board->squares[i][j].piece.type=='P'){
                    Payload payload={board,i,j,i+1,j+1};
                    validationFunction validationFunctions[]={isOutBounds,isPlayerTurn,isAPiece,isAValidMove,isThereAPieceOnTheWay,isAPieceBlockingTheWay,isOwnKingInCheck};
                    int numValidationFunctions=sizeof(validationFunctions)/sizeof(validationFunctions[0]);
                        
                    for(int i=0;i<numValidationFunctions;i++){
                            if(validationFunctions[i](&payload)==1){
                                if(board->squares[i+1][j+1].piece.type=='K' && board->squares[i][j].piece.player!=board->squares[i+1][j+1].piece.player){
                                    printf("Check! pawn at %d %d can check the king at %d %d \n",i+1,j+1,i+2,j+2);
                                }
                            }
                    }

                    Payload payload2={board,i,j,i+1,j-1};
                    validationFunction validationFunctions2[]={isOutBounds,isPlayerTurn,isAPiece,isAValidMove,isThereAPieceOnTheWay,isAPieceBlockingTheWay,isOwnKingInCheck};
                    int numValidationFunctions2=sizeof(validationFunctions2)/sizeof(validationFunctions2[0]);
                        
                    for(int i=0;i<numValidationFunctions2;i++){
                            if(validationFunctions2[i](&payload2)==1){
                                if(board->squares[i+1][j-1].piece.type=='K' && board->squares[i][j].piece.player!=board->squares[i+1][j-1].piece.player){
                                    printf("Check! pawn at %d %d can check the king at %d %d \n",i+1,j+1,i+2,j);
                                }
                            }
                    }

                    Payload payload3={board,i,j,i-1,j-1};
                    validationFunction validationFunctions3[]={isOutBounds,isPlayerTurn,isAPiece,isAValidMove,isThereAPieceOnTheWay,isAPieceBlockingTheWay,isOwnKingInCheck};
                    int numValidationFunctions3=sizeof(validationFunctions2)/sizeof(validationFunctions2[0]);
                        
                    for(int i=0;i<numValidationFunctions3;i++){
                            if(validationFunctions3[i](&payload3)==1){
                                if(board->squares[i-1][j-1].piece.type=='K' && board->squares[i][j].piece.player!=board->squares[i-1][j-1].piece.player){
                                    printf("Check! pawn at %d %d can check the king at %d %d \n",i+1,j+1,i,j);
                                }
                            }
                    }

                    Payload payload4={board,i,j,i-1,j+1};
                    validationFunction validationFunctions4[]={isOutBounds,isPlayerTurn,isAPiece,isAValidMove,isThereAPieceOnTheWay,isAPieceBlockingTheWay,isOwnKingInCheck};
                    int numValidationFunctions4=sizeof(validationFunctions4)/sizeof(validationFunctions4[0]);
                        
                    for(int i=0;i<numValidationFunctions4;i++){
                            if(validationFunctions4[i](&payload4)==1){
                                if(board->squares[i-1][j+1].piece.type=='K' && board->squares[i][j].piece.player!=board->squares[i-1][j+1].piece.player){
                                    printf("Check! pawn at %d %d can check the king at %d %d \n",i+1,j+1,i,j+2);
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
        board->squares[x2-1][y2-1].piece.type=board->squares[x1-1][y1-1].piece.type;
        board->squares[x2-1][y2-1].piece.player=board->squares[x1-1][y1-1].piece.player;
        board->squares[x2-1][y2-1].piece.timesMoved=board->squares[x1-1][y1-1].piece.timesMoved+1;
        board->squares[x1-1][y1-1].piece.type=' ';
        board->squares[x1-1][y1-1].piece.player=3;
        board->squares[x1-1][y1-1].piece.timesMoved=0;
        board->playerTurn= board->playerTurn==1?2:1;   
    }
