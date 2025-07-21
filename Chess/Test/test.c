#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../board/board.h"
#include "../menu/menu.h"

int testMenu(){
    FILE *f  = stdout;
    freopen("test.txt","w",stdout);
    printf("Test\n");
    Board* board = (Board*) malloc(sizeof(Board));
    int x1 = 0 , y1 = 0, x2 = 0, y2 = 0;
    int continueGame = 0;
    showMenu(board,&x1,&y1,&x2,&y2,&continueGame);
    freopen("CON", "w", stdout);
    printf("Screen\n");
    assert(1==1);
}
int main(){
    testMenu();
    printf("Test\n");

}