#include "Board.h"



int showBoard(Board* board){
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("| ------- |");
        }
        printf("\n");
        for(j=0;j<8;j++){

            switch (board->squares[i][j].piece.player)
            {
            case 1:
                 printf("| %d *%c* %d |",board->squares[i][j].x,board->squares[i][j].piece.type,board->squares[i][j].y);
                break;
            case 2:
                printf("| %d (%c) %d |",board->squares[i][j].x,board->squares[i][j].piece.type,board->squares[i][j].y);
                break;
            default:
                printf("| %d     %d |",board->squares[i][j].x,board->squares[i][j].y);
                break;
            }
            
        }
        printf("\n");
        for(j=0;j<8;j++){
            printf("| ------- |");
        }
        printf("\n");
    }
    return 0;
}

int initBoard(Board* board){
    int i,j;
    char piecesFirstLineOrder[] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            board->squares[i][j].x=i+1;
            board->squares[i][j].y=j+1;
            board->squares[i][j].piece.player = 3;
            board->squares[i][j].piece.type = ' ';
            board->squares[i][j].piece.timesMoved = 0;

            if(i==0 || i==1)
                board->squares[i][j].piece.player=1;
            else if (i==6 || i==7)
                board->squares[i][j].piece.player=2;

            if(i==1 || i==6){
                board->squares[i][j].piece.type='P';
            }
            else if(i==0 || i==7){
                board->squares[i][j].piece.type=piecesFirstLineOrder[j];
            }
                  
            
        }
    }
    board->playerTurn=1;
    return 0;
}

int movePiece(Board* board,int x1,int y1,int x2,int y2){
    
    Payload payload={board,x1,y1,x2,y2};

    validationFunction validationFunctions[]={isOutBounds,isPlayerTurn,isAPiece,isAValidMove,isThereAPieceOnTheWay};

    int numValidationFunctions=sizeof(validationFunctions)/sizeof(validationFunctions[0]);
    
    for(int i=0;i<numValidationFunctions;i++){
        if(validationFunctions[i](&payload)==1){
            return 1;
        }
    }



    printf("Moving %c from %d %d to %d %d\n",board->squares[x1-1][y1-1].piece.type,x1,y1,x2,y2);
    board->squares[x2-1][y2-1].piece.type=board->squares[x1-1][y1-1].piece.type;
    board->squares[x2-1][y2-1].piece.player=board->squares[x1-1][y1-1].piece.player;
    board->squares[x2-1][y2-1].piece.timesMoved=board->squares[x1-1][y1-1].piece.timesMoved+1;
    board->squares[x1-1][y1-1].piece.type=' ';
    board->squares[x1-1][y1-1].piece.player=3;
    board->squares[x1-1][y1-1].piece.timesMoved=0;
    board->playerTurn= board->playerTurn==1?2:1;
    return 0;
}