#ifndef MAP_H
#define MAP_H

/*-------------Libraries-------------*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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

/*--------Func-Prototypes--------*/
void generate_map(char map[][ MAX_X ], int max_x, int max_y);
void print_map(char map[][ MAX_X ], int max_x, int max_y);
/*--------Func-Prototypes--------*/

/*---------Typedef---------*/
typedef struct Coordinates_Point_Of_Bridge
{
    int x;
    int y;
} Coordinates_Point_Of_Bridge;
/*---------Typedef---------*/

#endif