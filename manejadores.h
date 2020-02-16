using namespace std;
void in_lst(char c) {
	lst_caracteres* nuevo = new lst_caracteres();
	nuevo->c = c;
	int cx = 0;

	if (crc_primero!=nullptr)
	{
		crc_primero = crc_ultimo = nuevo;
		nuevo->index = 0;
	}
	else {
		cx = crc_ultimo->index;
		nuevo->index = ++cx;
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



void buscar_reemplazar(string busca, string nuevo) {
	int total = busca.length();
	bool x = false;
	string sum="";
	lst_caracteres* env=crc_primero;
	while(env!=nullptr){
		sum = sum + env->c;
		env=env->sig;
	}
	replaceAll(sum,nuevo,busca);
	truncar_lst();
	insertar_texto(sum);

}