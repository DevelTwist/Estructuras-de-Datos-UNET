/* 
	ARCHIVOS
*/

#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include "archivo.h"
#include "main.h"


int main(){
	
	
	char cad[180];
	archivo<alumno>arc("alumno.txt");
	arc.abrir(); // Solo lectura de texto
	
	alumno reg;
	
	while(true){
		
		arc.leer(cad);
		
		arc.convertir(cad,conver);
		cout << arc.get_buf() << endl;
		
		if(arc.es_fin()){
			break;
		} 
		
	}
	
	arc.cerrar();
	
	return 0;	
}
