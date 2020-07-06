/*
 * Insertar.cpp
 *
 *  Created on: Jul 3, 2020
 *      Author: curso
 */

#include "Insertar.h"
#include <iostream>
#include <string>
#include <pqxx/pqxx>
#include <cstring>

using namespace std;
using namespace pqxx;


Insertar::Insertar() {
	// TODO Auto-generated constructor stub

}

Insertar::~Insertar() {
	// TODO Auto-generated destructor stub
}

int  Insertar::conect(){
cout<<"en conexion-conectar";

try {
      connection c(cadenaConexion);
      if (c.is_open()) {
    	  nontransaction N(c);
    	  int size=sql->size();
    	  result R(N.exec(this->insert()));
         cout << "Conectado a la base de datos" << c.dbname() << endl;
      } else {
         cout << "No se conecto a la base de datos" << endl;
         return 1;
      }
      c.disconnect ();
   } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
      return 1;
   }

   return 0;
}
char* Insertar::insert(){
	string matricula,nombre, primerApellido,segundoApellido;
	cout<<"Por favor, ingrese los siguientes datos:"<<endl;
	cout<<"Ingrese su Matricula:"<<endl;
	cin>>matricula;
	cout<<"Ingrese su Nombre:"<<endl;
	cin>>nombre;
	cout<<"Ingrese su Primer Apellido:"<<endl;
	cin>>primerApellido;
	cout<<"Ingrese su Segundo Apellido"<<endl;
	cin>>segundoApellido;
	cout<<"/ Fecha de Nacimiento /"<<endl;
	/*int dia,mes,year;
	cout<<"DIA:"<<endl;
	cin>>dia;
	cout<<"MES"<<endl;
	cin>>mes;
	cout<<"AÑO"<<endl;
	cin>>year;*/
	sql=new string("INSERT INTO Alumno (matricula,nombre,primerApellido,segundoApellido) "  \
   "VALUES ('"+matricula+"','"+nombre+"','"+primerApellido+"','"+segundoApellido+"')");
	int size;
	size=sql->size()+1;
	char *query=new char[size];
	strcpy(query, sql->c_str());
	return query;
}
