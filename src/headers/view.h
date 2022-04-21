#ifndef VIEW_H
#define VIEW_H

/*-------------Libraries-------------*/
#include <SDL2/SDL.h>
#include <stdbool.h>

#include "model.h"
/*-------------Libraries-------------*/

/*-------------Constants-------------*/
#define SCALE 1
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
/*--------Func-Prototypes--------*/

#endif