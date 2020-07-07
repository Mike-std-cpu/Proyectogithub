/*
 * Conexion.h
 *
 *  Created on: Jun 16, 2020
 *      Author: curso
 */


#include <string>
#include <pqxx/pqxx>
using namespace pqxx;
#include <iostream>
using namespace std;


#ifndef CONEXION_H_
#define CONEXION_H_

class Conexion {
public:
	const string cadenaConexion= "dbname=controlescolar2 user=postgres password=postgres hostaddr = 127.0.0.1 port=5432";
	string *sql;
	Conexion();
	virtual ~Conexion();
	int wConsultar();
	int wInsertar();
	int wActualizar();
	int wBorrar();
	char* consultar();
	char* insertar(string matricula,string nombre, string primerapellido, string segundoapellido,string dia,string mes,string year);
	char* actualizar();
	char* borrar();
};

#endif /* CONEXION_H_ */
