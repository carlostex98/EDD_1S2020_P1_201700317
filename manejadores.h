using namespace std;
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

void cambio_edd_reemp(){

}



void buscar_reemplazar(string busca, string nuevo) {
	string sum="";
	lst_caracteres* env=crc_primero;
	while(env!=nullptr){
		sum = sum + env->c;
		env=env->sig;
	}
	replaceAll(sum,busca,nuevo);
	truncar_lst();
	insertar_texto(sum);

}

void add_archivos(string ruta){
	historial* nuevo=new historial();
	nuevo->ruta=ruta;
	nuevo->nombre=ruta;
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
	
	if(busc_primero==nullptr){

	}
}