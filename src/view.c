#include "headers/view.h"

/*-------------Constants-------------*/
const int 
    WIDTH = MAX_X * TILE_SIZE * SCALE, 
    HEIGHT = MAX_Y * TILE_SIZE * SCALE;
/*-------------Constants-------------*/

/*--------Func-Prototypes--------*/
void draw_player( Player *player, SDL_Renderer *renderer );
void draw_game_map( Game_Map *game_map, SDL_Renderer *renderer );
void apply_surface
( 
    int x, int y, SDL_Texture *texture,
    SDL_Renderer *renderer
);
/*--------Func-Prototypes--------*/

/*-------------------VIEW-MAIN-------------------*/
VIEW * VIEW_init( )
{
    VIEW * VIEW_object;
    VIEW_object = ( VIEW * ) malloc( sizeof (VIEW) );

    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_Window *window = SDL_CreateWindow
    (
		"SDL_Roguelite", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
		WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI
	);

    if ( NULL == window )
    {
        printf( "SDL_CreateWindow error: %s\n", SDL_GetError( ) );
    }

    SDL_Renderer *renderer = SDL_CreateRenderer
    (
        window, -1, 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if ( NULL == renderer )
    {
        printf( "SDL_CreateRenderer error: %s\n", SDL_GetError( ) );
    }

    SDL_RenderSetScale(renderer, SCALE, SCALE);

    VIEW_object->m_Window   = window;
    VIEW_object->m_Renderer = renderer;

    return VIEW_object;
}

void VIEW_destroy( VIEW * VIEW_object )
{
    SDL_DestroyWindow( VIEW_object->m_Window );
    SDL_DestroyRenderer( VIEW_object->m_Renderer );
    SDL_Quit( );
}

void VIEW_draw_frame( VIEW * VIEW_object, MODEL * MODEL_object )
{
    SDL_RenderClear( VIEW_object->m_Renderer );

    draw_game_map( MODEL_object->m_Game_Map, VIEW_object->m_Renderer );
    draw_player( MODEL_object->m_Player, VIEW_object->m_Renderer );
    
    SDL_RenderPresent( VIEW_object->m_Renderer );
}
/*-------------------VIEW-MAIN-------------------*/

/*-------------------HELP-FUNC-------------------*/
void draw_player( Player *player, SDL_Renderer *renderer )
{
    apply_surface( player->x, player->y, player->texture, renderer );
}

void draw_game_map( Game_Map *game_map, SDL_Renderer *renderer )
{
    for ( int y = 0; y < game_map->max_y; y++ )
    {
        for ( int x = 0; x < game_map->max_x; x++)
        {
            if ( game_map->grid[ y ][ x ] == '#')
            {
                apply_surface( x * TILE_SIZE, y * TILE_SIZE, game_map->wall_texture, renderer );
            }
            if ( game_map->grid[ y ][ x ] == ' ')
            {
                apply_surface( x * TILE_SIZE, y * TILE_SIZE, game_map->floor_texture, renderer );
            }
        }
    }
}

void apply_surface
( 
    int x, int y, SDL_Texture *texture,
    SDL_Renderer *renderer
)
{
    SDL_Rect position;
    position.x = x;
    position.y = y;
    SDL_QueryTexture( texture, NULL, NULL, &position.w, &position.h );
    SDL_RenderCopy( renderer, texture, NULL, &position );
}
/*-------------------HELP-FUNC-------------------*/