#ifndef MENU_H
#define MENU_H 

struct Board; // Forward declaration to avoid circular dependency
void getStartPositionMessage(int* x1,int* y1);
void getEndPositionMessage(int* x2,int* y2);
void showPlayerTurnMessage(struct Board* board);
void showContinueMessage(int* continueGame);
int showMenu(struct Board* board,int* x1,int* y1,int* x2,int* y2,int* continueGame);

#endif