#include "view.h"

/*-------------Constants-------------*/
const int 
    WIDTH = MAX_X * TILE_SIZE, 
    HEIGHT = MAX_Y * TILE_SIZE;
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

int game_sdl_run( )
{
    /*---------Init-Part--------*/
    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_Window *window = SDL_CreateWindow
    (
		"SDL_Roguelite", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
		WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI
	);

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

    Game_Map game_map;
    init_game_map
    ( 
        &game_map, MAX_X, MAX_Y, 
        "./res/img/floor.bmp", "./res/img/wall.bmp", 
        renderer 
    );
    Player player;
    init_player( &player, &game_map, "./res/img/hero.bmp", renderer );
    /*---------Init-Part--------*/

    /*---------Draw-Part--------*/
    SDL_RenderClear( renderer );

    draw_game_map( &game_map, renderer );
    draw_player( &player, renderer );
    
    SDL_RenderPresent( renderer );

    //SDL_Delay(2000);
    /*---------Draw-Part--------*/

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
    
    /*----------Destroy-Part----------*/
    destroy_player( &player );
    destroy_game_map( &game_map );

    SDL_DestroyWindow( window );
    SDL_DestroyRenderer( renderer );
    SDL_Quit( );
    /*----------Destroy-Part----------*/
    
    return EXIT_SUCCESS;
}