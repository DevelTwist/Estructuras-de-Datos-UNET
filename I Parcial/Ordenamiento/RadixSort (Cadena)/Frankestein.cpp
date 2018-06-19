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
void RadixSort(char V[][Max],  int VP[],int Size);
int numeroMax (int v[], int n);

int main(){

	char V[][Max] = { "Gamma" , "Beta", "Alfa" , "Delta", "Zetta", "Ro", "Psi"};
	int Size = CountArray(V);
	int *VP = new int[Size];
	int i,j;

	RadixSort(V,VP,Size);

	return 0;
}


void RadixSort(char V[][Max], int VP[],int Size){

	int Index = DeterminarMaxIndex(V);
    char Vaux[Size][Max];
	int i,j,z=0;
	
	for (j = 0 ; j < Size ; j++){
		strcpy(Vaux[j],V[j]);
	}
	

	while(Index > 0){

        cout << "\n\nLetra Posicion: " << Index<<endl;;
        Index -= 1;

        for(j = 0 ; j < Size ; j++){ // Creamos Vector Paralelo (ASCII (int))
            VP[j] = (int) tolower(V[j][Index]);
        }

          int salida[Size];
          int divisor = 1;
          int posicionNueva=0;
          int numMayor = numeroMax(VP, Size);

          while (numMayor / divisor > 0){

            ImprimirVector(VP, Size); cout << " ";
            for (i = 0; i < Size; i++){
                cout<<V[i]<<" ";
            }

            int contador[10] = { 0 };

            for (i = 0; i < Size; i++)
              contador[(VP[i] / divisor) % 10]++;

            for (i = 1; i < 10; i++)
              contador[i] += contador[i - 1];

            for (i = Size - 1; i >= 0; i--){
              posicionNueva = --contador[(VP[i] / divisor) % 10];
              salida[posicionNueva] = VP[i];
              strcpy(Vaux[posicionNueva], V[i]);
            }
            cout<<endl;
            for (i = 0; i < Size; i++){
                VP[i] = salida[i];
                strcpy(V[i], Vaux[i]);
            }

            divisor *= 10;

          }

        
		ImprimirVector(VP, Size); cout << " ";
        for (i = 0; i < Size; i++){
          	if(V[i] != 0){
          		cout<<V[i] << " ";
			}            
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



