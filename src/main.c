//roguelite.c - Моя перша roguelite гра.

/*
 * TODO:
 * Написати генератор двовимірної карти            +
 * Виправити побудову "мостів"                     +
 * Додати графічний вивід (SDL)                    +
 * Малювати гравця на екрані                       +
 * Створити структури Player та Map                +
 * _init функції повинні повертати показжчик       +
 * Додати можливість вказувати ширину "мостів"     +
 * Додати можливість скейлу графіки                +
 * Перевірити що ширина "мостів" не переповнює     +
 * Структура файлів (додати папку src, headers)    +
 * Розташувати код по модулям (mvc)                +
 * Додати можливість рухатись
 * Зробити анімацію
 * Зробити колізії
 * Зробити скрол карти
 * Домалювати графіку
 * Додати мобів
 * Додати стрілянину
 * Додати переход на наступний рівень
 * Задокоментувати функції та модулі
 * Випустити першу версію серед друзів :)
 * ???
 * PROFIT!
 */

/*-------------Libraries-------------*/
#include <stdlib.h>
#include <time.h>

#include "headers/controller.h"
/*-------------Libraries-------------*/

int main( int argc, char *argv[] )
{ 
    srand( time( NULL ) );
    
    return CONTROLLER_game_run( );
}