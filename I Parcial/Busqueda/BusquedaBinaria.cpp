#include <iostream>
#include <stdlib.h>
#define min 0

using namespace std;

/*
*  HECHO POR LUIS FERNANDO VARGAS GÓMEZ
*/

int busquedaBinaria(int a[], int n, int clave){
	
	int central,bajo,alto;
	int valorCentral;
	bajo = 0;
	alto = n-1;
	
	while(bajo <= alto){
		
		central = (bajo + alto)/2; // índice de elemento central
		valorCentral = a[central]; // valor del índice central
		
		if(clave == valorCentral){
			return central; // encontrado, devuelve posición
		}else if (clave < valorCentral){
			alto = central - 1;  // ir a sublista inferior
		}else{
			bajo = central + 1;  // ir a sublista superior
		}
		
	}
	
	return -1;   //elemento no encontrado
}


int main(){
	
	int V[] = { 1 , 5, 20, 22, 24, 26, 27, 29, 31, 35, 36, 37, 40};
	int N = sizeof(V)/sizeof(int);
	int clave;
	int resultado;
	
	cout << "Buscar Elemento: "; cin >> clave;
	
	resultado = busquedaBinaria(V,N,clave);
	
	if(resultado != -1){
		cout << "Se encontro el valor en la posicion: " << resultado << endl;
	}else{
		cout << "No se encontro el elemento. " << endl; 
	}
	
	return 0;
}
