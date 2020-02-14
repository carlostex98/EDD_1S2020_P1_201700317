#include <iostream>
#include <curses.h>
#include "clases.h"
using namespace std;
//area de estructuras o archivos
int main(int argc,char ** argv)
{
    initscr();
    int height, width, start_y, start_x;
    height = 60;
    width = 30;
    start_y = start_x = 2;


    WINDOW* win = newwin(height,width,start_y,start_x);
    refresh();

    box(win,0,0);
    wrefresh(win);
    int c = getch();
    endwin();

    //cout << "Hello World!\n";
    return 0;
}
