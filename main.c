//roguelite.c - Моя первая roguelite игра.

/*
 * TODO:
 * Написать генератор двумерной карты (подземелья) +
 * Исправить построение "мостов"                   +
 * Добавить графический вывод с SDL                +
 * Найти нормальную графику 32х32                  +
 * Выводить игрока                                 +
 * Движения игрока (по примеру JS)
 * Коллизии (по примеру JS)
 * Разбить код по модулям ( map, view )            +
 * Скролл карты
 * Собрать структуры Plyaer и Map                  +
 * init_ функции должны возвращать указатель
 * Добавить возможность указывать ширину коридоров 
 */

/*-------------Libraries-------------*/
#include <stdlib.h>
#include <time.h>

#include "view.h"
/*-------------Libraries-------------*/

int main( int argc, char *argv[] )
{ 
    srand( time( NULL ) );
    
    return game_sdl_run( );
}