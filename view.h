#ifndef VIEW_H
#define VIEW_H

/*-------------Libraries-------------*/
#include <SDL2/SDL.h>
#include <stdbool.h>

#include "map.h"
#include "player.h"
/*-------------Libraries-------------*/

/*-------------Constants-------------*/
#define TILE_SIZE 32
/*-------------Constants-------------*/

/*--------Func-Prototypes--------*/
int game_sdl_run( char map[ ][ MAX_X ] );
/*--------Func-Prototypes--------*/

#endif