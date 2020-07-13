/*
 * Profesor.cpp
 *
 *  Created on: Jul 9, 2020
 *      Author: curso
 */

#include "Profesor.h"
#include<iostream>
#include<string>
using namespace std;
Profesor::Profesor() {
	// TODO Auto-generated constructor stub

}

Profesor::~Profesor() {
	// TODO Auto-generated destructor stub
}

void Profesor::setNombre(string nombre){
	this->nombre=nombre;
	}

	string Profesor::getNombre(){
		return nombre;
	}

	void Profesor::setPrimerApellido(string primerApellido){
		this->primerApellido = primerApellido;
	}

	string Profesor::getPrimerApellido(){
		return primerApellido;
	}

	void Profesor::setSegundoApellido(string segundoApellido){
		this->segundoApellido = segundoApellido;
	}
	string Profesor::getSegundoApellido(){
		return segundoApellido;
	}
	string Profesor::getMatriculaProfesor(){
		return matriculaProfesor;
	}
	void Profesor::setMatriculaProfesor(string matriculaProfesor){
		this->matriculaProfesor=matriculaProfesor;
	}
