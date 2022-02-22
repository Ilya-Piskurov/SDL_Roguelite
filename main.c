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
 * Разбить код по модулям ( map, view )            +
 * Убрать зависимость модуля view от map           -
 * Скролл карты
 * Собрать структуры Plyaer и Map
 */

/*-------------Libraries-------------*/
#include <stdlib.h>
#include <time.h>

#include "view.h"
#include "map.h"
/*-------------Libraries-------------*/

int main( void )
{
    char map[ MAX_Y ][ MAX_X ];
    
    srand( time( NULL ) );
    
    generate_map( map, MAX_X, MAX_Y );
    //print_map( map, MAX_X, MAX_Y );
    
    return game_sdl_run( map );
}