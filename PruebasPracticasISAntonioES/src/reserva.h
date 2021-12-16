#ifndef RESERVA_H
#define RESERVA_H
#include <iostream>
#include <cstdio>
#include "maquina.h"
#include "usuario.h"
using namespace std;
class Reserva{
    private:
	    int idR_;
	    int maquinaR_;
	    int memoriaR_;
	    int nucleoR_;
	    int usuarioR_;
	    int tiempoR_;
    public:
        int getIdR(){return idR_;};
        void setIdR(int id){idR_=id;};    
        int getMaquinaR(){return maquinaR_;};
        void setMaquinaR(int maquina){maquinaR_=maquina;};
        int getMemoriaR(){return memoriaR_;};
        void setMemoriaR(int memoria){memoriaR_=memoria;}; 
        int getNucleoR(){return nucleoR_;};
        void setNucleoR(int nucleo){nucleoR_=nucleo;}; 
        int getUsuarioR(){return usuarioR_;};
        void setUsuarioR(int usuario){usuarioR_=usuario;};
        int getTiempoR(){return tiempoR_;};
        void setTiempoR(int tiempo){tiempoR_=tiempo;};          
};

#endif
