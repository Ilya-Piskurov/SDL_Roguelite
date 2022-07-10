#ifndef MODEL_H
#define MODEL_H

/*-------------Libraries-------------*/
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
/*-------------Libraries-------------*/

/*-------------Constants-------------*/

/*---Generate-Room-Algoritm---*/
#define MAX_X 33 //35
#define MAX_Y 15 //25
#define COUNT_OF_ROOMS 7 //20
#define MAX_ROOM_HEIGHT 4 //7
#define MAX_ROOM_WIDTH 4 //7
#define MIN_ROOM_HEIGHT 3 //3
#define MIN_ROOM_WIDTH 3 //3
#define BRIDGE_WIDTH 2 //2
/*---Generate-Room-Algoritm---*/

/*---Texture---*/
#define FLOOR_TEXTURE_PATH  "../res/img/floor.bmp"
#define WALL_TEXTURE_PATH   "../res/img/wall.bmp"
#define PLAYER_TEXTURE_PATH "../res/img/hero.bmp"
#define PLAYER_TEXTURE_FRAME_1 "../res/img/hero1.bmp"
#define PLAYER_TEXTURE_FRAME_2 "../res/img/hero2.bmp"
#define PLAYER_TEXTURE_FRAME_3 "../res/img/hero3.bmp"
#define PLAYER_TEXTURE_FRAME_4 "../res/img/hero4.bmp"
#define BACKGROUND_COLOR 255, 255, 255
#define TILE_SIZE 16
/*---Texture---*/

/*---Player---*/
#define PLAYER_SPEED_Y 0.2
#define PLAYER_SPEED_X 0.2
/*---Player---*/
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
SDL_Texture* load_image( char path[], SDL_Renderer *renderer );
/*--------Func-Prototypes--------*/

#endif