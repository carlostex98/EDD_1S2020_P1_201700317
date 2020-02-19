#include <iostream>
#include <ncurses.h>
#include <string>
#include <fstream>
using namespace std;
#include "clases.h"
#include "manejadores.h"
#include "reportes.h"
#define CTRL_KEYPRESS(k) ((k)  & 0x1f)
//area de estructuras o archivos
int main()
{
    init_x();
    //string a="mi nomb c";
    //string b="c";
    //string e="x";
    //replaceAll(var,from,to);
    //const char *c=a.c_str();
    //insertar_texto("mi casa es bonita");
    //buscar_reemplazar("casa","novia");
    //imprime_lista();
    string msj_b="Universidad de San Carlos de Guatemala\nFacultad de ingenieria\nEstructura de datos\nPractica 1\nCarlos Alejandro Tenes Mejia\n201700317 \n\n";
    msj_b+="Menu:\n1.Crear Archivo\n2.Abrir archivo\n3.Archivos recientes\n4.Salir\n\n";
    string a="1.Lista caracteres\n2.Palabras buscadas\n3.Palabras ordenadas";
    string b="Palabra a buscar; palabra a reemplazar\n";
    string aux2="";
    const char *cx=msj_b.c_str();
    const char *vv="";
    string aux="";
    char e='0';
    initscr();
    int c;
    char n='0';
    string h="";
    while(true){
        erase();
        switch (e)
        {
            case '0':
            /* code */
                move(0,0);
                printw(cx);
                refresh();
                
                break;

            case '1':
            /* code */
                move(0,0);
                //aux="edicion de archivo \n"+cx;
                printw( aux.c_str());
                refresh();
                break;
            case '2':
                //abrir archivo
                break;
            case '3':
            /* code */
                break;
            case '4':
            /* code */
                break;
            default:
            break;
        }
        
        if(c==27){
            break;
        }

        /*move(0,0);
        printw(cx);
        refresh();
        

        c=getch();
        if(c==27){
            break;
        }*/
        c=getch();
        e=c;
        if (e='1'){
            
            if(c==127){
                aux.pop_back();
                insertar_texto(aux);
            }else if(c==CTRL_KEYPRESS('t')){//atras
                ctrl_z();
            }else if(c==CTRL_KEYPRESS('n')){//rep[ortes]
                //reportes
                erase();
                printw(a.c_str());
                refresh();
                n=getch();
                if(n=='1'){
                    imprime_lista();
                }
                if(n=='2'){
                    reporte_log_cambios();
                    reporte_revertidos();
                }
                if(n=='3'){
                    reporte_ord_buscadas();
                    reporte_ord_reemplazadas();
                }


            }else if(c==CTRL_KEYPRESS('y')){//adelante
                ctrl_y();
            }
            else if(c==CTRL_KEYPRESS('u')){//regresar
                e='0';
            }
            else if(c==CTRL_KEYPRESS('f')){//busq y reemp
                //para buscar y reemplazar
                aux2="";
                erase();
                while(true){
                    n=getch();
                    if(n=='\n'){
                        uncat(aux2);
                        aux=get_txt();
                        break;
                        //execute replacement
                        
                    }else{
                        aux2+=n;
                        erase();
                        printw(aux2.c_str());
                        refresh();
                        
                    }
                }


                

            }
            
            
            else{
                aux+=c;
                insertar_texto(aux);
            }
        }
    }
    
    

    endwin();
    return 0;
}
