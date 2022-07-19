#ifndef VIEW_H
#define VIEW_H

/*-------------Libraries-------------*/
#include <SDL2/SDL.h>
#include <stdbool.h>

#include "model.h"
/*-------------Libraries-------------*/

/*-------------Constants-------------*/
#define SCALE 3
#define ANIMATION_SPEED 0.006
/*-------------Constants-------------*/

typedef struct
{
    SDL_Window   * m_Window;
    SDL_Renderer * m_Renderer;
} VIEW;

/*--------Func-Prototypes--------*/
VIEW * VIEW_init( );
void VIEW_destroy( VIEW * VIEW_object );
void VIEW_draw_frame( VIEW * VIEW_object, MODEL * MODEL_object );
void MODEL_Player_set_frame_for_animation
( 
    VIEW * VIEW_object, MODEL * MODEL_object, double currentFrame 
);
/*--------Func-Prototypes--------*/

#endif