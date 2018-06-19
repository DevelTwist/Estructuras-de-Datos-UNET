#include <iostream>
#include <stdlib.h>
#include <string.h>
#define Max 25

/*
*   UMINKS Tech;
*/


using namespace std;
int Length(char V[]);
int CountArray(char V[][Max]);
int DeterminarMaxIndex(char V[][Max]);
void ImprimirVector(int V[], int N);
void RadixSort(char V[][Max], int VP[],int Size, int **M);
int numeroMax (int v[], int n);
void LimpiarMatriz(int **M,int Size);
void ImprimirCadena(char V[][Max],int Size);

int main(){

	char V[][Max] = { "Brayan", "Luis" , "Emanuel", "Yorman", "Kimberly", "Angel"};
	int Size = CountArray(V);
	int *VP = new int[Size];
	int i,j;
	
	
	int **Matriz = new int*[10];
	
	for(i = 0 ; i < 10 ; i++){
		Matriz[i] = new int[Size];
	}
	
	
	for(i = 0; i < 10 ; i++){
		Matriz[i][0] = i;
	}
	
	for ( i = 0; i < 10; i++){
		for( j = 1; j < Size ; j++){
			Matriz[i][j] = 0;	
		} 			
	}
	

	RadixSort(V,VP,Size,Matriz);

	return 0;
}

//VP vector que va a contener el codigo ascii de la letra seleccionada
void RadixSort(char V[][Max], int VP[],int Size, int **M){

	int Index = DeterminarMaxIndex(V);
    char Vaux[Size][Max];
	int i,j,z=0,temporal,modulo=10,decena=1;
	
	// Copiando Vector Auxiliar
	for( j = 0 ; j < Size ; j++){
		strcpy(Vaux[j],V[j]);
	}
	
	//cout << "Tamano:" << Size << endl;

	while(Index > 0){
        
        cout << "\nIndex: " << Index<<endl;;
        Index--;

        for(j = 0 ; j < Size ; j++){ // Creamos Vector Paralelo (ASCII (int))
            VP[j] = (int) tolower(V[j][Index]);
        }
        
		

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

int numeroMax (int v[], int n) {

	int i;
    int numMayor = -1;

      for(i = 0; i < n; i++){
        if(v[i] > numMayor)
          numMayor = v[i];
      }

    return numMayor;

}

void LimpiarMatriz(int **M,int Size){
	
	for (int i = 0; i < 10; i++){
		for(int j = 1; j < Size; j++){
			M[i][j] = -1;
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


