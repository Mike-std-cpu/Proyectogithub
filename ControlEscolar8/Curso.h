/*
 * Curso.h
 *
 *  Created on: Jul 9, 2020
 *      Author: curso
 */
#include<iostream>
#include<string>
using namespace std;
#ifndef CURSO_H_
#define CURSO_H_

class Curso {
private:
	//char* crearCurso(string matricula,string idmateria,string matriculaprofesor,int calificacion)
	string matriculaAlumno,idmateria,matriculaprofesor;
	int calificacion;
public:
	Curso();
	virtual ~Curso();
	void setMatriculaAlumno(string matriculaAlumno);
	string getMatriculaAlumno();
	void setMatriculaProfesor(string matriculaprofesor);
	string getMatriculaProfesor();
	void setIdmateria(string idmateria);
	string getIdmateria();
	void setCalificacion(int calificacion);
	int getCalificacion();
};

#endif /* CURSO_H_ */
