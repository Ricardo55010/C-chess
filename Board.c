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
    if(isOutBounds(x1,y1,x2,y2)==1){
        printf("isOutBounds\n");
        return 1;
    }

    if(isPlayerTurn(board,x1,y1)==1){
        printf("isNotPlayerTurn\n");
        return 1;
    }

    if(isAPiece(board,x1,y1)==1){
        printf("isnotPiece\n");
        return 1;
    }

    if(isAValidMove(board,x1,y1,x2,y2)==1){
        printf("isNotValidMove\n");
        return 1;
    }


    printf("Moving %c from %d %d to %d %d\n",board->squares[x1-1][y1-1].piece.type,x1,y1,x2,y2);
    board->squares[x2-1][y2-1].piece.type=board->squares[x1-1][y1-1].piece.type;
    board->squares[x2-1][y2-1].piece.player=board->squares[x1-1][y1-1].piece.player;
    board->squares[x1-1][y1-1].piece.type=' ';
    board->squares[x1-1][y1-1].piece.player=NULL;
    board->playerTurn= board->playerTurn==1?2:1;
    return 0;
}