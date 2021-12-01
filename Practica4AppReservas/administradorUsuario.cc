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

void AdministradorUsuario::crearUsuario(){
    listaUsuarios_.clear();
    int idNuevo;
    bool idRepetido=false;
    cout<<"\n";
    //Comprobar si el id introducido ya existe
    do{
        ifstream fichero("usuarios.txt");
        idRepetido=false;
        cout<<"Introduce un id para el nuevo usuario: ";
        cin>>idNuevo;
     	string idF,datosF;
    	int idEntero, tipoEntero;
    	if(fichero.good()){
    		while(getline(fichero,idF,',')){
    			idEntero=atoi(idF.c_str());
    			getline(fichero,datosF,'\n');
                if(idNuevo==idEntero){
                    idRepetido=true;
                }
    		}
    	}else{
    	    cout<<"Error al leer el fichero\n";
    	}
    	if(idRepetido==true){
    	    cout<<"Id introducido ya existe.\n";
    	}
    	fichero.close();
    }while(idRepetido==true);
	//Pedir los demas datos y crear usuario nuevo
	Usuario usuarioNuevo;
	string nombreNuevo,contraNuevo,correoNuevo;
	int tipoUsuNuevo;
	cout<<"\nIntroduce el nombre completo: ";
	cin>>nombreNuevo;
	cout<<"\nIntroduce la contrasena: ";
	cin>>contraNuevo;
	cout<<"\nIntroduce el correo: ";
	cin>>correoNuevo;
	cout<<"\nIndica el tipo de usuario: \n Usuario normal->0\nAdministrador de usuarios->1\nAdminitrador de maquinas->2\n";
	cin>>tipoUsuNuevo;
				usuarioNuevo.setId(idNuevo);
				usuarioNuevo.setNombre(nombreNuevo);
				usuarioNuevo.setContra(contraNuevo);
				usuarioNuevo.setCorreo(correoNuevo);
				usuarioNuevo.setTipoUsu(tipoUsuNuevo);
	//Guardar usuarios en la lista
	ifstream fichero2("usuarios.txt");
 	string idL,nombreL,contraL,correoL,tipoL;
	int idLEntero, tipoLEntero;
	Usuario usuarioLista;
	if(fichero2.good()){
		while(getline(fichero2,idL,',')){
			idLEntero=atoi(idL.c_str());
			getline(fichero2,nombreL,',');
			getline(fichero2,contraL,',');
			getline(fichero2,correoL,',');
			getline(fichero2,tipoL,'\n');
			tipoLEntero=atoi(tipoL.c_str());
				usuarioLista.setId(idLEntero);
				usuarioLista.setNombre(nombreL);
				usuarioLista.setContra(contraL);
				usuarioLista.setCorreo(correoL);
				usuarioLista.setTipoUsu(tipoLEntero);
            listaUsuarios_.push_back(usuarioLista);
		}
			listaUsuarios_.push_back(usuarioNuevo);
	}else{
	    cout<<"Error al leer el fichero";
	}
	fichero2.close();
	
	//Recorrer lista y escribir en el fichero
	ofstream ficheroE("usuarios.txt");
	if(ficheroE.good()){
        list <Usuario>::iterator i;
    	for(i=listaUsuarios_.begin();i!=listaUsuarios_.end();i++){
    	    //Listar usuarios
    	    //cout<<(*i).getId()<<","<<(*i).getNombre()<<"\n";
        	ficheroE<<(*i).getId()<<",";
        	ficheroE<<(*i).getNombre()<<",";
        	ficheroE<<(*i).getContra()<<",";
        	ficheroE<<(*i).getCorreo()<<",";
        	ficheroE<<(*i).getTipoUsu()<<"\n";
    	}		    
	}else{
	    cout<<"Error al leer el fichero";
	}
    	ficheroE.close();	

}
