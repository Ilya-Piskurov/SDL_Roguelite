#ifndef PLAYER_H
#define PLAYER_H

/*-------------Libraries-------------*/
#include <SDL2/SDL.h>
#include <stdlib.h>

/* FIX: Не нужен этот заголовок здесь. */

/* #include "map.h" */
/*-------------Libraries-------------*/

/*---------Typedef---------*/
typedef struct Player
{
    double x;
    double y;
} Player;
/*---------Typedef---------*/

/*--------Func-Prototypes--------*/
void init_player( Player *player, char map[ ][ MAX_X ] );
/*--------Func-Prototypes--------*/

#endif