#include <stdio.h>
#include <iostream>
#include "usuario.h"
#include "administradorUsuario.h"
#include "administradorMaquina.h"
#include "sistema.h"
#include "reserva.h"
#include "maquina.h"
using namespace std;

int main()
{
   Sistema sistema;
   int idSesion;
   string contraSesion;
   Usuario usuarioSesion;
   bool sesionIniciada;
   cout<<"-------------Bienvenido a la aplicacion--------------\n";
   cout<<"Iniciar sesion\n";
   do{
	   cout<<"Introduce tu id: \n";
	   cin>>idSesion;
	   cout<<"Introduce la contrasena: \n";
	   cin>>contraSesion;
	   sesionIniciada=sistema.iniciarSesion(idSesion,contraSesion,usuarioSesion);
	   if(sesionIniciada==false){
		cout<<"Credenciales erroneas vuelve a iniciar sesion.\n";
	   }
   }while(sesionIniciada==false);
   if(usuarioSesion.getTipoUsu()==0){
    int opcionMenuUsu=0;
    do{
        	cout<<"--------------------------------------------\n";
            cout<<"Bienvenido/a ";
            cout<< usuarioSesion.getNombre();
            cout<<"\n";
        	do{
            	cout<<"--------------MENU--------------\n";
            	cout<<"1.-Hacer reserva\n";
            	cout<<"2.-Salir\n";
            	cout<<"Elige una opcion:\n";
            	cin>>opcionMenuUsu;
            	if(opcionMenuUsu<1 || opcionMenuUsu>2){
            	  cout<<"Opcion invalida\n";
            	}
        	}while(opcionMenuUsu<1 || opcionMenuUsu>2);
        	if(opcionMenuUsu==1){
        	    cout<<"----Hacer reserva----\n";
        	   usuarioSesion.crearReserva();
        	}else if(opcionMenuUsu==2){
        	    cout<<"Hasta pronto\n";
        	}
       }while(opcionMenuUsu!=2);
   }else if(usuarioSesion.getTipoUsu()==1){
    int opcionMenuAdminUsu=0;
    do{
            AdministradorUsuario AdminUsu(usuarioSesion.getId(),usuarioSesion.getNombre(),usuarioSesion.getContra(), usuarioSesion.getCorreo());

        	cout<<"\n--------------------------------------------\n";
            cout<<"Bienvenido administrador de usuarios ";
            cout<< AdminUsu.getNombre();
            cout<<"\n";
        	do{
            	cout<<"--------------MENU--------------\n";
            	cout<<"1.-Crear usuario\n";
            	cout<<"2.-Hacer reserva\n";
            	cout<<"3.-Salir\n";
            	cout<<"Elige una opcion:\n";
            	cin>>opcionMenuAdminUsu;
            	if(opcionMenuAdminUsu<1 || opcionMenuAdminUsu>3){
            	  cout<<"Opcion invalida\n";
            	}
        	}while(opcionMenuAdminUsu<1 || opcionMenuAdminUsu>3);
        	if(opcionMenuAdminUsu==1){
        	    cout<<"----Crear usuario----\n";
        	    bool errorCrearUsuario;
        	    errorCrearUsuario=AdminUsu.crearUsuario();
        	    if(errorCrearUsuario==true){
        	    	cout<<"|Usuario nuevo creado correctamente|\n";
        	    }else{
        	    	cout<<"Error al crear el nuevo usuario";
        	    }
        	}else if(opcionMenuAdminUsu==2){
        	    cout<<"----Hacer reserva----\n";
        	     AdminUsu.crearReserva();
        	}else if(opcionMenuAdminUsu==3){
        	    cout<<"Hasta pronto\n";
        	}
       }while(opcionMenuAdminUsu!=3);
   }
   return 0;
}
