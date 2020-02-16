#include <iostream>
#include <ncurses.h>
#include <string>
using namespace std;
#include "clases.h"
#include "manejadores.h"

//area de estructuras o archivos
int main()
{
    //string a="mi nomb c";
    //string b="c";
    //string e="x";
    //replaceAll(var,from,to);
    //const char *c=a.c_str();

    initscr();
    printw("59");
    refresh();
    getch();
    endwin();
    return 0;
}
