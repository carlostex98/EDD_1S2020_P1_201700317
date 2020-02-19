using namespace std;
string get_txt(){
	nx* n =prin;
	return n->txt;
}
void set_txt(string tt){
	nx* n=prin;
	n->txt=tt;
}

void in_lst(char c) {
	lst_caracteres* nuevo = new lst_caracteres();
	nuevo->c = c;
	int cx = 0;

	if (crc_primero==nullptr)
	{
		crc_primero = crc_ultimo = nuevo;
		nuevo->index = 0;
	}
	else {
		cx = crc_ultimo->index;
		cx++;
		nuevo->index = cx;
		crc_ultimo->sig = nuevo;
		nuevo->prev = crc_ultimo;
		crc_ultimo = nuevo;
	}
}

void truncar_lst() {
	crc_primero = crc_ultimo = nullptr;
}

void insertar_texto(string inlet) {
	truncar_lst();
	for (int i = 0; i < inlet.length(); i++)
	{
		in_lst(inlet.at(i));
	}
}

void push_cambios(string cadena_a,string buscada,string reemplazada){
	log_cambios* nuevo = new log_cambios();
	nuevo->cadena=cadena_a;
	nuevo->buscada=buscada;
	nuevo->reempz=reemplazada;
	if(log_primero==nullptr){
		log_primero=log_ultimo=nuevo;
	}else{
		nuevo->sig=log_primero;
		log_primero=nuevo;
	}

}

log_cambios* pop_cambios(){
	log_cambios* enviar = new log_cambios();
	if(log_primero!=nullptr){
		if(log_primero->sig==nullptr){
			enviar=log_primero;
			log_primero = log_ultimo = nullptr;
		}else{
			enviar=log_primero;
			log_primero=log_primero->sig;
		}
	}else{
		enviar=nullptr;
	}

	return enviar;
}

void push_revertidos(){//pasa de pop
	log_cambios* ent = pop_cambios();
	rev_cambios* nuevo = new rev_cambios();


	if(ent!=nullptr){//para evitar una excepcion
		nuevo->buscada=ent->buscada;
		nuevo->cadena=ent->cadena;
		//nuevo->palabra=ent->palabra;
		nuevo->estado=true;
		set_txt(ent->cadena);//retornamos el texto a la variable global
		if(rev_primero==nullptr){
			rev_primero = rev_ultimo = nuevo;
		}else{
			nuevo->sig=rev_primero;
			rev_primero = nuevo;
		}
	}
}

void pop_revertidos(){
	//it means ctrl + y
	//quitamos y mandamos
	rev_cambios* mover=new rev_cambios();
	mover = rev_primero;
	if(rev_primero!=nullptr){
		push_cambios(mover->cadena,mover->buscada,mover->reempz);
		set_txt(mover->cadena);
		if(mover->sig==nullptr){
			rev_primero = rev_ultimo = nullptr;
			free(mover);
		}else{
			rev_primero=mover->sig;
			mover->sig=nullptr;
			free(mover);
		}
	}


}




void replaceAll(string& str, const string& from, const string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
		//here goes the co add to a list to stepecify te position of the searched word
    }
}


void buscar_reemplazar(string busca, string nuevo) {
	string sum="";
	lst_caracteres* env=crc_primero;
	while(env!=nullptr){
		sum = sum + env->c;
		env=env->sig;
	}
	push_cambios(sum,busca,nuevo);
	replaceAll(sum,busca,nuevo);
	truncar_lst();
	insertar_texto(sum);
	set_txt(sum);

}

string nomb_extract(string ruta){
	string n="";
	for (int i = ruta.length()-1; i != -1; i--)
	{
		if(ruta.at(i)=='/'){
			break;
		}else{
			n=n+ruta.at(i);
		}
	}
	return n;
}

void add_archivos(string ruta){
	historial* nuevo=new historial();
	nuevo->ruta=ruta;
	nuevo->nombre=nomb_extract(ruta);
	int id=0;
	if(his_primero==nullptr){
		nuevo->id=0;
		his_primero=his_ultimo=nuevo;
		nuevo->sig=his_primero;
	}else{
		id=his_ultimo->id;
		id++;
		nuevo->id=id;
		his_ultimo->sig=nuevo;
		his_ultimo=nuevo;
		nuevo->sig=his_primero;
	}

}

void ord_buscadas(string busq,string reemp){
	busc* nuevo=new busc();
	nuevo->bus=busq;
	nuevo->reemp=reemp;
	if(busc_primero==nullptr){
		busc_primero = busc_ultimo = nuevo;
	}else{
		busc* visto = busc_primero;
		busc* aux=busc_primero;
		while(true){
			if(busq.compare(visto->bus)<0){
				//si es mas pequenio
				if(visto==busc_primero){
					nuevo->sig=busc_primero;
					busc_primero=nuevo;
					
				}else{
					aux->sig=nuevo;
					nuevo->sig=visto;
				}
				break;
			}
			if(visto==busc_ultimo){
				busc_ultimo->sig=nuevo;
				busc_ultimo=nuevo;
				break;
			}
			aux=visto;
			visto=visto->sig;
		}
	}
}

void ord_reemplazadas(string busq,string reemp){
	reemplazadas* nuevo=new reemplazadas();
	nuevo->bus=busq;
	nuevo->reemp=reemp;
	if(reem_primero==nullptr){
		reem_primero = reem_ultimo = nuevo;
	}else{
		reemplazadas* visto = reem_primero;
		reemplazadas* aux=reem_primero;
		while(true){
			if(reemp.compare(visto->reemp)<0){
				//si es mas pequenio
				if(visto==reem_primero){
					nuevo->sig=reem_primero;
					reem_primero=nuevo;
					
				}else{
					aux->sig=nuevo;
					nuevo->sig=visto;
				}
				break;
			}
			if(visto==reem_ultimo){
				reem_ultimo->sig=nuevo;
				reem_ultimo=nuevo;
				break;
			}
			aux=visto;
			visto=visto->sig;
		}
	}
}

void ctrl_z(){
	push_revertidos();
}

void ctrl_y(){
	pop_revertidos();
}

void init_x(){
	nx* nuevo = new nx();
	nuevo->txt = "";
	prin=nuevo;
}

void uncat(string p){
	string a="";
	string b="";
	string aux="";
	int c=0;
	for (int i = 0; i < p.length(); i++)
	{
		if(p.at(i)==';'){
			c=i+1;
			break;
			
		}else{
			a+=p.at(i);
		}
	}

	for (int i = c; i < p.length(); i++)
	{
		b+=p.at(i);
	}
	buscar_reemplazar(a,b);
	

}



