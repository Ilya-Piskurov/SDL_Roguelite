//roguelite.c - Моя первая roguelite игра.

/*
 * TODO:
 * Написать генератор двумерной карты (подземелья) +
 * Исправить построение "мостов"                   +
 * Добавить графический вывод с SDL                +
 * Найти нормальную графику 32х32
 * Выводить игрока
 * Движения игрока (по примеру JS)
 * Коллизии (по примеру JS)
 * Разбить код по модулям ( map, view )
 */

/*-------------Libraries-------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
/*-------------Libraries-------------*/

/*-------------Constants-------------*/
#define MAX_X 60
#define MAX_Y 40
#define COUNT_OF_ROOMS 17

#define MAX_ROOM_HEIGHT 6
#define MAX_ROOM_WIDTH 6
#define MIN_ROOM_HEIGHT 2
#define MIN_ROOM_WIDTH 2

#define TILE_SIZE 16

const int 
    WIDTH = MAX_X * 16, 
    HEIGHT = MAX_Y * 16;
/*-------------Constants-------------*/

/*--------Func-Prototypes--------*/
void generate_map(char map[][ MAX_X ], int max_x, int max_y);
void print_map(char map[][ MAX_X ], int max_x, int max_y);
int game_sdl_run( char map[ ][ MAX_X ]);
/*--------Func-Prototypes--------*/

/*---------Typedef---------*/
typedef struct Coordinates_Point_Of_Bridge
{
    int x;
    int y;
} Coordinates_Point_Of_Bridge;
/*---------Typedef---------*/

int main( void )
{
    char map[ MAX_Y ][ MAX_X ];
    
    srand(time(NULL));
    
    generate_map(map, MAX_X, MAX_Y);
    print_map(map, MAX_X, MAX_Y);
    
    return game_sdl_run( map );
}

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

int game_sdl_run( char map[ ][ MAX_X ])
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

void debug_print_coordinates
(
    int top_y, int bottom_y, int left_x, 
    int right_x, int num_of_room
) 
{
    
    printf( "--------Room-#%d--------\n", num_of_room );
    printf( "top_y = %d\n", top_y );
    printf( "bottom_y = %d\n", bottom_y );
    printf( "left_x = %d\n", left_x );
    printf( "right_x = %d\n", right_x );
    printf( "--------Room-#%d--------\n\n", num_of_room );
}

Coordinates_Point_Of_Bridge generate_one_room
(
    char map[][ MAX_X ], int num_of_room
) 
{
    
    int top_y, bottom_y, left_x, right_x;
        
    top_y    = 1 + ( rand() % ( MAX_Y - MAX_ROOM_HEIGHT - 1 ) );
    left_x   = 1 + ( rand() % ( MAX_X - MAX_ROOM_WIDTH - 1 ) );
    bottom_y = top_y + ( MIN_ROOM_HEIGHT + ( rand() 
               % ( MAX_ROOM_HEIGHT - MIN_ROOM_HEIGHT ) ) );  
    right_x  = left_x + ( MIN_ROOM_WIDTH + ( rand() 
               % ( MAX_ROOM_WIDTH - MIN_ROOM_WIDTH ) ) );
              
    Coordinates_Point_Of_Bridge point; 
    point.y = top_y  + ( rand() % ( bottom_y - top_y ) );
    point.x = left_x + ( rand() % ( right_x  - left_x ) );
    
    /*         
    debug_print_coordinates(
        top_y, bottom_y, left_x, right_x, num_of_room
    );
    */

    for ( int y = top_y; y <= bottom_y; y++ )
    {
        for ( int x = left_x; x <= right_x; x++ )
        {
            map[ y ][ x ] = ' ';
        }
    }
    
    return point;
}

// map = {#}
void set_map_of_null( char map[][ MAX_X ], int max_x, int max_y )
{
    for ( int y = 0; y < max_y; y++ )
    {
        for ( int x = 0; x < max_x; x++ )
        {
            map[ y ][ x ] = '#';
        }
    }
}

void build_bridge
(
    char map[][MAX_X], int max_x, int max_y,
    int x1, int x2, int y1, int y2
) 
{
    int start_x, start_y, end_x, end_y;
            
    if ( x1 < x2 ) 
    {
        start_x = x1;
        start_y = y1;
        end_x   = x2;
        end_y   = y2;
    } 
    else 
    {
        start_x = x2;
        start_y = y2;
        end_x   = x1;
        end_y   = y1;
    }               
            
    for ( int x = start_x; x <= end_x; x++ )
    {
        map[ start_y ][ x ] = ' ';
    }
    
    if ( start_y < end_y )
    {
        for ( int y = start_y; y <= end_y; y++ )
        {
            map[ y ][ end_x ] = ' ';
        }
    } 
    else 
    {
        for ( int y = start_y; y >= end_y; y-- ) 
        {
            map[ y ][ end_x ] = ' ';
        }
    }
}

bool is_first_room( int x, int y ) 
{
    bool result;
    
    if ( x == -1 && y == -1 )
    {
        result = true;
    } 
    else 
    {
        result = false;
    }
    
    return result;
}

void generate_map( char map[][ MAX_X ], int max_x, int max_y ) 
{
    set_map_of_null( map, MAX_X, MAX_Y );
    
    int current_bridge_x = -1, current_bridge_y = -1,
        previous_bridge_x, previous_bridge_y;
        
    for ( int rooms = 0; rooms < COUNT_OF_ROOMS; rooms++ )
    {    
        Coordinates_Point_Of_Bridge point = generate_one_room(map, rooms);
               
        previous_bridge_y = current_bridge_y;
        previous_bridge_x = current_bridge_x;
                   
        current_bridge_y = point.y;
        current_bridge_x = point.x;
 
        if ( !is_first_room(previous_bridge_x, previous_bridge_y ) )
        {
            build_bridge
            (
                map, MAX_X, MAX_Y, current_bridge_x,
                previous_bridge_x, current_bridge_y, previous_bridge_y
            );
        }
    }
}

void print_map( char map[][MAX_X], int max_x, int max_y )
{    
    for ( int y = 0; y < max_y; y++ )
    {
        for ( int x = 0; x < max_x; x++ )
        {
            putchar(map[ y ][ x ]);
        }
        putchar('\n');
    }

    putchar('\n');
}
