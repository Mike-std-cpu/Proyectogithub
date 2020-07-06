/*
 * Conexion.h
 *
 *  Created on: Jul 3, 2020
 *      Author: curso
 */

#ifndef CONEXION_H_
#define CONEXION_H_
#include<iostream>
#include <string>
#include <pqxx/pqxx>
#include <cstring>

using namespace std;
using namespace pqxx;

class Conexion {
public:
	string *sql;

		const string cadenaConexion="dbname=proyecto user=fpoo password=fpoo hostaddr=127.0.0.1 port=5432";
		Conexion();
		virtual ~Conexion();
		int conectar();
		char* consultar();
};

#endif /* CONEXION_H_ */
