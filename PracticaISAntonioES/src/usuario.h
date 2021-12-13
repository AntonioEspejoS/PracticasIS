#ifndef USUARIO_H
#define USUARIO_H
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Usuario{
    private:
        string nombre_;
        int id_;
        string correo_;
        string contra_;
        int limiteTiempo_;
        vector<int>limiteRecursos_;
        int tipoUsu_;
    public:
        Usuario(int id=0,string nombre="",string contra="", string correo="",int tipoUsu=0){id_=id;nombre_=nombre;contra_=contra;correo_=correo;tipoUsu_=tipoUsu;};
        string getNombre(){return nombre_;};
        void setNombre(string nombre){nombre_=nombre;};
        int getId(){return id_;};
	    void setId(int id){id_=id;};
        string getCorreo(){return correo_;};
        void setCorreo(string correo){correo_=correo;};
	    void setContra(string contra){contra_=contra;};
	    string getContra(){return contra_;};
        //int getLimiteTiempo(){return limiteTiempo_;};
        //vector<int> getLimiteRecursos(){return limiteRecursos_;};
        int getTipoUsu(){return tipoUsu_;};
        void setTipoUsu(int tipo){tipoUsu_=tipo;};
        void crearReserva();
};
#endif