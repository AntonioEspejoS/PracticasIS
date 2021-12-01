#ifndef ADMINISTRADORUSUARIO_H
#define ADMINISTRADORUSUARIO_H
#include <iostream>
#include <cstdio>
#include <list>
#include "usuario.h"
using namespace std;
class AdministradorUsuario:public Usuario{
    private:
        list <Usuario> listaUsuarios_;
    public:
        AdministradorUsuario(int id,string nombre,string contra, string correo):Usuario(id,nombre,contra,correo){
            setTipoUsu(1);
        };  
        void crearUsuario();
};

#endif
