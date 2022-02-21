#include "view.h"

/*-------------Libraries-------------*/
#include "map.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
/*-------------Libraries-------------*/

/*-------------Constants-------------*/
#define TILE_SIZE 16

const int 
    WIDTH = MAX_X * 16, 
    HEIGHT = MAX_Y * 16;
/*-------------Constants-------------*/

SDL_Texture* load_image( char path[], SDL_Renderer *renderer )
{
    SDL_Surface *loaded_image = NULL;
    SDL_Texture *texture      = NULL;

    loaded_image = SDL_LoadBMP( path );

    if ( loaded_image != NULL )
    {
        texture = SDL_CreateTextureFromSurface
        (
            renderer, loaded_image
        );
        if ( NULL == texture )
        {
            printf( "SDL_CreateTextureFromSurface error: %s\n", SDL_GetError( ) );
        }
        SDL_FreeSurface( loaded_image );
    }
    else
    {
        printf( "SDL_LoadBMP error: %s\n", SDL_GetError( ) );
    }

    return texture;
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

int game_sdl_run( char map[ ][ MAX_X ] )
{
    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_Window *window = SDL_CreateWindow
    (
		"Hello SDL World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
		WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI
	);
    // Check that the window was successfully created
    if ( NULL == window )
    {
        printf( "SDL_CreateWindow error: %s\n", SDL_GetError( ) );
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer
    (
        window, -1, 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if ( NULL == renderer)
    {
        printf( "SDL_CreateRenderer error: %s\n", SDL_GetError( ) );
        return 1;
    }

    SDL_Texture *wall_texture  = load_image( "./res/img/wall.bmp", renderer );
    SDL_Texture *floor_texture = load_image( "./res/img/floor.bmp", renderer );

    SDL_RenderClear( renderer );
    /*print_map*/
    for ( int y = 0; y < MAX_Y; y++ )
    {
        for ( int x = 0; x < MAX_X; x++)
        {
            if ( map[ y ][ x ] == '#')
            {
                apply_surface( x * TILE_SIZE, y * TILE_SIZE, wall_texture, renderer );
            }
            if ( map[ y ][ x ] == ' ')
            {
                apply_surface( x * TILE_SIZE, y * TILE_SIZE, floor_texture, renderer );
            }
        }
    }
    /*print_map*/
    SDL_RenderPresent( renderer );

    SDL_Delay(2000);
    
    SDL_Event windowEvent;
    
    while ( true )
    {
        if ( SDL_PollEvent( &windowEvent ) )
        {
            if ( SDL_QUIT == windowEvent.type )
            {
                break;
            }
        }
    }
    
    SDL_DestroyWindow( window );
    SDL_DestroyRenderer( renderer );
    SDL_DestroyTexture( wall_texture );
    SDL_Quit( );
    
    return EXIT_SUCCESS;
}