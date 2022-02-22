#ifndef VIEW_H
#define VIEW_H

/*-------------Libraries-------------*/
#include <stdbool.h>

/* Forward declarations */
typedef struct SDL_Renderer SDL_Renderer;
typedef struct SDL_Texture SDL_Texture;

/* #include "map.h"
#include "player.h" */
/*-------------Libraries-------------*/

/*-------------Constants-------------*/
#define TILE_SIZE 32
/*-------------Constants-------------*/

/*--------Func-Prototypes--------*/
int game_sdl_run( );
SDL_Texture* load_image( char path[], SDL_Renderer *renderer );
/*--------Func-Prototypes--------*/

#endif