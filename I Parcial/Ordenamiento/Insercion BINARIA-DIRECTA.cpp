/***** DATOS *****
*  Nombre: Luis Fernando Vargas Gómez
*  Sección: 2 Cedula: 26.723.356
*/

#include <iostream>
#include "conio.h"
#include <ctime>

using namespace std;

void InsercionDirecta(int V[], int N);
void Intercambio(int &a, int &b);
void Imprimir(int V[], int N, int Color=-1);
void InsercionBinaria(int V[], int N);
void InsercionDirectaOtra(int V[], int N);

long long int intercambios = 0;

int main(){

	int N = 20; // -> Tamaño del Arreglo a probar.
	int V[N], C[N];
	clock_t time1, time2;

	// GENERAR ARREGLO CON NUMEROS ALEATORIOS.
	srand (time(NULL));
	for (int i = 0 ; i < N ; i++){
		V[i] = rand()%N;
		C[i] = V[i];
	}

	cout << "\n ARRAY BASE " << sizeof(V)/sizeof(int) << " : " ;
	Imprimir(V,sizeof(V)/sizeof(int));
	cout << "\n";

	// ORDENAR 1

	cout << " Insercion Directa: \n" << endl; time1 = clock();
	InsercionDirecta(V, sizeof(V)/sizeof(int));
	float Directa = difftime(clock(),time1) / 1000;
	cout << " Tiempo de ordenacion: " << Directa << " Segundos." << endl;

	// ORDENAR 2

	cout << "\n Insercion Binaria: \n" << endl; time2 = clock();
	InsercionBinaria(C,sizeof(C)/sizeof(int));
	float Binaria = difftime(clock(),time2) / 1000;
	cout << " Tiempo de ordenacion: " << Binaria << " Segundos." << endl;


		textcolor(10);
	if( Binaria > Directa ){
		cout << "\n El Metodo de Insercion Directa tardo menos tiempo en ordenar." << endl;
	}else if(Directa > Binaria ){
		cout << "\n El Metodo de Insercion Binaria tardo menos tiempo en ordenar." << endl;
	}else{
		cout << "\n Ambos ordenaron al mismo tiempo" << endl;
	}  textcolor(WHITE);

	cin.get();
	return 0;
}

void Imprimir(int V[], int N, int Color){

	int i;

	for( i = 0 ; i < N ; i++ ){

		if(Color >= i-1){
			textcolor(2);
		}else{
			textcolor(12);
		}


		cout << V[i] << " ";
		textcolor(WHITE);

	}

	cout << "\n";
}

void Intercambio(int &a, int &b){

	int aux = a;
	a = b;
	b = aux;

}

void InsercionDirecta(int V[], int N){

	int i, j, aux;
	bool band;
	intercambios = 0;

	for( i = 0 ; i < N-1 ; i++){ // Se Hace en N-1 Fases


		aux = i+1;
		band = true;


		for( j = i ; j > -1 && band ; j-- ){ // A medida que se mueve la posicion de la izquierda se pregunta, si es menor a su derecha.


			if ( V[aux] < V[j] ){ // En Caso de Ser menor, aplicar intercambio.
				Intercambio(V[aux],V[j]);
				intercambios++;
				aux--; // Desplazar posición izquierda (menor) a derecha, para preguntar por su nueva derecha.

			}else{

				band = false; // Si su derecha es menor a la izquierda. Significa que esta ordenado. por lo tanto negamos la bandera para evitar ciclos innecesarios.

			}

		}

		cout << " FIN FASE " << i+1 << ": "; Imprimir(V,N,i);

	}

	cout << " Intercambios: " << intercambios << endl;

}

void InsercionBinaria(int V[], int N){

	int i, aux, izq, der, m, j;
	intercambios = 0;

	for( i = 1 ; i < N ; i++ ){

		aux = V[i];
		izq = 0;
		der = i-1;

		while( izq <= der ){

			m = (izq+der)/2;
			if( aux <= V[m] ){
				der = m-1;
			}else{
				izq = m+1;
			}

		}

		j = i - 1;

		while( j >= izq){

			intercambios++;
			V[j+1] = V[j];
			j--;
		}

		V[izq] = aux;

		cout << " FIN FASE " << i << ": "; Imprimir(V,N,i-1);

	}

	cout << " Intercambios : " << intercambios << endl;
}

/* OTRA MANERA DE INSERCION DIRECTA*/
void InsercionDirectaOtra(int V[], int N){

	int i, j, aux;
	intercambios = 0;
	clock_t inicio;
	clock_t final;

	inicio = clock();
	for( i = 1 ; i < N ; i++){

		aux = V[i];
		j = i - 1;


		while ( j >= 0 && V[j] > aux){

			V[j+1] = V[j];
			j--;
			intercambios++;

		}

		V[j+1] = aux;
		cout << "FIN FASE " << i << ": "; Imprimir(V,N,i-1);
	}
	final = clock();

	cout << "Tiempo de Ordenamiento: " << difftime(final,inicio) / 1000 << " Segundos "<< endl;
	cout << "Intercambios : " << intercambios << "\n\n" << endl;
}


