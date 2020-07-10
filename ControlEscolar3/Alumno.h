/*
 * Alumno.h
 *
 *  Created on: Jun 1, 2020
 *      Author: curso
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_
#include<iostream>
#include<string>
/*#include "Estudios.h"
#include "MedioContacto.h"*/
using namespace std;

class Alumno {
private:
	string nombre;
	string primerApellido;
	string segundoApellido;
	int dia;
	int mes;
	int year;
	string curp;
	string boleta;
public:
	Alumno();
	virtual ~Alumno();
	/*void addEstudios(Estudios estudios);
	void addMedioContacto(MedioContacto medioContacto);*/

	void setNombre(string nombre);
	string getNombre();
	void setPrimerApellido(string primerApellido);
	string getPrimerApellido();
	void setSegundoApellido(string segundoApellido);
	string getSegundoApellido();
	void setDia(int dia);
	string getCurp();
	void setCurp(string curp);
	int getDia();
	void setMes(int mes);
	int getMes();
	void setYear(int year);
	int getYear();
	void setBoleta(string boleta);
	string getBoleta();

};
#endif /* ALUMNO_H_ */
