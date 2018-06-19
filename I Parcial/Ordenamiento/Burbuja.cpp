/***** DATOS *****
*  Nombre: Luis Fernando Vargas Gómez
*  Sección: 2 Cedula: 26.723.356
*/

#include <iostream>
#include "conio.h"

using namespace std;
void Imprimir(int V[], int N);

void Intercambio(int &a, int &b){
	
	int aux = a;
	a = b;
	b = aux;
	
}

void Burbuja(int V[], int N){
	
	int i,j;
	
	for(i = 1 ; i < N ; i++){
		for( j = 0 ; j < N-i ; j++){
			if(V[j] > V[j+1]){
				Intercambio(V[j],V[j+1]);			
			}
		}
	}
	
}

void Imprimir(int V[], int N){
	
	int i;
	
	for( i = 0 ; i < N ; i++ ){
		
		cout << V[i] << " ";	

	}
	
	
	cout << "\n";
}

int main(){
	
	int V[] = { 4, 2, 1, 6, 9, 3, 5, 7, 8, 1, 6, 2, 50, 14, 25, 67, 96, 16, 18, 26, 49, 25, 36, 67};
	
	Imprimir(V,sizeof(V)/sizeof(int));
	Burbuja(V,sizeof(V)/sizeof(int));
	cout << "\n" << endl;
	Imprimir(V,sizeof(V)/sizeof(int));
	
	
}
