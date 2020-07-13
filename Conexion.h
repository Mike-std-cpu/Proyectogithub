/*
 * Conexion.h
 *
 *  Created on: Jun 16, 2020
 *      Author: curso
 */


#include <string>
#include <pqxx/pqxx>
using namespace pqxx;
#include <iostream>
using namespace std;


#ifndef CONEXION_H_
#define CONEXION_H_

class Conexion {
public:
	const string cadenaConexion= "dbname=controlescolar2 user=postgres password=postgres hostaddr = 127.0.0.1 port=5432";
	string *sql;
	Conexion();
	virtual ~Conexion();
	//Alumno
	int wConsultarAlumno();
	int wInsertarAlumno();
	int wActualizarAlumno();
	int wBorrarAlumno();
	//Profesor
	int wConsultarProfesor();
	int wInsertarProfesor();
	int wActualizarProfesor();
	int wBorrarProfesor();
	//Materia
	int wConsultarMateria();
	int wInsertarMateria();
	int wActualizarMateria();
	int wBorrarMateria();
	//CURSO
	int wConsultarCurso();
	int wCrearCurso();
	int wAsingarCalificacion();
	int wBorrarCurso();
	// ----------------------------------- //
	//ALUMNO
	char* consultarAlumno();
	//char* insertar(string matricula,string nombre, string primerapellido, string segundoapellido,string dia,string mes,string year);
	char* insertarAlumno(string matricula,string nombre, string primerapellido, string segundoapellido,int dia,int mes,int year);
	char* actualizarAlumno();
	char* borrarAlumno();
	//Profesor
	//insert into profesor(matriculaprofesor , nombre, primerapellido ,segundoapellido) values('48715967','carlos','diaz','camacho');
	char* consultarProfesor();
	char* insertarProfesor(string matriculaprofesor,string nombre, string primerapellido, string segundoapellido);
	char* actualizarProfesor();
	char* borrarProfesor();
	//MATERIA
	//insert into materia (idmateria ,nombre ) values('1CV11','POO');
	char* consultarMateria();
	char* insertarMateria(string idmateria,string nombre);
	char* actualizarMateria();
	char* borrarMateria();
	//CURSO
	//matricula  idmateria matriculaprofesor int calificacion
	char* consultarCurso();
	char* crearCurso(string matriculaAlumno,string idmateria,string matriculaprofesor,int calificacion);
	char* asingarCalificacion();
	char* borrarCurso();
};

#endif /* CONEXION_H_ */
