/*
 * Conexion.cpp
 *
 *  Created on: Jun 16, 2020
 *      Author: curso
 */

#include "Conexion.h"
#include "Alumno.h"
#include "Profesor.h"
#include "Materia.h"
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

int  Conexion::wConsultarAlumno(){

try{
connection c(cadenaConexion);
if(c.is_open()){
cout<<"Se conecto a la BD: "<<" "<<c.dbname();
//cout<<"\nSELECT a tabla alumno";
nontransaction N(c); // * Crear un objeto no transaccional. *
int size=sql->size();
result R(N.exec(this->consultarAlumno())); // * Ejecutar consulta SQL *
cout<<"\n Matricula\tnombre\t\t Primer apellido\t Segundo apellido\t Dia\t Mes\t AÃ±o "<<endl;
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

char* Conexion::consultarAlumno(){
sql=new string("select * from alumno");
int size;
size=sql->size()+1;
char *query=new char[size];
strcpy(query, sql->c_str());
return query;

}
// Insert
Alumno alumno;
int  Conexion::wInsertarAlumno(){
try{
connection c(cadenaConexion);
if(c.is_open()){
work W(c); //AGREGADO *** / * Crear un objeto transaccional. * /
int size=sql->size();
///TEEEEEEEEEEEEEST
Alumno* alumno;
alumno = new Alumno();
string nombre,apellido1,apellido2,curp,boleta;
int dia,mes,ano;
				cout<<"Nombre(s):"<<endl;
				//cin>>nombre;
				std::getline(std::cin >> std::ws, nombre);
				alumno->setNombre(nombre);
				cout<<"Apellido paterno:"<<endl;
				cin>>apellido1;
				alumno->setPrimerApellido(apellido1);
				cout<<"Apellido materno:"<<endl;
				cin>>apellido2;
				alumno->setSegundoApellido(apellido2);
				cout<<"Fecha de nacimiento dd mm aaaa:"<<endl;
				cin>>dia>>mes>>ano;
				alumno->setDia(dia);
				alumno->setMes(mes);
				alumno->setYear(ano);
				cout<<"Ingrese CURP:"<<endl;
				cin>>curp;
				alumno->setCurp(curp);
				cout<<"Ingrese boleta de alumno:"<<endl;
				cin>>boleta;
				alumno->setBoleta(boleta);
				cout<<"Nombre:"<<alumno->getBoleta()<<endl;
// TESSSSSSSSSSSSSST
W.exec(this->insertarAlumno(alumno->getBoleta(),alumno->getNombre(), alumno->getPrimerApellido(), alumno->getSegundoApellido(),alumno->getDia(),alumno->getMes(),alumno->getYear()));


//W.exec(this->insertar(matricula,nombre, primerapellido, segundoapellido,dia,mes,year)); //AGREGADO ***/ * Ejecutar consulta SQL * /
cout << "Valores insertados exitosamente" << endl;
W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃ³n.
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

//char* Conexion::insertar(string matricula,string nombre, string primerapellido, string segundoapellido,string dia,string mes,string year){
char* Conexion::insertarAlumno(string matricula,string nombre, string primerapellido, string segundoapellido,int dia,int mes,int year){
//sql=new string( "INSERT INTO alumno (matricula,nombre,primerapellido,segundoapellido,dia,mes,year)" \
		       "VALUES (\'" + matricula + "\', \'" + nombre + "\', \'" + primerapellido + "\', \'" + segundoapellido + "\', \'" + dia + "\', \'" + mes + "\', \'" + year + "\');");

	sql=new string( "INSERT INTO alumno (matricula,nombre,primerapellido,segundoapellido,dia,mes,year)" \
			       "VALUES (\'" + matricula + "\', \'" + nombre + "\', \'" + primerapellido + "\', \'" + segundoapellido + "\', \'" + std::to_string(dia) +  "\', \'" + std::to_string(mes)+  "\', \'" + std::to_string(year) + "\');");
int size;
size=sql->size()+1;
char *query=new char[size];
strcpy(query, sql->c_str());
return query;

}
// Actualizar

int  Conexion::wActualizarAlumno(){

try{
connection c(cadenaConexion);
if(c.is_open()){
//cout<<"Se conecto a la BD: "<<" "<<c.dbname();
work W(c); //AGREGADO  * Crear un objeto transaccional.
int size=sql->size();
W.exec(this->actualizarAlumno()); //AGREGADO ** * Ejecutar consulta SQL * /
cout << "Valores actualizados exitosamente" << endl;
W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃ³n.
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

char* Conexion::actualizarAlumno(){
	string nuevonombre,nombrexistente;
	int dia,mes,year;
	string eprimerapellido,nprimerapellido,nMatricula,vMatricula;
	string esegundopellido,nsegundoapellido ;
	Alumno alumno;
	//alumno = new Alumno();
	string claveAlumno;
	cout << "Dame la clave del alumno a modificar" << endl;
	cin>>claveAlumno;
	alumno.setBoleta(claveAlumno);
	//Alumno alumno= alumno.setBoleta(claveAlumno);
	//alumno= alumno.setBoleta(claveAlumno);
	//cout << "Nombre" << alumno.getNombre()<<endl;
	int opc;
	cout << "\nCambio de" << endl;
	cout << "1-Nombre" << endl;
	cout << "2-Primer apellido" << endl;
	cout << "3-Segundo apellido" << endl;
	cout << "4-Fecha de nacimiento" << endl;
	cout << "5-Matricula" << endl;
	cout << "6-Salir al menu principal" << endl;
	cin>>opc;
	switch(opc){
	case 1:
	/*cout << "\nEl nombre a cambiar" << endl;
	cin >> nombrexistente;
	alumno.setNombre(nombrexistente);*/
	cout << "Cambiar nombre a " << endl;
	//cin >> nuevonombre;
	std::getline(std::cin >> std::ws, nuevonombre);
	alumno.setNombre(nuevonombre);
	sql=new string("UPDATE alumno set nombre= '" + alumno.getNombre() + "' where matricula= '" + alumno.getBoleta()  + "' ");
	break;
	case 2:
	/*cout << "\nEl Primer apellido a cambiar" << endl;
	cin >> eprimerapellido;*/
	cout << "Cambiar Primer apellido a: " << endl;
	cin >> nprimerapellido;
	alumno.setPrimerApellido(nprimerapellido);
	sql=new string("UPDATE alumno set primerapellido= '" + alumno.getPrimerApellido() + "' where matricula= '" + alumno.getBoleta()  + "' ");
	break;
	case 3:
	cout << "Cambiar a Segundo apellido a: " << endl;
	cin >> nsegundoapellido;
	alumno.setSegundoApellido(nsegundoapellido);
	sql=new string("UPDATE alumno set segundoapellido= '" + alumno.getSegundoApellido() + "' where matricula= '" + alumno.getBoleta()  + "' ");
	break;
	case 4:
	cout << "\nFecha de nacimiento formate dd/mm/aaaa  cambiar a: " << endl;
	cin>>dia>>mes>>year;
	alumno.setDia(dia);
	alumno.setMes(mes);
	alumno.setYear(year);
	sql=new string("UPDATE alumno set dia= '" + std::to_string(alumno.getDia()) + "',mes= '" + std::to_string(alumno.getMes()) + "',year= '" + std::to_string(alumno.getYear()) + "' where matricula= '" + alumno.getBoleta()  + "' ");
	break;
	case 5:
	cout << "\nMatricula actual : " << endl;
	cin>>vMatricula;
	cout << "\nCambiar a : " << endl;
	cin>>nMatricula;
	alumno.setBoleta(nMatricula);
	sql=new string("UPDATE alumno set matricula= '" + alumno.getBoleta() + "' where matricula= '" + vMatricula  + "' ");
	break;
	default:
		cout<<"salir ...\n";
		break;
	}
//	sql=new string("UPDATE alumno set nombre= '" + alumno.getNombre() + "',primerapellido= '" + alumno.getPrimerApellido() + "' where matricula= '" + alumno.getBoleta()  + "' ");
int size;
size=sql->size()+1;
char *query=new char[size];
strcpy(query, sql->c_str());
return query;
}

// Borrar

int  Conexion::wBorrarAlumno(){

try{
connection c(cadenaConexion);
if(c.is_open()){

work W(c); //AGREGADO ***  Crear un objeto transaccional.
int size=sql->size();
W.exec(this->borrarAlumno()); //AGREGADO  * Ejecutar consulta SQL * /
cout << "Los valores fueron borrados exitosamente" << endl;
W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃ³n.
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

char* Conexion::borrarAlumno(){
	Alumno alumno;
	/*string claveAlumno;
		cout << "Dame la clave del alumno a modificar" << endl;
		cin>>claveAlumno;
		alumno.setBoleta(claveAlumno);*/

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
		alumno.setNombre(nombre);
		//std::getline(std::cin >> std::ws,nombre);
		//cin.ignore(256, '\n');
		sql=new string("DELETE from alumno where nombre = '"+ alumno.getNombre() +"'");
		break;
		case 2:
		cout << "\nPrimer apellido " << endl;
		cin >> nombre;
		alumno.setPrimerApellido(nombre);
		sql=new string("DELETE from alumno where primerapellido = '"+ alumno.getPrimerApellido() +"'");
		break;
		case 3:
		cout << "\nSegundo apellido " << endl;
		cin >> nombre;
		alumno.setSegundoApellido(nombre);
		sql=new string("DELETE from alumno where segundoapellido = '"+ alumno.getSegundoApellido() +"'");
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
}

//************************************************** PROFESOR **************************************************
int  Conexion::wConsultarProfesor(){

try{
connection c(cadenaConexion);
if(c.is_open()){
cout<<"Se conecto a la BD: "<<" "<<c.dbname();
//cout<<"\nSELECT a tabla alumno";
nontransaction N(c); // * Crear un objeto no transaccional. *
int size=sql->size();
result R(N.exec(this->consultarProfesor())); // * Ejecutar consulta SQL *
cout<<"\n Matricula\tnombre\t\t Primer apellido\t Segundo apellido "<<endl;
cout<<"=================================================="<<endl;
for(result::const_iterator c=R.begin(); c!=R.end();++c){
//char* insertarProfesor(string matriculaprofesor,string nombre, string primerapellido, string segundoapellido);
cout<<" "<<c[0].as<string>()<<"\t\t";
cout<<" "<<c[1].as<string>()<<"\t\t";
cout<<" "<<c[2].as<string>()<<"\t\t";
cout<<" "<<c[3].as<string>()<<endl;
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

char* Conexion::consultarProfesor(){
sql=new string("select * from profesor");
int size;
size=sql->size()+1;
char *query=new char[size];
strcpy(query, sql->c_str());
return query;

}
// Insert
//Alumno alumno;
int  Conexion::wInsertarProfesor(){
try{
connection c(cadenaConexion);
if(c.is_open()){
work W(c); //AGREGADO *** / * Crear un objeto transaccional. * /
int size=sql->size();
///TEEEEEEEEEEEEEST
Profesor* profesor;
profesor = new Profesor();
//insert into profesor(matriculaprofesor , nombre, primerapellido ,segundoapellido) values('48715967','carlos','diaz','camacho');
string nombre,primerapellido,segundoapellido,matriculaprofesor;
				cout<<"--Profesor--"<<endl;
				cout<<"Nombre(s):"<<endl;
				//cin>>nombre;
				std::getline(std::cin >> std::ws, nombre);
				profesor->setNombre(nombre);
				cout<<"Apellido paterno:"<<endl;
				cin>>primerapellido;
				profesor->setPrimerApellido(primerapellido);
				cout<<"Apellido materno:"<<endl;
				cin>>segundoapellido;
				profesor->setSegundoApellido(segundoapellido);
				cout<<"Ingrese matricula del profesor:"<<endl;
				cin>>matriculaprofesor;
				profesor->setMatriculaProfesor(matriculaprofesor);
// TESSSSSSSSSSSSSST
W.exec(this->insertarProfesor(profesor->getMatriculaProfesor(),profesor->getNombre(), profesor->getPrimerApellido(), profesor->getSegundoApellido()));


//W.exec(this->insertar(matricula,nombre, primerapellido, segundoapellido,dia,mes,year)); //AGREGADO ***/ * Ejecutar consulta SQL * /
cout << "Valores insertados exitosamente" << endl;
W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃ³n.
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

//char* Conexion::insertar(string matricula,string nombre, string primerapellido, string segundoapellido,string dia,string mes,string year){
char* Conexion::insertarProfesor(string matriculaprofesor,string nombre, string primerapellido, string segundoapellido){
//insert into profesor(matriculaprofesor , nombre, primerapellido ,segundoapellido) values('48715967','carlos','diaz','camacho');
	sql=new string( "INSERT INTO profesor (matriculaprofesor,nombre,primerapellido,segundoapellido)" \
			       "VALUES (\'" + matriculaprofesor + "\', \'" + nombre + "\', \'" + primerapellido + "\', \'" + segundoapellido + "\');");
int size;
size=sql->size()+1;
char *query=new char[size];
strcpy(query, sql->c_str());
return query;

}
// Actualizar

int  Conexion::wActualizarProfesor(){

try{
connection c(cadenaConexion);
if(c.is_open()){
//cout<<"Se conecto a la BD: "<<" "<<c.dbname();
work W(c); //AGREGADO  * Crear un objeto transaccional.
int size=sql->size();
W.exec(this->actualizarProfesor()); //AGREGADO ** * Ejecutar consulta SQL * /
cout << "Valores actualizados exitosamente" << endl;
W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃ³n.
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

char* Conexion::actualizarProfesor(){
	string nuevonombre,nombrexistente;
	int dia,mes,year;
	string nsegundoapellido,nprimerapellido,nMatricula,vMatricula;

	Profesor profesor;
	string claveProfesor;
	cout << "Dame la clave del Profesor a modificar" << endl;
	cin>>claveProfesor;
	profesor.setMatriculaProfesor(claveProfesor);
	//cout << "Nombre" << profesor.getNombre()<<endl;
	int opc;
	cout << "\nCambio de" << endl;
	cout << "1-Nombre" << endl;
	cout << "2-Primer apellido" << endl;
	cout << "3-Segundo apellido" << endl;
	cout << "4-Matricula" << endl;
	cout << "6-Salir al menu principal" << endl;
	cin>>opc;
	switch(opc){
	case 1:
	/*cout << "\nEl nombre a cambiar" << endl;
	cin >> nombrexistente;
	alumno.setNombre(nombrexistente);*/
	cout << "Cambiar nombre a " << endl;
	//cin >> nuevonombre;
	std::getline(std::cin >> std::ws, nuevonombre);
	profesor.setNombre(nuevonombre);
	sql=new string("UPDATE profesor set nombre= '" + profesor.getNombre() + "' where matriculaprofesor= '" + profesor.getMatriculaProfesor()  + "' ");
	break;
	case 2:
	/*cout << "\nEl Primer apellido a cambiar" << endl;
	cin >> eprimerapellido;*/
	cout << "Cambiar Primer apellido a: " << endl;
	cin >> nprimerapellido;
	profesor.setPrimerApellido(nprimerapellido);
	sql=new string("UPDATE profesor set primerapellido= '" + profesor.getPrimerApellido() + "' where matriculaprofesor= '" + profesor.getMatriculaProfesor()  + "' ");
	break;
	case 3:
	cout << "Cambiar a Segundo apellido a: " << endl;
	cin >> nsegundoapellido;
	profesor.setSegundoApellido(nsegundoapellido);
	sql=new string("UPDATE profesor set segundoapellido= '" + profesor.getSegundoApellido() + "' where matriculaprofesor= '" + profesor.getMatriculaProfesor()  + "' ");
	break;
	case 4:
	cout << "\nMatricula actual : " << endl;
	cin>>vMatricula;
	cout << "\nCambiar a : " << endl;
	cin>>nMatricula;
	profesor.setMatriculaProfesor(nMatricula);
	sql=new string("UPDATE profesor set matriculaprofesor= '" + profesor.getMatriculaProfesor() + "' where matriculaprofesor= '" + vMatricula  + "' ");
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
W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃ³n.
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

//************************************************** MATERIA **************************************************

int  Conexion::wConsultarMateria(){

try{
connection c(cadenaConexion);
if(c.is_open()){
cout<<"Se conecto a la BD: "<<" "<<c.dbname();
//cout<<"\nSELECT a tabla alumno";
nontransaction N(c); // * Crear un objeto no transaccional. *
int size=sql->size();
result R(N.exec(this->consultarMateria())); // * Ejecutar consulta SQL *
//insert into materia (idmateria ,nombre ) values('1CV11','POO');
cout<<"\n Id_materia\tNombre\t"<<endl;
cout<<"=================================================="<<endl;
for(result::const_iterator c=R.begin(); c!=R.end();++c){
cout<<" "<<c[0].as<string>()<<"\t\t";
cout<<" "<<c[1].as<string>()<<endl;
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

char* Conexion::consultarMateria(){
sql=new string("select * from materia");
int size;
size=sql->size()+1;
char *query=new char[size];
strcpy(query, sql->c_str());
return query;

}
// Insert
//Alumno alumno;
int  Conexion::wInsertarMateria(){
try{
connection c(cadenaConexion);
if(c.is_open()){
work W(c); //AGREGADO *** / * Crear un objeto transaccional. * /
int size=sql->size();
///TEEEEEEEEEEEEEST
Materia* materia;
materia = new Materia();
//insert into materia (idmateria ,nombre ) values('1CV11','POO');
string idmateria,nombre;

				cout<<"Id materia:"<<endl;
				cin>>idmateria;
				//getline(cin,idmateria);
				//std::getline(std::cin, idmateria);
				//cin.getline (nombre,256);
				//cin.getline(nombre,40);
				materia->setIdmateria(idmateria);
				cout<<"Nombre:"<<endl;
				//cin>>nombre;
				 //std::getline(std::cin, nombre);
				std::getline(std::cin >> std::ws, nombre);
				//getline(cin,nombre);
				//cin.ignore(256, '\n');
				materia->setNombre(nombre);
// TESSSSSSSSSSSSSST
W.exec(this->insertarMateria(materia->getIdmateria(),materia->getNombre()));


//W.exec(this->insertar(matricula,nombre, primerapellido, segundoapellido,dia,mes,year)); //AGREGADO ***/ * Ejecutar consulta SQL * /
cout << "Valores insertados exitosamente" << endl;
W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃ³n.
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

//char* Conexion::insertar(string matricula,string nombre, string primerapellido, string segundoapellido,string dia,string mes,string year){
char* Conexion::insertarMateria(string idmateria,string nombre){
	//insert into materia (idmateria ,nombre ) values('1CV11','POO');
	sql=new string( "INSERT INTO materia (idmateria,nombre)" \
			       "VALUES (\'" + idmateria + "\', \'" + nombre + "\');");
int size;
size=sql->size()+1;
char *query=new char[size];
strcpy(query, sql->c_str());
return query;

}
// Actualizar

int  Conexion::wActualizarMateria(){

try{
connection c(cadenaConexion);
if(c.is_open()){
//cout<<"Se conecto a la BD: "<<" "<<c.dbname();
work W(c); //AGREGADO  * Crear un objeto transaccional.
int size=sql->size();
W.exec(this->actualizarMateria()); //AGREGADO ** * Ejecutar consulta SQL * /
cout << "Valores actualizados exitosamente" << endl;
W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃ³n.
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

char* Conexion::actualizarMateria(){
	string nuevonombre,nombrexistente;
		int dia,mes,year;
		string nsegundoapellido,nprimerapellido,nId,vId;

		Materia materia;
		string claveMateria;
		cout << "Dame la clave del Profesor a modificar" << endl;
		cin>>claveMateria;
		materia.setIdmateria(claveMateria);
		int opc;
		cout << "\nCambio de" << endl;
		cout << "1-Nombre" << endl;
		cout << "2-Id" << endl;
		cout << "6-Salir al menu principal" << endl;
		cin>>opc;
		switch(opc){
		case 1:
		cout << "Cambiar nombre a " << endl;
		//cin >> nuevonombre;
		std::getline(std::cin >> std::ws, nuevonombre);
		materia.setNombre(nuevonombre);
		sql=new string("UPDATE materia set nombre= '" + materia.getNombre() + "' where idmateria= '" + materia.getIdmateria()  + "' ");
		break;
		case 2:
		cout << "\nId actual : " << endl;
		cin>>vId;
		cout << "\nCambiar a : " << endl;
		cin>>nId;
		materia.setIdmateria(nId);
		sql=new string("UPDATE alumno set idmateria= '" + materia.getIdmateria() + "' where idmateria= '" + vId + "' ");
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
W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃ³n.
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
