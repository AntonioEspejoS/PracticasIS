#ifndef MAQUINA_H
#define MAQUINA_H
#include <iostream>
#include <cstdio>
using namespace std;
class Maquina{
    private:
	    int idM_;
        int nucleo_;
        int memoria_;
    public:
        int getIdM(){return idM_;};
        void setIdM(int id){idM_=id;};
        int getNucleo(){return nucleo_;};
        void setNucleo(int nucleo){nucleo_=nucleo;};        
        int getMemoria(){return memoria_;};
        void setMemoria(int memoria){memoria_=memoria;};
};

#endif
