#ifndef MOVEMENTS_H
#define MOVEMENTS_H


struct Payload;
int pawnMovement(struct Payload* payload);
int rookMovement(struct  Payload* payload);
int knightMovement(struct Payload* payload);
int bishopMovement(struct Payload* payload);
int queenMovement(struct Payload* payload);
int kingMovement(struct Payload* payload);
int lookForBothChecks(struct Payload* payload);
int switchPlaces(struct Payload* payload);
#endif