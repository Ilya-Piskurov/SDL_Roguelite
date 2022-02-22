#ifndef MAP_H
#define MAP_H

/*-------------Libraries-------------*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct SDL_Renderer SDL_Renderer;

/*-------------Libraries-------------*/

/*-------------Constants-------------*/
#define MAX_X 50
#define MAX_Y 30
#define COUNT_OF_ROOMS 17

#define MAX_ROOM_HEIGHT 6
#define MAX_ROOM_WIDTH 6
#define MIN_ROOM_HEIGHT 2
#define MIN_ROOM_WIDTH 2
/*-------------Constants-------------*/

/*---------Typedef---------*/
typedef struct Game_Map
{
    int max_x;
    int max_y;
    char grid[ MAX_Y ][ MAX_X ];
    SDL_Texture *floor_texture;
    SDL_Texture *wall_texture;
} Game_Map;

typedef struct
{
    int x;
    int y;
} Coordinates_Point_Of_Bridge;
/*---------Typedef---------*/

/*-------------Libraries-------------*/
#include "view.h"
/*-------------Libraries-------------*/

/*--------Func-Prototypes--------*/
void generate_grid( Game_Map *game_map );
void debug_console_print_map(char map[][ MAX_X ], int max_x, int max_y);
void init_game_map
( 
    Game_Map *game_map, int max_x, int max_y,
    char path_to_floor_img[], char path_to_wall_img[],
    SDL_Renderer *renderer 
);
void destroy_game_map( Game_Map *game_map );
/*--------Func-Prototypes--------*/

#endif