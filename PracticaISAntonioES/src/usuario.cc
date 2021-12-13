#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "usuario.h"
#include "administradorUsuario.h"
#include "administradorMaquina.h"
#include "sistema.h"
#include "reserva.h"
#include "maquina.h"
using namespace std;
void mostrarMaquinasDisponibles();
void Usuario::crearReserva(){
    list <Reserva> listaReservas;
    listaReservas.clear();
    int idRNuevo,nucleoRNuevo,memoriaRNuevo,tiempoRNuevo;
    bool idNoExiste;
    mostrarMaquinasDisponibles();
    //comprobar si la maquina elegida está disponible y sus recursos
        do{
        ifstream fichero2("src/maquinasDisponibles.txt");
        idNoExiste=true;
        cout<<"Escribe el id de la maquina que quieras reservar: ";
        cin>>idRNuevo;
        cout<<"Escribe los nucleos que quieras reservar: ";
        cin>>nucleoRNuevo;
        cout<<"Escribe la memoria que quieras reservar: ";
        cin>>memoriaRNuevo;
        cout<<"Escribe el tiempo en dias que quieras reservar: ";
        cin>>tiempoRNuevo;
     	string idF,nucleoF,memoriaF;
     	int idEntero,nucleoEntero,memoriaEntero;
    	if(fichero2.good()){
    		while(getline(fichero2,idF,',')){
    			idEntero=atoi(idF.c_str());
    			getline(fichero2,nucleoF,',');
    			nucleoEntero=atoi(nucleoF.c_str());
    			getline(fichero2,memoriaF,'\n');
    			memoriaEntero=atoi(memoriaF.c_str());
                if(idRNuevo==idEntero && nucleoRNuevo<=nucleoEntero && memoriaRNuevo<=memoriaEntero){
                    idNoExiste=false;
                }
    		}
    	}else{
    	    cout<<"Error al leer el fichero\n";
    	}
    	if(idNoExiste==true){
    	    cout<<"Id de la maquina no existe, no está disponible o no tiene recursos suficientes para ti.\n";
    	}
    	fichero2.close();
    }while(idNoExiste==true);
//Si esta disponible continua
// crear reserva nueva
	Reserva reservaNueva;
	string cadenaIdU=to_string(this->getId());
	string cadenaIdM=to_string(idRNuevo);
	string cadena=cadenaIdU+cadenaIdM;
	int cadenaIdR=atoi(cadena.c_str());
	//Para que el id sea unico lo creo con el id del usuario + el id de la maquina
	reservaNueva.setIdR(cadenaIdR);
	reservaNueva.setMaquinaR(idRNuevo);
	reservaNueva.setNucleoR(nucleoRNuevo);
	reservaNueva.setMemoriaR(memoriaRNuevo);
	reservaNueva.setUsuarioR(this->getId());
	reservaNueva.setTiempoR(tiempoRNuevo);

	//Actualizar fichero de maquinas para restar los recursos que se han reservado
	//Leer fichero de maquinas y modificar la maquina reservada y guardarlo en una lista de maquinas
	list <Maquina> listaMaquina;
	listaMaquina.clear();
	ifstream ficheroMaquina("src/maquinasDisponibles.txt");
	if(ficheroMaquina.good()){
		string idMaquina,nucleoMaquina,memoriaMaquina;
		int idMaquinaE,nucleoMaquinaE,memoriaMaquinaE,nucleoModificado,memoriaModificado;
		Maquina maquinaLista;
		while(getline(ficheroMaquina,idMaquina,',')){
			idMaquinaE=atoi(idMaquina.c_str());
			getline(ficheroMaquina,nucleoMaquina,',');
			nucleoMaquinaE=atoi(nucleoMaquina.c_str());
			getline(ficheroMaquina,memoriaMaquina,'\n');
			memoriaMaquinaE=atoi(memoriaMaquina.c_str());
            if(idRNuevo==idMaquinaE){
            	nucleoModificado=nucleoMaquinaE-nucleoRNuevo;
            	memoriaModificado=memoriaMaquinaE-memoriaRNuevo;
            }else{
            	nucleoModificado=nucleoMaquinaE;
            	memoriaModificado=memoriaMaquinaE;
            }
            maquinaLista.setIdM(idMaquinaE);
            maquinaLista.setNucleo(nucleoModificado);
            maquinaLista.setMemoria(memoriaModificado);
            listaMaquina.push_back(maquinaLista);
		}
	}else{
	    cout<<"Error al leer el fichero\n";
	}
	ficheroMaquina.close();

	//Actualizar el fichero con la lista de maquinas

	ofstream ficheroMaquinasE("src/maquinasDisponibles.txt");
	if(ficheroMaquinasE.good()){
        list <Maquina>::iterator i;
    	for(i=listaMaquina.begin();i!=listaMaquina.end();i++){
        	ficheroMaquinasE<<(*i).getIdM()<<",";
        	ficheroMaquinasE<<(*i).getNucleo()<<",";
        	ficheroMaquinasE<<(*i).getMemoria()<<"\n";
    	}
	}else{
	    cout<<"Error al leer el fichero";
	}
    ficheroMaquinasE.close();

	
	//Guardar reservas del fichero + la nueva reserva en la lista
	ifstream fichero3("src/reservas.txt");
 	string idRL,maquinaL,nucleoL,memoriaL,usuarioL,tiempoL;
	int idRLEntero,maquinaLEntero,nucleoLEntero,memoriaLEntero,usuarioLEntero,tiempoLEntero;
	Reserva reservaLista;
	if(fichero3.good()){
		while(getline(fichero3,idRL,',')){
			idRLEntero=atoi(idRL.c_str());
            getline(fichero3,maquinaL,',');
            maquinaLEntero=atoi(maquinaL.c_str());
            getline(fichero3,nucleoL,',');
            nucleoLEntero=atoi(nucleoL.c_str());
            getline(fichero3,memoriaL,',');
            memoriaLEntero=atoi(memoriaL.c_str());
            getline(fichero3,usuarioL,',');
            usuarioLEntero=atoi(usuarioL.c_str());
            getline(fichero3,tiempoL,'\n');
            tiempoLEntero=atoi(tiempoL.c_str());

        	reservaLista.setIdR(idRLEntero);
        	reservaLista.setMaquinaR(maquinaLEntero);
        	reservaLista.setNucleoR(nucleoLEntero);
        	reservaLista.setMemoriaR(memoriaLEntero);
        	reservaLista.setUsuarioR(usuarioLEntero);
        	reservaLista.setTiempoR(tiempoLEntero);
            listaReservas.push_back(reservaLista);
		}
			listaReservas.push_back(reservaNueva);
	}else{
	    cout<<"Error al leer el fichero";
	}
	fichero3.close();
	
	//Recorrer lista de reservas y escribir en el fichero de reservas
	ofstream ficheroE("src/reservas.txt");
	if(ficheroE.good()){
        list <Reserva>::iterator i;
    	for(i=listaReservas.begin();i!=listaReservas.end();i++){
    	    //Listar reservas
    	    //cout<<(*i).getId()<<","<<(*i).getNombre()<<"\n";
        	ficheroE<<(*i).getIdR()<<",";
        	ficheroE<<(*i).getMaquinaR()<<",";
        	ficheroE<<(*i).getNucleoR()<<",";
        	ficheroE<<(*i).getMemoriaR()<<",";
        	ficheroE<<(*i).getUsuarioR()<<",";
        	ficheroE<<(*i).getTiempoR()<<"\n";
    	}		    
	}else{
	    cout<<"Error al leer el fichero";
	}
    	ficheroE.close();
cout<<"\n|Reserva realizada|\n";
}

void mostrarMaquinasDisponibles(){
    string id,nucleos,memoria;
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
            }
            
         }
        fichero.close();
        
    }else{cout<<"Error al abrir el fichero para leer";}

    
}
