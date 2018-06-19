#include <iostream>

using namespace std;

void Intercambio(int &a, int &b);
void SHELLSORT( int V[], int N);
void Imprimir(int V[], int N);

int main(){
	
	int V[] = { 4, 2, 1, 6, 9, 3, 5, 7, 8, 1, 6, 2, 50, 14, 25, 67, 96, 16, 18, 26, 49, 25, 36, 67};
	
	Imprimir(V,sizeof(V)/sizeof(int));
	SHELLSORT(V,sizeof(V)/sizeof(int));
	cout << "\n" << endl;
	Imprimir(V,sizeof(V)/sizeof(int));
	
}

void Imprimir(int V[], int N){
	
	int i;

	for( i = 0 ; i < N ; i++ ){
		cout << V[i] << " ";	
	}
	
	cout << "\n";
}

void SHELLSORT( int V[], int N){
	
	int Bandera, Paso, i;
	
	while( Paso != 0){
		
		do{
		
		
		Bandera = 0;
		
		for(i = 0 ; i+Paso < N ; i++){
			
			if ( V[i] > V[i+Paso] ){
				Intercambio(V[i], V[i+Paso]);
				Bandera = 1;
			} 
			
		}
		
		}while( Bandera == 1);
		
		Paso /= 2;
		
	}
	
	
}

void Intercambio(int &a, int &b){
	
	int aux = a;
	a = b;
	b = aux;
	
}
