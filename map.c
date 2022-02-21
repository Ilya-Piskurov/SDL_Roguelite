#include "map.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
