/*
 * Conexion.cpp
 *
 *  Created on: Jul 3, 2020
 *      Author: curso
 */

#include "Conexion.h"
#include "Conexion.h"
#include <iostream>
#include <string>
#include <pqxx/pqxx>
#include <cstring>

using namespace std;
using namespace pqxx;


Conexion::Conexion() {
	// TODO Auto-generated constructor stub

}

Conexion::~Conexion() {
	// TODO Auto-generated destructor stub
}

int  Conexion::conectar(){
cout<<"en conexion-conectar";

try{
connection c(cadenaConexion);



	if(c.is_open()){
		nontransaction N(c);
		int size=sql->size();
		result R(N.exec(this->consultar()));
		cout<<endl;
		cout<<"\tMostrando datos"<<endl;
		cout<<"\n\n Nombre\t\t PrimerApellido\t\t SegundoApellido\t"<<endl;
		cout<<"============================================================"<<endl;
	for(result::const_iterator c=R.begin(); c!=R.end();++c){
		cout<<"-"<<c[0].as<string>()<<"\t\t";
		cout<<"-"<<c[1].as<string>()<<"\t\t";
		cout<<"-"<<c[2].as<string>()<<endl;
	}

	cout<<"Se conecto a la BD "<<" "<<c.dbname()<<" Con exito";
}
	else {
cout<<"No se conecto a la Base de datos"<<endl;
	return 1;
}
	c.disconnect();
}

	catch (const std::exception &e) {
		cerr<<e.what()<<std::endl;
		return 1;
}
	return 0;
}

	char* Conexion::consultar(){
		sql=new string("select * from alumno");
		int size;
		size=sql->size()+1;
		char *query=new char[size];
		strcpy(query, sql->c_str());
		return query;
}

