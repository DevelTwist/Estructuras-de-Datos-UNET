/*
*
*    METODOS DE BUSQUEDA INTERNA 08/05/2018
*    PROCESO DE RECORRIDO O POSICIONAMIENTO PARA COMPARAR LOS ELEMENTOS DEL ARRAY CON UNA CLAVE (ELEMENTO A BUSCAR).
*    EL RESULTADO ES UNO DE DOS:
*	 -Encontrado (Localizado)
*    -No Encontrado
*
*    Existen Diversos métodos:
*    -Lineal ó Secuencial simple
*    -Lineal por saltos ( Búsqueda por bloques)
*    -Secuencial Indexada.
*    -Busqueda Binaria.
*	 -Búsqueda por transformación de claves (Dispersión Hashing).
*	 -Entre otros.
*                                                                  
*/

// IMPLEMENTACION DE METODOS CON PLANTILLAS C++

/*
*  tempalte <class T>
*  bool buscarSimple();
*
*/

#include <iostream>

using namespace std;

template <class T>

int buscarSimple(T clave,T V[],int N){
	
	int i;
		
	for(i = 0 ; i < N ; i++){
		
		if(V[i] == clave){
			return i;
		}
		
	}
	
	return -1;
}

int buscarBloques(T clave,T V[],int N){
	
	int Blo = sqrt(n);
		
	for(i = Blo-1 ; i < N ; i+=Blo){
		
		if( clave <= V[i]){
			return buscarSimple(Clave,V[i-Blo+1],N);
		}
		
	}
	
	// IF n % Blo != 0
	
}


int main(){
	
	int V[] = { 5, 16, 22, 26, 31, 33, 38, 41, 46, 51, 55, 58 };
	int clave, pos;
	int n = (sizeof(V)/sizeof(int));
	
	cout << "Clave: "; cin >> clave;
	pos = buscarSimple(clave,V,n);
	
	
	if(pos != -1){
	  cout << "\nLa posicion es: " << pos << endl;	
	}else{
	  cout << "\nNo Existe el elemento." << endl;
	}
	
	
	return 0;
}


