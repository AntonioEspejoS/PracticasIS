#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "usuario.h"
#include "administradorUsuario.h"
#include "administradorMaquina.h"
#include "sistema.h"
using namespace std;

bool Sistema::iniciarSesion(int id,string contra,Usuario &usuarioSesion){
	ifstream fichero("usuarios.txt");
 	string idF,nombreF,contraF,correoF,tipoF;
	int idEntero, tipoEntero;
	if(fichero.good()){
		while(getline(fichero,idF,',')){
			idEntero=atoi(idF.c_str());
			getline(fichero,nombreF,',');
			getline(fichero,contraF,',');
			getline(fichero,correoF,',');
			getline(fichero,tipoF,'\n');
			tipoEntero=atoi(tipoF.c_str());
			if(id==idEntero && contra==contraF){
				usuarioSesion.setId(idEntero);
				usuarioSesion.setNombre(nombreF);
				usuarioSesion.setContra(contraF);
				usuarioSesion.setCorreo(correoF);
				usuarioSesion.setTipoUsu(tipoEntero);
				return true;
			}
		}

	}else{
	    cout<<"Error al leer el fichero";
	}
	fichero.close();
	return false;
}
