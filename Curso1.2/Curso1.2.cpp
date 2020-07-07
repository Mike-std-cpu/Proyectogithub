/*
 * Conecta.cpp
 *
 *  Created on: Jun 16, 2020
 *      Author: curso
 */

#include "Conexion.h"
#include <iostream>
using namespace std;
int main(int argc, char **argv) {
int opc;
Conexion *prueba;
prueba=new Conexion();

do{
	cout<<"\n1- SELECT * FROM alumno \n";
	cout<<"2- INSERT INTO  alumno \n";/*
	cout<<"3- UPDATE alumno set nombre \n";
	cout<<"4- DELETE alumno set nombre \n";*/
	cout<<"5- Salir \n";
cin>>opc;
switch(opc){
case 1:
cout<<"\nSELECT a tabla alumno\n";
prueba->wConsultar();
break;

//Insert INTO alumno
case 2:
//prueba->insertar(nombre,primerapellido,segundoapellido);
prueba->wInsertar();
prueba->wConsultar();
break;


case 3:
/*cout << "\n-Tabla actual- " << endl;
prueba->wConsultar();
prueba->wActualizar();
cout << "\n-Tabla actualizada- " << endl;
prueba->wConsultar();*/
break;
case 4:
/*cout << "\n-Tabla actual- " << endl;
prueba->wConsultar();
prueba->wBorrar();
cout << "\n-Tabla actualizada- " << endl;
prueba->wConsultar();*/
break;
default:
	cout<<"salir ...";
	}
}while(opc != 5);
return 0;
}
