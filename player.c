#include "player.h"

void init_player
(
    Player *player, Game_Map *game_map,
    char path[], SDL_Renderer *renderer 
)
{
    player->texture = load_image( path, renderer );

    int y, x;
    do
    {
        y = 1 + ( rand() % ( MAX_Y - MAX_ROOM_HEIGHT - 1 ) );
        x = 1 + ( rand() % ( MAX_X - MAX_ROOM_WIDTH - 1 ) );
    } 
    while ( game_map->grid[ y ][ x ] != ' ');

    player->y = y * TILE_SIZE;
    player->x = x * TILE_SIZE;
}

void draw_player( Player *player, SDL_Renderer *renderer )
{
    apply_surface( player->x, player->y, player->texture, renderer );
} 

void destroy_player( Player *player )
{
    SDL_DestroyTexture( player->texture );
}