#include "map.h"

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

void destroy_game_map( Game_Map *game_map )
{
    SDL_DestroyTexture( game_map->floor_texture );
    SDL_DestroyTexture( game_map->wall_texture  );
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
    
    for ( int y = start_y; y < start_y + BRIDGE_WIDTH; y++ )
    {
        for ( int x = start_x; x <= end_x; x++ )
        {
            map[ y ][ x ] = ' ';
        }    
    }
    
    if ( start_y < end_y )
    {
        for ( int x = end_x; x < end_x + BRIDGE_WIDTH; x++ )
        {
            for ( int y = start_y; y <= end_y; y++ )
            {
                map[ y ][ x ] = ' ';
            }
        }
    }
    else 
    {
        for ( int x = end_x; x < end_x + BRIDGE_WIDTH; x++ )
        {
            for ( int y = start_y; y >= end_y; y-- ) 
            {
                map[ y ][ x ] = ' ';
            }
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

void generate_grid( Game_Map *game_map ) 
{
    set_map_of_null( game_map->grid, game_map->max_x, game_map->max_y );
    
    int current_bridge_x = -1, current_bridge_y = -1,
        previous_bridge_x, previous_bridge_y;
        
    for ( int rooms = 0; rooms < COUNT_OF_ROOMS; rooms++ )
    {    
        Coordinates_Point_Of_Bridge point = generate_one_room
        ( 
            game_map->grid, rooms
        );
               
        previous_bridge_y = current_bridge_y;
        previous_bridge_x = current_bridge_x;
                   
        current_bridge_y = point.y;
        current_bridge_x = point.x;
 
        if ( !is_first_room(previous_bridge_x, previous_bridge_y ) )
        {
            build_bridge
            (
                game_map->grid, game_map->max_x, game_map->max_y, 
                current_bridge_x, previous_bridge_x, 
                current_bridge_y, previous_bridge_y
            );
        }
    }
}

void debug_console_print_map( Game_Map *game_map )
{    
    for ( int y = 0; y < game_map->max_y; y++ )
    {
        for ( int x = 0; x < game_map->max_x; x++ )
        {
            putchar( game_map->grid[ y ][ x ] );
        }
        putchar( '\n' );
    }
    putchar( '\n' );
}

void init_game_map
( 
    Game_Map *game_map, int max_x, int max_y,
    char path_to_floor_img[], char path_to_wall_img[],
    SDL_Renderer *renderer 
) 
{
    game_map->max_x = max_x;
    game_map->max_y = max_y;

    generate_grid( game_map );

    game_map->floor_texture = load_image( path_to_floor_img, renderer );
    game_map->wall_texture  = load_image( path_to_wall_img, renderer );
}