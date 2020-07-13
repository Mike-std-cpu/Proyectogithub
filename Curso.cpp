/*
 * Curso.cpp
 *
 *  Created on: Jul 9, 2020
 *      Author: curso
 */

#include "Curso.h"

Curso::Curso() {
	// TODO Auto-generated constructor stub

}

Curso::~Curso() {
	// TODO Auto-generated destructor stub
}

void Curso::setMatriculaAlumno(string matriculaAlumno){
	this->matriculaAlumno=matriculaAlumno;
	}

	string Curso::getMatriculaAlumno(){
		return matriculaAlumno;
	}

	void Curso::setIdmateria(string idmateria){
		this->idmateria = idmateria;
	}

	string Curso::getIdmateria(){
		return idmateria;
	}

	void Curso::setMatriculaProfesor(string matriculaprofesor){
		this->matriculaprofesor=matriculaprofesor;
		}

	string Curso::getMatriculaProfesor(){
		return matriculaprofesor;
	}

	void Curso::setCalificacion(int calificacion){
			this->calificacion = calificacion;
		}

		int Curso::getCalificacion(){
		return calificacion;
		}


