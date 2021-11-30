#ifndef ADMINISTRADORMAQUINA_H
#define ADMINISTRADORMAQUINA_H
#include <iostream>
#include <cstdio>
#include <list>
#include "usuario.h"
using namespace std;
class AdministradorMaquina:public Usuario{
    private:
        //list <Maquina> listaMaquinas_;
    public:
        AdministradorMaquina(int id,string nombre,string contra, string correo):Usuario(id,nombre,contra,correo){
            setTipoUsu(2);
        };  
};

#endif
