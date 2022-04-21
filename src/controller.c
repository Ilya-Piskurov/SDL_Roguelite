#include "headers/controller.h"

int CONTROLLER_game_run( void )
{
    /*---------Init-Part--------*/
    VIEW  * VIEW_object  = VIEW_init( );
    MODEL * MODEL_object = MODEL_init( VIEW_object->m_Renderer );
    /*---------Init-Part--------*/

    /*---------Draw-Part--------*/
    VIEW_draw_frame( VIEW_object, MODEL_object );
    /*---------Draw-Part--------*/

    /*------Event-Part------*/
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
    /*------Event-Part------*/

    /*----------Destroy-Part----------*/
    MODEL_destroy( MODEL_object );
    VIEW_destroy( VIEW_object );
    /*----------Destroy-Part----------*/
    
    return EXIT_SUCCESS;
}