#include <iostream>

using namespace std;

void Imprimir(int V[], int N);
void SelDir(int V[], int N);
void Intercambio(int &a, int &b);


int main(){
	
	int num[] = { 19, 14, 11, 15, 12, 20 , 9 , 1, 2 , 3 , 4 ,5 , 6 , 7 ,8 ,9 ,10 ,11 ,12 , 13 ,17};
	
	Imprimir(num, sizeof(num)/sizeof(int));
	SelDir(num, sizeof(num)/sizeof(int));
	Imprimir(num,sizeof(num)/sizeof(int));
	
	
}

void Imprimir(int V[], int N){
	
	int i;
	
	for( i = 0 ; i < N ; i++){
		cout << V[i] << " ";
	}
	
	cout << "\n";
	
}

void SelDir(int V[], int N){
	
	int Posmen, Men, i, j;
	
	for(j = 1 ; j < N ; j++){
		
		Men = V[j-1];
		Posmen = j-1;
		
		for(i = j ;  i < N ; i++){
			
			if( V[i] < Men ){
				Men = V[i];
				Posmen = i;
			}
			
		}
		
		if( Posmen != j-1 ){
			Intercambio(V[Posmen], V[j-1]);
		}
		
	}
	
	
}

void Intercambio(int &a, int &b){
	
	int aux = a;
	a = b;
	b = aux;
	
}
