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
	ifstream fichero("src/usuarios.txt");
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
				fichero.close();
				return true;
			}
		}

	}else{
	    cout<<"Error al leer el fichero";
	}
	fichero.close();
	return false;
}

int Sistema::mostrarMaquinasDisponibles(){
	string id,nucleos,memoria;
	int numeroMaquinas=0;
	    ifstream fichero("src/maquinasDisponibles.txt");
	    if(fichero.good()){
	        cout<<"--------------Lista de maquinas disponibles-------------------\n";
	        cout<<"ID maquina|||Nucleos|||Memoria\n";
	         while(getline(fichero,id,',')){
	            getline(fichero,nucleos,',');
	            int nucleosEntero=atoi(nucleos.c_str());
	            getline(fichero,memoria,'\n');
	            int memoriaEntero=atoi(memoria.c_str());
	            if(nucleosEntero<1 || memoriaEntero<1){

	            }else{
	                cout<<id<<"       |||"<<nucleos<<"      |||"<<memoria<<"\n";
	                numeroMaquinas++;
	            }

	         }
	        fichero.close();

	    }else{cout<<"Error al abrir el fichero para leer";}
	    return numeroMaquinas;
}
