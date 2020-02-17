using namespace std;
void imprime_lista()
{
    //generamos los reportes
    ofstream f("chars.dot", ios::out | ios::binary);
    
    f << "digraph L { \n";
    f << "node [shape=record fontname=Arial]; \n";
    lst_caracteres* visto=crc_primero;
    string d="";
    while(visto!=nullptr){
        //nodo, relacion
        d=visto->c+to_string(visto->index)+"[label=\" "+visto->c+" \"]; \n";
        f<<d;
        if(visto->sig!=nullptr){
            d=visto->c+to_string(visto->index)+"->"+visto->sig->c+to_string(visto->sig->index)+"\n";
            f<<d;
        }

        if(visto->prev!=nullptr){
            d=visto->c+to_string(visto->index)+"->"+visto->prev->c+to_string(visto->prev->index)+"\n";
            f<<d;
        }

        visto=visto->sig;
    }
    f<<"}\n";
    f.close();
}
void reporte_historial(){
    ofstream f("historial.dot", ios::out | ios::binary);
    
    f << "digraph L { \n";
    f << "node [shape=record fontname=Arial]; \n";
    historial* visto=his_primero;
    string d="";
    while (true)
    {
        d=visto->id+"[label=\" "+visto->nombre+"\\n"+visto->ruta+" \"]; \n";
        f<<d;
        d=to_string(visto->id) +"->"+ to_string(visto->sig->id) +";\n";
        f<<d;
        if(visto->sig==his_primero){
            break;
        }
    }
    

    f<<"}\n";
    f.close();
}