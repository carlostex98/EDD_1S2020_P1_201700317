#include <iostream>
#include <ncurses.h>
#include <string>
#include <fstream>
using namespace std;
#include "clases.h"
#include "manejadores.h"
#include "reportes.h"

//area de estructuras o archivos
int main()
{
    //string a="mi nomb c";
    //string b="c";
    //string e="x";
    //replaceAll(var,from,to);
    //const char *c=a.c_str();
    insertar_texto("mi casa es bonita");
    buscar_reemplazar("casa","novia");
    imprime_lista();
    initscr();
    printw("59");
    refresh();
    getch();
    endwin();
    return 0;
}
