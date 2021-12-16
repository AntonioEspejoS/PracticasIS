#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "usuario.h"
#include "administradorUsuario.h"
#include "administradorMaquina.h"
#include "sistema.h"
#include "reserva.h"
#include "maquina.h"
/*void thisIsATest() {
	ASSERTM("start writing tests", false);	

}*/
void TestIniciarSesionExiste() {

	Sistema sistema;
	int idSesion=123;
	string contraSesion="contra1";
	Usuario usuarioSesion;
	bool sesionIniciada;
	sesionIniciada=sistema.iniciarSesion(idSesion,contraSesion,usuarioSesion);
	ASSERT(sesionIniciada==true);
}
void TestIniciarSesionErrorContra() {

	Sistema sistema;
	int idSesion=123;
	string contraSesion="contra2";
	Usuario usuarioSesion;
	bool sesionIniciada;
	sesionIniciada=sistema.iniciarSesion(idSesion,contraSesion,usuarioSesion);
	ASSERT(sesionIniciada==false);
}
void TestIniciarNumeroMaquinasDisponibles() {
Sistema sistema;
int numeroMaquinas,numeroMaquinasComprobar=0;
string id,nucleos,memoria;
numeroMaquinas=sistema.mostrarMaquinasDisponibles();
ifstream fichero("src/maquinasDisponibles.txt");
if(fichero.good()){
     while(getline(fichero,id,',')){
        getline(fichero,nucleos,',');
        int nucleosEntero=atoi(nucleos.c_str());
        getline(fichero,memoria,'\n');
        int memoriaEntero=atoi(memoria.c_str());
        if(nucleosEntero<1 || memoriaEntero<1){
        }else{
            numeroMaquinasComprobar++;
        }

     }
    fichero.close();

}else{cout<<"Error al abrir el fichero para leer";}
ASSERT(numeroMaquinasComprobar==numeroMaquinas);
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	//s.push_back(CUTE(thisIsATest));
	s.push_back(CUTE(TestIniciarSesionExiste));
	s.push_back(CUTE(TestIniciarSesionErrorContra));
	s.push_back(CUTE(TestIniciarNumeroMaquinasDisponibles));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
