/*
 * Materia.h
 *
 *  Created on: Jul 9, 2020
 *      Author: curso
 */
#include<iostream>
#include<string>
using namespace std;
#ifndef MATERIA_H_
#define MATERIA_H_

class Materia {
private:
	//insert into materia (idmateria ,nombre ) values('1CV11','POO');
	string nombre,idmateria;
public:
	Materia();
	virtual ~Materia();
	void setNombre(string nombre);
	string getNombre();
	string getIdmateria();
	void setIdmateria(string idmateria);

};

#endif /* MATERIA_H_ */
