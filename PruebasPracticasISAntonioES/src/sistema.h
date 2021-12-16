#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include <cstdio>
#include <list>
#include "usuario.h"
using namespace std;
class Sistema{
    private:
        //list <Maquina> listaMaquinas_;
	list <Usuario> listaUsuarios_;

    public:
	bool iniciarSesion(int id,string contra,Usuario &usuarioSesion);
	int mostrarMaquinasDisponibles();

};

#endif
