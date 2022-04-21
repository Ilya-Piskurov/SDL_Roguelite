#ifndef MODEL_H
#define MODEL_H

/*-------------Libraries-------------*/
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
/*-------------Libraries-------------*/

/*-------------Constants-------------*/
#define MAX_X 60          // 40 - 25
#define MAX_Y 30          // 20 - 15
#define COUNT_OF_ROOMS 25 // 20 - 10

#define MAX_ROOM_HEIGHT 7
#define MAX_ROOM_WIDTH 7
#define MIN_ROOM_HEIGHT 3
#define MIN_ROOM_WIDTH 3

#define BRIDGE_WIDTH 2

#define FLOOR_TEXTURE_PATH  "../res/img/floor.bmp"
#define WALL_TEXTURE_PATH   "../res/img/wall.bmp"
#define PLAYER_TEXTURE_PATH "../res/img/hero.bmp"

#define BACKGROUND_COLOR 255, 255, 255
#define TILE_SIZE 16
/*-------------Constants-------------*/

/*---------Typedef---------*/
typedef struct
{
    double x;
    double y;
    SDL_Texture *texture;
} Player;

typedef struct
{
    int max_x;
    int max_y;
    char grid[ MAX_Y ][ MAX_X ];
    SDL_Texture *floor_texture;
    SDL_Texture *wall_texture;
} Game_Map;

typedef struct
{
    Player   * m_Player;
    Game_Map * m_Game_Map;
} MODEL;

typedef struct
{
    int x;
    int y;
} Coordinates_Point_Of_Bridge;
/*---------Typedef---------*/

/*--------Func-Prototypes--------*/
MODEL * MODEL_init( SDL_Renderer * renderer );
void MODEL_destroy( MODEL * MODEL_object );
/*--------Func-Prototypes--------*/

#endif