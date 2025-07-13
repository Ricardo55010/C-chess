#ifndef SQUARE_H
#define SQUARE_H
#include "../piece/piece.h"
typedef struct Square{
    int x;
    int y;
    Piece piece;
} Square;
#endif