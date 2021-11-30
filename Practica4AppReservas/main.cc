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
	cout<<"Hola usuario administrador\n";
   }


/*
   Usuario u1(1234,"Antonio","miContra","correo@hotmail.com");
   AdministradorUsuario aU1(6784,"Pedro","miContra2","correo@hotmail.com");
   AdministradorMaquina aM1(352,"Martin","miContra3","correo@hotmail.com");
*/
   return 0;
}
