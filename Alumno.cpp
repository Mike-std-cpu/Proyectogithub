/*
 * Alumno.cpp
 *
 *  Created on: Jun 1, 2020
 *      Author: curso
 */

#include "Alumno.h"
#include<iostream>
#include<string>
using namespace std;


Alumno::Alumno() {
	// TODO Auto-generated constructor stub

}

Alumno::~Alumno() {
	// TODO Auto-generated destructor stub
}

void Alumno::setNombre(string nombre){
	this->nombre=nombre;
	}

	string Alumno::getNombre(){
		return nombre;
	}

	void Alumno::setPrimerApellido(string primerApellido){
		this->primerApellido = primerApellido;
	}

	string Alumno::getPrimerApellido(){
		return primerApellido;
	}

	void Alumno::setSegundoApellido(string segundoApellido){
		this->segundoApellido = segundoApellido;
	}
	string Alumno::getSegundoApellido(){
		return segundoApellido;
	}
	string Alumno::getCurp(){
		return curp;
	}
	void Alumno::setCurp(string curp){
		this->curp=curp;
	}

	void Alumno::setDia(int dia){
		this->dia = dia;
	}

	int Alumno::getDia(){
	return dia;
	}
	void Alumno::setMes(int mes){
		this->mes = mes;
	}
	int Alumno::getMes(){
		return mes;
	}
	void Alumno::setYear(int year){
		this-> year = year;
	}
	int Alumno::getYear(){
		return year;
	}

	void Alumno::setBoleta(string boleta){
			this-> boleta = boleta;
		}
	string Alumno::getBoleta(){
			return boleta;
		}
