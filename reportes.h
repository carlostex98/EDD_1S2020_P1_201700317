using namespace std;
void imprime_lista(){//reporte de la lista de chars
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
    system("dot -Tpng -O chars.dot");
    system("xdg-open chars.dot.png");
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
    system("dot -Tpng -O historial.dot");
    system("xdg-open historial.dot.png");
}

void reporte_ord_buscadas(){
    ofstream f("ord_buscadas.dot", ios::out | ios::binary);
    
    f << "digraph L { \n";
    f << "node [shape=record fontname=Arial]; \n";
    busc* visto=busc_primero;
    string d="";
    int i=0;
    while (visto!=nullptr)
    {
        d=visto->bus+to_string(i)+"[ label=\" "+visto->bus+" \\n Remplazada por:"+visto->reemp+" \" ]; \n";
        f<<d;
        if(visto->sig!=nullptr){
            d=visto->bus+to_string(i)+"->"+visto->sig->bus+to_string(i+1)+";\n";
        }
        visto=visto->sig;
    }
    f<<"}\n";
    f.close();
    system("dot -Tpng -O ord_buscadas.dot");
    system("xdg-open ord_buscadas.dot.png");
}

void reporte_ord_reemplazadas(){
    ofstream f("ord_reemplazadas.dot", ios::out | ios::binary);
    
    f << "digraph L { \n";
    f << "node [shape=record fontname=Arial]; \n";
    reemplazadas* visto=reem_primero;
    string d="";
    int i=0;
    while (visto!=nullptr)
    {
        d=visto->bus+to_string(i)+"[ label=\" "+visto->bus+" \\n Remplazo a:"+visto->reemp+" \" ]; \n";
        f<<d;
        if(visto->sig!=nullptr){
            d=visto->bus+to_string(i)+"->"+visto->sig->bus+to_string(i+1)+";\n";
        }
        visto=visto->sig;
    }
    f<<"}\n";
    f.close();

    system("dot -Tpng -O ord_reemplazadas.dot");
    system("xdg-open ord_reemplazadas.dot.png");
}

void reporte_log_cambios(){
    ofstream f("log_cambios.dot", ios::out | ios::binary);
    
    f << "digraph L { \n";
    f << "node [shape=record fontname=Arial]; \n";
    log_cambios* visto=log_primero;
    string d="";
    int i=0;
    while(visto != nullptr){
        d=to_string(i)+"[label= \" Palabra buscada:"+visto->buscada+"\\n R.por: "+visto->reempz+"\\n Estado:No revertido \\n Palabra:null \\nPosicion:null \"]; \n";
        f<<d;
        //relacion
        if(visto->sig!=nullptr){
            d=to_string(i)+"->"+to_string(i+1)+";\n";
            f<<d;
        }
        visto=visto->sig;
    }
    f<<"}\n";
    f.close();
    system("dot -Tpng -O log_cambios.dot");
    system("xdg-open log_cambios.dot.png");
}


void reporte_revertidos(){
    ofstream f("revertidos.dot", ios::out | ios::binary);
    
    f << "digraph L { \n";
    f << "node [shape=record fontname=Arial]; \n";
    rev_cambios* visto=rev_primero;
    string d="";
    int i=0;
    while(visto != nullptr){
        d=to_string(i)+"[label= \" Palabra buscada:"+visto->buscada+"\\n R.por: "+visto->reempz+"\\n Estado:Revertido \\n Palabra:null \\nPosicion:null \"]; \n";
        f<<d;
        //relacion
        if(visto->sig!=nullptr){
            d=to_string(i)+"->"+to_string(i+1)+";\n";
            f<<d;
        }
        visto=visto->sig;
    }
    f<<"}\n";
    f.close();
    system("dot -Tpng -O revertidos.dot");
    system("xdg-open revertidos.dot.png");

}