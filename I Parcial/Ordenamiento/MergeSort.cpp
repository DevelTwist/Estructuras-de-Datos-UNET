#include <iostream>
#define sufpeq 4

using namespace std;

void Inter(int &A, int &B){
	
	int  Aux=A;
	A=B;
	B=Aux;
}

void Seledir(int V[], int N){
	
	int MEN,PMEN,i,j;
	
	for(j=1; j<N; j++){
		
		MEN=V[j-1]; PMEN=j-1;
		
		for(i=j; i<N; i++){
			
			if(V[i]<MEN){
				MEN=V[i];
				PMEN=i;
			}
		}
		
		if(PMEN!=j-1){
			Inter(V[j-1],V[PMEN]);
		}
	} // Fin ciclo de fases
}

void Imprimir(int V[], int N){
	
	for(int i=0; i<N; i++){	
		cout<<" "<<V[i]<<" ";
	}
	
	cout<<endl;		
}

void Partir(int V[], int *x1, int *x2, int N){
	
	int i;
	for(i=0; i<N/2; i++){
		x1[i]=V[i];
	}
	
	for(; i<N; i++){
		x2[i-N/2]=V[i];
	}
	
}

void Fusion(int *V, int *x1, int *x2, int N){
	
	int i=0,j=0,k=0;
	
	for(; k<N; k++){
		
		if(i==N/2 && j<N-N/2){
			V[k]=x2[j];
			j++;
		}
		
		else if(j==N-N/2 && i<N/2){
			V[k]=x1[i];
			i++;
		}
		
		else if((i<N/2) && (j<N-N/2) && (x1[i]<x2[j])){
			V[k]=x1[i];
			i++;
		}
	
		else{
			V[k]=x2[j];
			j++;
		}
	}
}

void MergeSort(int V[], int N){
	
	if(N<=sufpeq) {
		Seledir(V,N);
	}
	
	else {
		int *x1,*x2;
		x1= new int[N/2];
		x2= new int[N-N/2];
		
		Partir(V,x1,x2,N);
		//Imprimir(x1,N/2);
		//Imprimir(x2,N-N/2); //Mezcla por Tercios
		MergeSort(x1,N/2);
		MergeSort(x2,N-N/2);
		//Imprimir(x1,N/2);
		//Imprimir(x2,N-N/2);
		Fusion(V,x1,x2,N);
	}	
}

int main(int argc, char** argv) {
	
	int V[]={34,56,11,19,20,21,31,40,18,4,65,22,44,55,86,76,45,1};
	
	//Imprimir(V,sizeof(V)/sizeof(int));
	//Seledir(V,sizeof(V)/sizeof(int));
	//Imprimir(V,sizeof(V)/sizeof(int));
	MergeSort(V,sizeof(V)/sizeof(int));
	Imprimir(V,sizeof(V)/sizeof(int));
	
	//system("pause");
	
	return 0;
}
