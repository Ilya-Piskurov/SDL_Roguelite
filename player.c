#include "player.h"
#include "map.h"
#include "view.h"

void init_player( Player *player, char map[ ][ MAX_X ] )
{
    int y, x;
    do
    {
        y = 1 + ( rand() % ( MAX_Y - MAX_ROOM_HEIGHT - 1 ) );
        x = 1 + ( rand() % ( MAX_X - MAX_ROOM_WIDTH - 1 ) );
    } 
    while ( map[ y ][ x ] != ' ');

    player->y = y * TILE_SIZE;
    player->x = x * TILE_SIZE;
}