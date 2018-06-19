/*
*   Hecho por Luis Fernando Vargas Gómez
*   V.26723356
*
*/


#include <iostream>
#include <stdlib.h>
#include <string.h>
#define Max 25

using namespace std;
int Length(char V[]);
int CountArray(char V[][Max]);
int DeterminarMaxIndex(char V[][Max]);
void ImprimirVector(int V[], int N);
void ImprimirMatriz(int **Matriz,int Size);
void ImprimirCadena(char V[][Max],int Size);
void RadixSort(char V[][Max], int VP[], int **M,int Size);
void LimpiarMatriz(int **M,int Size);
int numeroMax (int v[], int n);

int main(){
	
	char V[][Max] = { "Abc", "Bca" , "Dfb", "Cad"};
	int Size = CountArray(V);
	int *VP = new int[Size];
	int i,j;
	
	
	
	int **Matriz = new int*[10];
	
	for(i = 0 ; i < 10 ; i++){
		Matriz[i] = new int[Size+1];
	}
	
	
	for(i = 0; i < 10 ; i++){
		Matriz[i][0] = i;
	}
	
	for ( i = 0; i < 10; i++){
		for( j = 1; j < Size+1 ; j++){
			Matriz[i][j] = 0;	
		} 			
	}
	

	RadixSort(V,VP,Matriz,Size);
		
	return 0;
}

void RadixSort(char V[][Max], int VP[], int **M,int Size){
	
	int Index = DeterminarMaxIndex(V);
	
	int i,j,z=0;
	int Aux[Size];
	char Vaux[][Max] = {""};
	int modulo = 10, decena = 1, temporal;
	int t;
	//cout << "Tamano:" << Size << endl;
	

	
	while(Index > 0){
	
	cout << "\nIndex: " << Index;
	Index -= 1;
	
	for(j = 0 ; j < Size ; j++){ // Creamos Vector Paralelo (ASCII (int))
			
			VP[j] = (int) tolower(V[j][Index]);	
			Aux [j] = VP[j];	
			
	}

	/****** RADIXSORT CLASICO *******/
	
	int NumMax = numeroMax(VP,Size);
	
		z = 0;
	while (NumMax > 0) {//contador de fases
		z++;
		NumMax /= 10;	
	}
	
	t = z;
	
	for( i = 0 ; i < t ; i++){ // FASES

		LimpiarMatriz(M,Size+1);
		
		for(j = 0 ; j < Size ; j++){ // Recorremos el Vector Paralelo
			
			int x = 0, y = 1;
			
			temporal = (VP[j] % modulo) / decena;
			
			while( x < 10 && y < Size ){ // Procedemos a Guardar en la Matriz Auxiliar
			
				if(M[x][0] == temporal){
					
					
					while(M[x][y] != -1){
						y++;
					}
					
					M[x][y] = VP[j];
					
				}
				y = 1;
				x++;
			}
		}
			
			int x = 0, y = 1 , k = 0;
			
			while ( x < 10 && y < Size && k < Size){ // Ordenamos el Vector Paralelo
				
				while ( M[x][y] != -1 ){
					VP[k] = M[x][y];
					y++;
					k++;
				}
				
				y=1;
				x++;
				
			}
			
			modulo *= 10;
			decena *= 10;
			cout << " \n\n";
			

		
		ImprimirVector(VP,Size);			
		ImprimirCadena(Vaux,Size);	
			
			
			cout << endl;
			ImprimirVector(Aux,Size);
			ImprimirCadena(V,Size);
			
			system("pause");
		}
		
		
	}
			
	
}

void ImprimirCadena(char V[][Max],int Size){
	
	int l;
	
	for(int j = 0 ; j < Size ; j++){
		
		l = 0;
				
			while(V[j][l]){
				cout << V[j][l++];
			}
			
		cout << " ";		
	}
	
}

int Length(char V[]){
	
	int tam =0; int i=0;
	
	while(V[i] != 0){
		tam++; i++;
	}
	
	return tam;
}

int CountArray(char V[][Max]){
	
	int tam=0; int i=0;
	
	while(V[i][0] > 0){
		tam++; i++;
	}
	
	return tam;
}

int DeterminarMaxIndex(char V[][Max]){
	
	int max = 0; int i,j;
	
	for(i = 0 ; i < CountArray(V) ; i++){
		if(Length(V[i]) > max){
			max = Length(V[i]);
		}
	}
	
	return max;
}

void ImprimirVector(int V[], int N){
	
	int i;
	
	for(i = 0 ; i < N ; i++){
		cout << V[i] << " ";
	}
	
}

void ImprimirMatriz(int **Matriz,int Size){
	
	int i,j;
	
	for(i = 0 ; i < 10 ; i++ ){
		for(j = 0 ; j < Size ; j++){
			cout << Matriz[i][j] << " ";
		}
		cout << endl;
	}
	
}

void LimpiarMatriz(int **M,int Size){
	
	for (int i = 0; i < 10; i++){
		for(int j = 1; j < Size; j++){
			M[i][j] = -1;
		}
	} 
		
}

int numeroMax (int v[], int n) {
	
	int max = 0;

	for(int i = 0; i < n; i++){
		
		if(v[i] > max){
			max = v[i];
		}
					
	} 
	
	return max;
}





