#ifndef VIEW_H
#define VIEW_H

/*-------------Libraries-------------*/
#include <SDL2/SDL.h>
#include <stdbool.h>

#include "player.h"
#include "map.h"
/*-------------Libraries-------------*/

/*-------------Constants-------------*/
#define TILE_SIZE 16
#define BACKGROUND_COLOR 255, 255, 255
#define SCALE 3
/*-------------Constants-------------*/

/*--------Func-Prototypes--------*/
int game_sdl_run( );
SDL_Texture* load_image( char path[], SDL_Renderer *renderer );
void apply_surface
( 
    int x, int y, SDL_Texture *texture,
    SDL_Renderer *renderer
);
/*--------Func-Prototypes--------*/

#endif