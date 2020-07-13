/*
 * Profesor.h
 *
 *  Created on: Jul 9, 2020
 *      Author: curso
 */
#include<iostream>
#include<string>
using namespace std;

#ifndef PROFESOR_H_
#define PROFESOR_H_

class Profesor {
private:
//insert into profesor(matriculaprofesor , nombre, primerapellido ,segundoapellido) values('48715967','carlos','diaz','camacho');
	string nombre, primerApellido, segundoApellido,matriculaProfesor;
public:
	Profesor();
	virtual ~Profesor();
	void setNombre(string nombre);
	string getNombre();
	void setPrimerApellido(string primerApellido);
	string getPrimerApellido();
	void setSegundoApellido(string segundoApellido);
	string getSegundoApellido();
	string getMatriculaProfesor();
	void setMatriculaProfesor(string matriculaProfesor);
};

#endif /* PROFESOR_H_ */
