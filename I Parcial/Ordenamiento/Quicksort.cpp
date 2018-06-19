#include <iostream>
#include <stdlib.h>
#define min 0

/*
*  HECHO POR LUIS FERNANDO VARGAS GÓMEZ
*/

using namespace std;

void intercambio(int &a, int &b){

	int aux = a;
	a = b;
	b = aux;

}


void quicksort(int a[], int primero, int ultimo){
	
	int i,j,central;
	int pivote;
	
	central = (primero + ultimo) / 2;
	pivote = a[central];
	i = primero;
	j = ultimo;
	
	do{
		while (a[i] < pivote) i++;
		while (a[j] > pivote) j--;
		
		if (i <= j){
			intercambio(a[i], a[j]);
			i++;
			j--;
		}
		
	}while( i <= j);
	
	if (primero < j)
	quicksort(a, primero, j); // mismo proceso con sublista izquierda
	if (i < ultimo)
	quicksort(a, i, ultimo); // mismo proceso con sublista derecha
	
}

void imprimirVector(int a[], int N){
	
	int i;
	
	for(i = 0 ; i < N; i++){
		cout << a[i] << " " ;
	}
	
	cout << "\n" << endl;
}


int main(){
	
	int a[] = { 4, 9 , 2 , 3, 7, 5, 1, 8, 6};
	int N = sizeof(a)/sizeof(int);
	
	cout << "Arreglo Original: "; imprimirVector(a,N);
	
	quicksort(a,min,N-1); // Ordenamos
	
	cout << "Aplicamos Quicksort: "; imprimirVector(a,N);
	
	return 0;
}


