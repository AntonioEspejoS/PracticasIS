#include <stdio.h>
#include <iostream>
#include "usuario.h"
#include "administradorUsuario.h"
#include "administradorMaquina.h"
#include "sistema.h"
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
        cout<<"Hola usuario normal\n";
   }else if(usuarioSesion.getTipoUsu()==1){
    int opcionMenuAdminUsu=0;
    do{   
            AdministradorUsuario AdminUsu(usuarioSesion.getId(),usuarioSesion.getNombre(),usuarioSesion.getContra(), usuarioSesion.getCorreo());
            
        	cout<<"--------------------------------------------\n";
            cout<<"Bienvenido administrador de usuarios ";
            cout<< AdminUsu.getNombre();
            cout<<"\n";
        	do{
            	cout<<"--------------MENU--------------\n";
            	cout<<"1.-Crear usuario\n";
            	cout<<"2.-Salir\n";
            	cout<<"Elige una opcion:\n";
            	cin>>opcionMenuAdminUsu;
            	if(opcionMenuAdminUsu<1 || opcionMenuAdminUsu>2){
            	  cout<<"Opcion invalida\n";  
            	}
        	}while(opcionMenuAdminUsu<1 || opcionMenuAdminUsu>2);
        	if(opcionMenuAdminUsu==1){
        	    cout<<"----Crear usuario----\n";
        	    AdminUsu.crearUsuario();
        	}else if(opcionMenuAdminUsu==2){
        	    cout<<"Hasta pronto\n";
        	}
       }while(opcionMenuAdminUsu!=2);
   }


   return 0;
}