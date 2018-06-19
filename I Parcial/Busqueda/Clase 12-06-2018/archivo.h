using namespace std;

template <class T>

class archivo{
	
	char nom[40];
	T buf;
	fstream obj;
	
	public:
		
		archivo(){}
		archivo(char *c){ strcpy(nom,c); }
		void abrir() { obj.open(nom,ios::in); }
		void cerrar() { obj.close();}
		T get_buf() { return buf; }
		bool es_fin() { return obj.eof(); }
		void leer( char cad[] ){ obj.getline(cad,180,'\n'); }
		void convertir(char cad[], T(*f)(char *k)){ buf = f(cad); }
		
		
	
};
