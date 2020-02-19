using namespace std;

//lista de los carateres
class lst_caracteres {
public:
	char c;
	int index;
	lst_caracteres* sig;
	lst_caracteres* prev;
}*crc_primero,*crc_ultimo;

//cambios en lista
class log_cambios {
public:
	string buscada;
	string reempz;
	bool estado;
	int pos;
	log_cambios* sig;
	string cadena;
}*log_primero,*log_ultimo;

//cambios revertidos
class rev_cambios {
public:
	string buscada;//buscada
	string reempz;//reemplazada
	bool estado;
	int pos;
	rev_cambios* sig;
	string cadena;
}*rev_primero, *rev_ultimo;

//palabras buscadas
class busc {
public:
	string bus;
	string reemp;
	busc* sig;
}*busc_primero,*busc_ultimo;

//palabras reemplazadas
class reemplazadas {
public:
	string bus;
	string reemp;
	reemplazadas* sig;
}*reem_primero, *reem_ultimo;

//historial de los archivos
class historial {
public:
	string nombre;
	int id;
	string ruta;
	historial* sig;
}*his_primero,*his_ultimo;

class nx{
public:
	string txt;
}*prin;