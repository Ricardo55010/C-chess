#ifndef PIECE_H
#define PIECE_H

 enum PieceType {PAWN = 'P', KNIGHT = 'N', BISHOP = 'B', ROOK = 'R', QUEEN = 'Q', KING = 'K', EMPTY = ' '};
typedef struct Piece{
    enum PieceType type;
    int player;
    int timesMoved;
} Piece;

#endif