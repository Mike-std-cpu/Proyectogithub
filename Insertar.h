/*
 * Insertar.h
 *
 *  Created on: Jul 3, 2020
 *      Author: curso
 */

#ifndef INSERTAR_H_
#define INSERTAR_H_
#include<iostream>
#include <string>
#include <pqxx/pqxx>
#include <cstring>

using namespace std;
using namespace pqxx;

class Insertar {
public:
	string *sql;

	const string cadenaConexion="dbname=proyecto user=fpoo password=fpoo hostaddr=127.0.0.1 port=5432";
	int conect();
	char* insert();
	Insertar();
	virtual ~Insertar();
};

#endif /* INSERTAR_H_ */
