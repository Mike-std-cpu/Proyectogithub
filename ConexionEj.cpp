#include <iostream>
#include <string>
#include <pqxx/pqxx>
#include <cstring>
#include "Conexion.h"
#include "Insertar.h"

using namespace std;
using namespace pqxx;

int main(int argc, char **argv) {
	cout<<"P R O G R A M A   C O N T R O L  E S C O L A R"<<endl;
	cout<<"Ingrese una opcion:"<<endl;
	int opc;
	cin>>opc;
	cout<<endl;
	switch(opc){
	      case 1:
	    	Conexion *prueba;
	    	prueba=new Conexion();
	    	prueba->conectar();
	    	return 0;
	    	cout<<endl;
	    	break;
	      	case 2:
	    	Insertar *insert;
	    	insert=new Insertar();
	    	insert->conect();
	    	prueba= new Conexion();
	    	prueba->conectar();
	    	return 0;
	    	cout<<endl;
	    	break;
	      /*case 3:
	    	Actualizar* update;
	    	update=new Actualizar();
	    	update->conectact();
	    	prueba= new Conexion();
	    	prueba->conectar();
	    	return 0;
	    	cout<<endl;
	    	break;*/
	}
	}
