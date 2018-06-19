#include <iostream>
#include <ctime>
#include <cstdlib>

#define X 10

using namespace std;

int numeroMax (int [], int );
void cargar (int [], int );
void imprimir (int [], int );
void radixSort (int [], int **, int );
void imprimirMatriz(int **,int );
void limpiar (int **,int );
/*
*	
*
*/


int main () {

	int v[20] , **m; 
	int n = sizeof(v) / sizeof(int);
	
	m = new int * [X];
	
	for (int i = 0; i < X; i++) 
		m[i] = new int [n];

	for (int i = 0; i < X; i++)
		m[i][0] = i;
		
	for (int x = 0; x < X; x++) 
		for(int y = 1; y < n; y++) 
				m[x][y] = 0;
	 
		
	cargar (v, n);
	
	radixSort (v,m,n);
	imprimir (v, n);
	return 0;
}

int numeroMax (int v[], int n) {
	
	int max = 0;

	for(int i = 0; i < n; i++) 
		if(v[i] > max)
			max = v[i];

	return max;
}

void radixSort (int v[], int **m, int n) {

	int max = numeroMax (v,n), indx = 0, mod = 10, d = 1 , temp;


	while (max > 0) {//contador de fases
		indx++;
		max /= 10;	
	}
	
	for (int i = 0; i < indx ; i++) {

		limpiar (m, n);//limpiar la matriz 
		for(int j = 0; j < n; j++){//recorrer el vector
			
			int x = 0, y = 1;
			
			temp = (v[j] % mod) / d;
			
			while(x < X && y < n) {//se guardan el la matriz
				
				if(m[x][0] == temp) {
					
					while(m[x][y] != 0)
						y++;
					
						
					m[x][y] = v[j];
						
				}
				y = 1;
				x++;
			}
		}
			
		int x = 0, y = 1 , k = 0;			
			
		while(x < X && y < n && k < n) { // se asignan en el vector
				
			while(m[x][y] != 0) {
				v[k] = m[x][y];
				y++;
				k++;
			}
					
			y = 1;
			x++;
		 	 
		}
		
		mod *=10;
		d *=10;
		
	}
	
}

void cargar (int vec[], int n) {
	
	srand(time(NULL));
	
	for(int i = 0; i < n; i++)
		vec[i] = rand() % 1000000 + 1;	
	
}

void imprimir (int vec[],int n) {
	cout << endl;
	for(int i = 0; i < n; i++)
		cout << "|" << vec[i];
		
	cout << endl;
}

void imprimirMatriz (int **m,int n) {
	cout << endl;
	for (int x = 0; x < X; x++) {
		cout << endl;
		for(int y = 0; y < n; y++)
			cout << "|"  << m[x][y];
	}
					
}

void limpiar (int **m, int n) {
	for (int x = 0; x < X; x++) 
		for(int y = 1; y < n; y++) 
				m[x][y] = 0;
}
