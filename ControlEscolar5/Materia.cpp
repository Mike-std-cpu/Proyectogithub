/*
 * Materia.cpp
 *
 *  Created on: Jul 9, 2020
 *      Author: curso
 */

#include "Materia.h"
#include<iostream>
#include<string>
using namespace std;

Materia::Materia() {
	// TODO Auto-generated constructor stub

}

Materia::~Materia() {
	// TODO Auto-generated destructor stub
}

void Materia::setNombre(string nombre){
	this->nombre=nombre;
	}

	string Materia::getNombre(){
		return nombre;
	}

	void Materia::setIdmateria(string idmateria){
		this->idmateria = idmateria;
	}

	string Materia::getIdmateria(){
		return idmateria;
	}
