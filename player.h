#ifndef PLAYER_H
#define PLAYER_H

/*-------------Libraries-------------*/
#include <SDL2/SDL.h>
#include <stdlib.h>

#include "map.h"
#include "view.h"
/*-------------Libraries-------------*/

/*---------Typedef---------*/
typedef struct Player
{
    double x;
    double y;
    SDL_Texture *texture;
} Player;
/*---------Typedef---------*/

/*--------Func-Prototypes--------*/
void init_player
( 
    Player *player, Game_Map *game_map,
    char path[], SDL_Renderer *renderer
);
void destroy_player( Player *player );
/*--------Func-Prototypes--------*/

#endif