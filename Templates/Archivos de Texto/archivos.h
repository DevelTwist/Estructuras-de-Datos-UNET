/*******************************
*  Luis Fernando Vargas Gómez  *
*		    18-06-2018         *
********************************/

#ifndef archivosH
#define archivosH

#include <fstream>

using namespace std;

template <class T>

class archivo{
	
	private:
	
	char nom[40];
	T buf;
	fstream obj;
	
	
	public:
		
		/* Metodos Personales */
		archivo(){} // Constructor Defecto
		archivo(char *c); // Constructor Parametrico
		void abrirEnLectura(); // Abre el archivo en modo de lectura.
		void abrirEnEscritura(); // Abre el archivo en modo de escritura.	
		void crearArchivo(); // Crear Archivo con el Nombre asignado en setReferencia en modo escritura
		void escribirEnArchivo(char *text,bool saltoLinea = false); // Escribe Texto en el archivo en la ultima linea.
		void leerLinea(char cad[]); // Leer linea de un archivo
		void escribirEn(char *text, int puntero, int posicion, bool saltoLinea = false); // Escribe en una posicion asignada del Archivo
		void leerEn(int puntero, int posicion); // Lee el Archivo en la Posicion Asignada.
		
		/* Metodos Propuestos en Clase */
		T get_buf() { return buf; } // Retorna un dato de Tipo T
		void convertir(char cad[], T(*f)(char *k)){ buf = f(cad); } // Funcion
		bool es_fin(); // Verificar si estamos en el final del archivo 
		void cerrar(); // Cerrar el Archivo
		
		/* Getters y Setters */
		char *getNom(){ return this->nom; } // Retornar Nombre del Archivo
		void setReferencia(char *c); // Para saber a que archivo hacer referencia
		int getPosLectura() { return this->obj.tellg(); } // Devuelve la posicion Actual del puntero en modo de lectura (Debe estar abierto el archivo)
		int getPosEscritura() { return this->obj.tellp(); } // Devuelve la posicion Actual del puntero en modo de Escritura (Debe estar abierto el archivo)
};
/*
	Constructor parametrico template
*/
template <class T>
archivo<T>::archivo(char *c){ 
	strcpy(this->nom,c); 
}
/*
	Para saber a que archivo hacer referencia
*/
template <class T>
void archivo<T>::setReferencia(char *c){
   strcpy(this->nom,c); 
}
/*
	Abre el archivo en modo de lectura.
*/
template <class T>
void archivo<T>::abrirEnLectura(){
	obj.open(this->nom,ios::in); 
	if (obj.fail())  { 
	cout << "Error al abrir el archivo"; 
	exit(1);  }
}
/*
	Abre el Archivo en modo de escritura.
*/
template <class T>
void archivo<T>::abrirEnEscritura(){
	obj.open(this->nom);
	if (obj.fail()) {
		cout << "Error al abrir el archivo"; exit(1);	
	}
}
/*
	Cerrar el Archivo
*/
template <class T>
void archivo<T>::cerrar(){
	obj.close();
}
/*
	Crea el Archivo en modo escritura
*/
template <class T>
void archivo<T>::crearArchivo(){
	obj.open(this->nom,ios::out);
	this->cerrar();
}
/*
	Escribir en el Archivo (Ultima linea).
*/
template <class T>
void archivo<T>::escribirEnArchivo(char *text,bool saltoLinea){
	if(saltoLinea) obj << text << "\n";
	else obj << text;
}
/*
	Leer linea de un Archivo por referencia.
*/
template <class T>
void archivo<T>::leerLinea(char cad[]){
	obj.getline(cad,180,'\n');
}
/*
	Verificar si estamos en el final del archivo
*/
template <class T>
bool archivo<T>::es_fin(){
	 return obj.eof(); 
}
/*
	Escribe en el Archivo en una posicion asignada
*/
template <class T>
void archivo<T>::escribirEn(char *text, int puntero, int posicion, bool saltoLinea){
	
	switch(puntero){
		case 0:{
			obj.seekp(posicion,ios::beg);
			break;
		}
		case 1:{
			obj.seekp(posicion,ios::cur);
			break;
		}case 2:{
			obj.seekp(posicion,ios::end);
			break;
		}
		default:{
			obj.seekp(posicion,ios::beg);
			break;
		}
	}
	if(saltoLinea) obj << text << "\n";
	else obj << text;
	
}
/*
	Asigna el puntero de lectura del Archivo en la Posicion Asignada
*/
template <class T>
void archivo<T>::leerEn(int puntero, int posicion){
	
	switch(puntero){
		case 0:{
			obj.seekg(posicion,ios::beg);
			break;
		}
		case 1:{
			obj.seekg(posicion,ios::cur);
			break;
		}case 2:{
			obj.seekg(posicion,ios::end);
			break;
		}
		default:{
			obj.seekg(posicion,ios::beg);
			break;
		}
	}
	
}

#endif
