/*
 * Conexion.cpp
 *
 *  Created on: Jun 16, 2020
 *      Author: curso
 */

#include "Conexion.h"
#include <iostream>
#include <pqxx/pqxx>
#include <string.h>
using namespace std;
using namespace pqxx;

Conexion::Conexion() {

}

Conexion::~Conexion() {
// TODO Auto-generated destructor stub
}

int  Conexion::wConsultar(){

try{
connection c(cadenaConexion);
if(c.is_open()){
cout<<"Se conecto a la BD: "<<" "<<c.dbname();
//cout<<"\nSELECT a tabla alumno";
nontransaction N(c); // * Crear un objeto no transaccional. *
int size=sql->size();
result R(N.exec(this->consultar())); // * Ejecutar consulta SQL *
cout<<"\n Matricula\tnombre\t\t Primer apellido\t Segundo apellido\t Dia\t Mes\t Año "<<endl;
cout<<"=================================================="<<endl;
for(result::const_iterator c=R.begin(); c!=R.end();++c){
cout<<" "<<c[0].as<string>()<<"\t\t";
cout<<" "<<c[1].as<string>()<<"\t\t";
cout<<" "<<c[2].as<string>()<<"\t\t";
cout<<" "<<c[3].as<string>()<<"\t\t";
cout<<" "<<c[4].as<string>()<<"\t\t";
cout<<" "<<c[5].as<string>()<<"\t\t";
cout<<" "<<c[6].as<string>()<<endl;
	}
}else {
cout<<"No se conecto a la Base de datos"<<endl;
return 1;
}
c.disconnect();
}catch (const std::exception &e) {
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
// Insert
int  Conexion::wInsertar(){
try{
connection c(cadenaConexion);
if(c.is_open()){
work W(c); //AGREGADO *** / * Crear un objeto transaccional. * /
int size=sql->size();
string matricula,nombre,primerapellido,segundoapellido,dia,mes,year;

cout << "Matricula (8 digitos)\n";
cin >> matricula;
cout << "\nNombre\n";
cin >> nombre;
cout << "Primer apellido\n";
cin >> primerapellido;
cout << "Segundo apellido\n";
cin >> segundoapellido;
cout<<"Fecha de nacimiento dd mm aaaa:"<<endl;
cin>>dia>>mes>>year;

W.exec(this->insertar(matricula,nombre, primerapellido, segundoapellido,dia,mes,year)); //AGREGADO ***/ * Ejecutar consulta SQL * /
cout << "Valores insertados exitosamente" << endl;
W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacción.
cout<<"*****************"<<endl;
}else {
cout<<"No se conecto a la Base de datos"<<endl;
return 1;
}
c.disconnect();
}catch (const std::exception &e) {
cerr<<e.what()<<std::endl;
return 1;
}
return 0;
}

char* Conexion::insertar(string matricula,string nombre, string primerapellido, string segundoapellido,string dia,string mes,string year){
sql=new string( "INSERT INTO alumno (matricula,nombre,primerapellido,segundoapellido,dia,mes,year)" \
		       "VALUES (\'" + matricula + "\', \'" + nombre + "\', \'" + primerapellido + "\', \'" + segundoapellido + "\', \'" + dia + "\', \'" + mes + "\', \'" + year + "\');");
int size;
size=sql->size()+1;
char *query=new char[size];
strcpy(query, sql->c_str());
return query;

}
// Actualizar
/*
int  Conexion::wActualizar(){

try{
connection c(cadenaConexion);
if(c.is_open()){
//cout<<"Se conecto a la BD: "<<" "<<c.dbname();
work W(c); //AGREGADO  * Crear un objeto transaccional. 
int size=sql->size();
W.exec(this->actualizar()); //AGREGADO ** * Ejecutar consulta SQL * /
cout << "Valores actualizados exitosamente" << endl;
W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacción.
cout<<"*****************";
}else {
cout<<"No se conecto a la Base de datos"<<endl;
return 1;
}
c.disconnect();
}catch (const std::exception &e) {
cerr<<e.what()<<std::endl;
return 1;
}
return 0;
}
*/
/*char* Conexion::actualizar(){
	string nuevonombre,nombrexistente;
	string eprimerapellido,nprimerapellido ;
	string esegundopellido,nsegundoapellido ;
	int opc;
	cout << "\nCambio de" << endl;
	cout << "1-Nombre" << endl;
	cout << "2-Primer apellido" << endl;
	cout << "3-Segundo apellido" << endl;
	cout << "4-Salir al menu principal" << endl;
	cin>>opc;
	switch(opc){
	case 1:
	cout << "\nEl nombre a cambiar" << endl;
	cin >> nombrexistente;
	cout << "Cambiar a " << endl;
	cin >> nuevonombre;
	sql=new string("UPDATE alumno set nombre = '" + nuevonombre + "' where nombre= '" + nombrexistente + "'");
	break;
	case 2:
	cout << "\nEl Primer apellido a cambiar" << endl;
	cin >> eprimerapellido;
	cout << "Cambiar a " << endl;
	cin >> nprimerapellido;
	sql=new string("UPDATE alumno set primerapellido = '" + nprimerapellido + "' where primerapellido= '" + eprimerapellido  + "'");
	break;
	case 3:
	cout << "\nEl Segundo apellido a cambiar" << endl;
	cin >> esegundopellido;
	cout << "Cambiar a " << endl;
	cin >> nsegundoapellido;
	sql=new string("UPDATE alumno set segundoapellido = '" + nsegundoapellido + "' where segundoapellido= '" + esegundopellido  + "'");
	break;
	default:
	cout<<"salir ...\n";
	break;
	}
int size;
size=sql->size()+1;
char *query=new char[size];
strcpy(query, sql->c_str());
return query;
}
*/
// Borrar
/*
int  Conexion::wBorrar(){

try{
connection c(cadenaConexion);
if(c.is_open()){

work W(c); //AGREGADO ***  Crear un objeto transaccional. 
int size=sql->size();
W.exec(this->borrar()); //AGREGADO  * Ejecutar consulta SQL * /
cout << "Los valores fueron borrados exitosamente" << endl;
W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacción.
cout<<"*****************";
}else {
cout<<"No se conecto a la Base de datos"<<endl;
return 1;
}
c.disconnect();
}catch (const std::exception &e) {
cerr<<e.what()<<std::endl;
return 1;
}
return 0;
}

char* Conexion::borrar(){
	string nombre;
		int opc;
		cout << "\n1-Borrar fila con el nombre" << endl;
		cout << "2-Borrar fila con el Primer apellido" << endl;
		cout << "3-Borrar fila con el Segundo apellido" << endl;
		cout << "4-Borrar toda la tabla" << endl;
		cout << "5-Salir al menu principal" << endl;
		cin>>opc;
		switch(opc){
		case 1:
		cout << "\nNombre " << endl;
		cin >> nombre;
		sql=new string("DELETE from alumno where nombre = '"+ nombre +"'");
		break;
		case 2:
		cout << "\nPrimer apellido " << endl;
		cin >> nombre;
		sql=new string("DELETE from alumno where primerapellido = '"+ nombre +"'");
		break;
		case 3:
		cout << "\nSegundo apellido " << endl;
		cin >> nombre;
		sql=new string("DELETE from alumno where segundoapellido = '"+ nombre +"'");
		break;
		case 4:
		sql=new string("DELETE from alumno");
		break;
		default:
		cout<<"salir ...\n";
		break;
		}

int size;
size=sql->size()+1;
char *query=new char[size];
strcpy(query, sql->c_str());
return query;
}*/
