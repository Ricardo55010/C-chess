#include "board.h"


/*Objective: Print the board highlighting the pieces with the piece player*/
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
                 printf("| %d *%c* %d |",board->squares[i][j].x,board->squares[i][j].piece.type,board->squares[i][j].y); // print player 1 piece
                break;
            case 2:
                printf("| %d (%c) %d |",board->squares[i][j].x,board->squares[i][j].piece.type,board->squares[i][j].y); // print player 2 piece
                break;
            default:
                printf("| %d     %d |",board->squares[i][j].x,board->squares[i][j].y); // print empty square
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

/*Objective: Initialize the board, it uses an array with the order of the pieces*/
int initBoard(Board* board){
    int i,j;
    char piecesFirstLineOrder[] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}; // array with the order of the pieces
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            //get the square position
            board->squares[i][j].x=i+1;
            board->squares[i][j].y=j+1;
            //initialize the piece with default values
            board->squares[i][j].piece.player = 3;
            board->squares[i][j].piece.type = ' ';
            board->squares[i][j].piece.timesMoved = 0;

            // define whose player the piece is
            if(i==0 || i==1)
                board->squares[i][j].piece.player=1;
            else if (i==6 || i==7)
                board->squares[i][j].piece.player=2;
            
            // define the type of the piece
            if(i==1 || i==6){
                board->squares[i][j].piece.type='P';
            }
            else if(i==0 || i==7){
                board->squares[i][j].piece.type=piecesFirstLineOrder[j]; // we use the array to avoid n ifs 
            }
                  
            
        }
    }
    board->playerTurn=1;
    board->playerInCheck=0;
    return 0;
}

/*Objective: Move a piece, it also validates the move with function pointers */
int movePiece(Board* board,int x1,int y1,int x2,int y2){
    
    Payload payload={board,x1,y1,x2,y2}; // we create the payload that will be passed to the functions

    validationFunction validationFunctions[]={isOutBounds,isPlayerTurn,isAPiece,isAValidMove,isThereAPieceOnTheWay,isAPieceBlockingTheWay,isOwnKingInCheck};// array with function pointers to validate the move

    int numValidationFunctions=sizeof(validationFunctions)/sizeof(validationFunctions[0]); // we get the size of the array
    
    for(int i=0;i<numValidationFunctions;i++){
        if(validationFunctions[i](&payload)==1){ // validate the move with each function pointer
            return 1;
        }
    }



    switchPlaces(&payload);
    isOpponentKingInCheck(&payload);
    isPawnPromotionPossible(&payload);
    return 0;
}