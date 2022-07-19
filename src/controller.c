#include "headers/controller.h"

int CONTROLLER_game_run( void )
{
    /*---------Init-Part--------*/
    VIEW  * VIEW_object  = VIEW_init( );
    MODEL * MODEL_object = MODEL_init( VIEW_object->m_Renderer );
    /*---------Init-Part--------*/

    /*------Event-Part------*/
    unsigned int lastTime, currentTime;
    double currentFrame = 0;
    lastTime = SDL_GetTicks();

    SDL_Event windowEvent;
    while ( true )
    {
        lastTime = currentTime;
        currentTime = SDL_GetTicks();
        unsigned int deltaTime = currentTime - lastTime;
        currentFrame += deltaTime * ANIMATION_SPEED;
        if ( currentFrame > 3 ) { currentFrame = 0; }
        MODEL_Player_set_frame_for_animation( VIEW_object, MODEL_object, currentFrame);

        if ( SDL_PollEvent( &windowEvent ) )
        {
            if ( SDL_QUIT == windowEvent.type )
            {
                break;
            }
        }

        if ( windowEvent.type == SDL_KEYDOWN )
        {
            if ( windowEvent.key.keysym.sym == SDLK_UP )
            {
                MODEL_object->m_Player->y -= PLAYER_SPEED_Y * deltaTime;
            }
            if ( windowEvent.key.keysym.sym == SDLK_DOWN )
            {
                MODEL_object->m_Player->y += PLAYER_SPEED_Y * deltaTime;
            }
            if ( windowEvent.key.keysym.sym == SDLK_RIGHT )
            {
                MODEL_object->m_Player->x += PLAYER_SPEED_X * deltaTime;
            }
            if ( windowEvent.key.keysym.sym == SDLK_LEFT )
            {
                MODEL_object->m_Player->x -= PLAYER_SPEED_X * deltaTime;
            }
        }

        /*---------Draw-Part--------*/
        VIEW_draw_frame( VIEW_object, MODEL_object );
        /*---------Draw-Part--------*/
    }
    /*------Event-Part------*/

    /*----------Destroy-Part----------*/
    MODEL_destroy( MODEL_object );
    VIEW_destroy( VIEW_object );
    /*----------Destroy-Part----------*/
    
    return EXIT_SUCCESS;
}