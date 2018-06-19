class alumno{
	
	int ced;
	char nom[30];
	
	public: 
	
	alumno(){}
	alumno(int ce, char *c) { ced = ce; strcpy(nom,c);  }
	
	//sobre carga
	
	friend ostream & operator << (ostream &os, alumno c){
		os << " " << c.ced << " " << c.nom;
		return os;
	}
	
};

alumno conver(char *cad){
	
	char *p;
	char nom[30];
	
	p = strtok(cad,",");
	int ced = atoi(p);
	p = strtok(cad,"\n");
	strcpy (nom,p);
	
	return alumno(ced,nom);
}

