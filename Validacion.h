/*
 * Validacion.h
 *
 *  Created on: Jul 11, 2020
 *      Author: curso
 */
#include "Alumno.h"
#include<iostream>
#include<string>
using namespace std;
#ifndef VALIDACION_H_
#define VALIDACION_H_

class Validacion {
public:
	Validacion();
	virtual ~Validacion();
	char* validarInformacion(string nombre,int opc);
	char* validarMatricula(string boleta,int opc);
	int validarFecha(int year,int opc);
	int validarCadena (int numero, int opc);
	int validarCadenaCalificacion(int numero,int opc);
	int validarOpc(int opc);
	char* validarIdMateria(string idmateria,int opc);
	int validarCalificacion(int calificacion);
	//bool Validacion::isnumber(const char *s);
	void setNombre(string nombre);
	string getNombre();
};

#endif /* VALIDACION_H_ */
