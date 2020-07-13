/*
 * Conexion.cpp
 *
 *  Created on: Jun 16, 2020
 *      Author: curso
 */

#include "Conexion.h"
#include "Alumno.h"
#include "Profesor.h"
#include "Materia.h"
#include "Curso.h"
#include "Menu.h"
#include "Validacion.h"
#include <iostream>
#include <ctype.h> //validar Mayusculas
#include <cctype>
#include <algorithm>

#include <pqxx/pqxx>
#include <string.h>
using namespace std;
using namespace pqxx;


Conexion::Conexion() {

}

Conexion::~Conexion() {
// TODO Auto-generated destructor stub
}
Menu menu;
Validacion validacion;
int  Conexion::wConsultarAlumno() {

    try {
        connection c(cadenaConexion);
        if(c.is_open()) {
            cout<<"Se conecto a la BD: "<<" "<<c.dbname();
            nontransaction N(c); // * Crear un objeto no transaccional. *
            int size=sql->size();
            result R(N.exec(this->consultarAlumno())); // * Ejecutar consulta SQL *
            cout<<"\n Matricula\t\tnombre\t\t Primer apellido\t Segundo apellido\t Dia\t Mes\t Año "<<endl;
            cout<<"=================================================="<<endl;
            for(result::const_iterator c=R.begin(); c!=R.end(); ++c) {
                cout<<" "<<c[0].as<string>()<<"\t\t";
                cout<<" "<<c[1].as<string>()<<"\t\t";
                cout<<" "<<c[2].as<string>()<<"\t\t";
                cout<<" "<<c[3].as<string>()<<"\t\t";
                cout<<" "<<c[4].as<string>()<<"\t\t";
                cout<<" "<<c[5].as<string>()<<"\t\t";
                cout<<" "<<c[6].as<string>()<<endl;
                }
        } else {
            cout<<"No se conecto a la Base de datos"<<endl;
            return 1;
        }
        c.disconnect();
    } catch (const std::exception &e) {
        cerr<<e.what()<<std::endl;
        return 1;
    }
    return 0;
    /*wConsultarAlumno();
    menu.mostrarMenu();*/
}

char* Conexion::consultarAlumno() {
    sql=new string("select * from alumno");
    int size;
    size=sql->size()+1;
    char *query=new char[size];
    strcpy(query, sql->c_str());
    return query;

}
// Insert
Alumno alumno;
int  Conexion::wInsertarAlumno() {
    try {
        connection c(cadenaConexion);
        if(c.is_open()) {
            work W(c); //AGREGADO *** / * Crear un objeto transaccional. * /
            int size=sql->size();
            Alumno* alumno;
            alumno = new Alumno();
            string nombre,primerapellido,segundoapellido,matricula;
            //string nombre[100];
            int dia,mes,year;
            cout<<"\nLa matricula debe de ser de 10 caracteres \nIngrese la matricula de alumno:"<<endl;
                cin>>matricula; // OBTENER BOLETA
                validacion.validarMatricula(matricula,1); // VALIDAR MATRICULA
                alumno->setBoleta(matricula);// //INSERTAR SI SE VALIDO CORRECTAMENTE *
            cout<<"Nombre y apellidos deben empezar con Mayusculas\nNombre(s):"<<endl;// OBTENER NOMBRE
            	//cin>>nombre;
            	std::getline(std::cin >> std::ws, nombre);
            	validacion.validarInformacion(nombre,1);// // VALIDAR NOMBRE
            	alumno->setNombre(nombre); //INSERTAR SI SE VALIDO CORRECTAMENTE *
            cout<<"Apellido paterno:"<<endl;
            	cin>>primerapellido;
            	validacion.validarInformacion(primerapellido,1);
            	alumno->setPrimerApellido(primerapellido);
            cout<<"Apellido materno:"<<endl;
            	cin>>segundoapellido;
            	validacion.validarInformacion(segundoapellido,1);
            	alumno->setSegundoApellido(segundoapellido);
            cout<<"Fecha de nacimiento dd / mm / aaaa:"<<endl;
            	cin>>dia;
            	validacion.validarCadena(dia,1);  // Validar que solo se introduzcan numeros
           		cin>>mes;
           		validacion.validarCadena(mes,1);
           		cin>>year;
           		validacion.validarFecha(year,1);
            	alumno->setDia(dia);
            	alumno->setMes(mes);
            	alumno->setYear(year);
            W.exec(this->insertarAlumno(alumno->getBoleta(),alumno->getNombre(), alumno->getPrimerApellido(), alumno->getSegundoApellido(),alumno->getDia(),alumno->getMes(),alumno->getYear()));
            cout << "Valores insertados exitosamente" << endl;
            W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃƒÂ³n.
            cout<<"*****************\n"<<endl;
            wConsultarAlumno();
            menu.mostrarMenu();
        } else {
            cout<<"No se conecto a la Base de datos"<<endl;
            return 1;
        }
        c.disconnect();
    } catch (const std::exception &e) {
        cerr<<e.what()<<std::endl;
        return 1;
    }
    return 0;
 wConsultarAlumno();
 menu.mostrarMenu();
}

char* Conexion::insertarAlumno(string matricula,string nombre, string primerapellido, string segundoapellido,int dia,int mes,int year) {
    sql=new string( "INSERT INTO alumno (matricula,nombre,primerapellido,segundoapellido,dia,mes,year)" \
                    "VALUES (\'" + matricula + "\', \'" + nombre + "\', \'" + primerapellido + "\', \'" + segundoapellido + "\', \'" + std::to_string(dia) +  "\', \'" + std::to_string(mes)+  "\', \'" + std::to_string(year) + "\');");
    int size;
    size=sql->size()+1;
    char *query=new char[size];
    strcpy(query, sql->c_str());
    return query;

}
// Actualizar

int  Conexion::wActualizarAlumno() {

    try {
        connection c(cadenaConexion);
        if(c.is_open()) {
            work W(c); //AGREGADO  * Crear un objeto transaccional.
            int size=sql->size();
            W.exec(this->actualizarAlumno()); //AGREGADO ** * Ejecutar consulta SQL * /
            W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃƒÂ³n.
            cout<<"*****************\n";
            wConsultarAlumno();
            menu.mostrarMenu();
        } else {
            cout<<"No se conecto a la Base de datos"<<endl;
            return 1;
        }
        c.disconnect();
    } catch (const std::exception &e) {
        cerr<<e.what()<<std::endl;
        return 1;
    }
    return 0;
    wConsultarAlumno();
    menu.mostrarMenu();
}

char* Conexion::actualizarAlumno() {
    string nuevonombre,nombrexistente;
    int dia,mes,year;
    string eprimerapellido,nprimerapellido,nMatricula,vMatricula;
    string esegundopellido,nsegundoapellido ;
    Alumno alumno;
    string claveAlumno;
    cout << "Dame la clave del alumno a modificar" << endl;
    cin>>claveAlumno;
    validacion.validarMatricula(claveAlumno,2);
    alumno.setBoleta(claveAlumno);
    int opc;
    cout << "\nCambio de" << endl;
    cout << "1-Nombre" << endl;
    cout << "2-Primer apellido" << endl;
    cout << "3-Segundo apellido" << endl;
    cout << "4-Fecha de nacimiento" << endl;
    cout << "5-*Matricula (Se puede cambiar mientras el alumno no este inscrito dentro de un Curso)" << endl;
    cout << "6-Consultar Cursos" << endl;
    cout << "7-Salir al menu principal" << endl;
    cin>>opc;
    switch(opc) {
    case 1:
        cout << "Cambiar nombre a " << endl;
        std::getline(std::cin >> std::ws, nuevonombre);
        validacion.validarInformacion(nuevonombre,2);
        alumno.setNombre(nuevonombre);
        sql=new string("UPDATE alumno set nombre= '" + alumno.getNombre() + "' where matricula= '" + alumno.getBoleta()  + "' ");
        break;
    case 2:
        cout << "Cambiar Primer apellido a: " << endl;
        cin >> nprimerapellido;
        validacion.validarInformacion(nprimerapellido,2);
        alumno.setPrimerApellido(nprimerapellido);
        sql=new string("UPDATE alumno set primerapellido= '" + alumno.getPrimerApellido() + "' where matricula= '" + alumno.getBoleta()  + "' ");
        break;
    case 3:
        cout << "Cambiar a Segundo apellido a: " << endl;
        cin >> nsegundoapellido;
        validacion.validarInformacion(nsegundoapellido,2);			//2
        alumno.setSegundoApellido(nsegundoapellido);
        sql=new string("UPDATE alumno set segundoapellido= '" + alumno.getSegundoApellido() + "' where matricula= '" + alumno.getBoleta()  + "' ");
        break;
    case 4:
        cout << "\nFecha de nacimiento formato dd/mm/aaaa  cambiar a: " << endl;
        cin>>dia;
        validacion.validarCadena(dia,2);  // Validar que solamente se introduzcan numeros y formato
        cin>>mes;
        validacion.validarCadena(mes,2);
        cin>>year;
        validacion.validarFecha(year,2);
        alumno.setDia(dia);
        alumno.setMes(mes);
        alumno.setYear(year);
        sql=new string("UPDATE alumno set dia= '" + std::to_string(alumno.getDia()) + "',mes= '" + std::to_string(alumno.getMes()) + "',year= '" + std::to_string(alumno.getYear()) + "' where matricula= '" + alumno.getBoleta()  + "' ");
        break;
    case 5:
        cout << "\nMatricula actual : " << endl;
        cin>>vMatricula;
        validacion.validarMatricula(vMatricula,2);
        cout << "\nCambiar a : " << endl;
        cin>>nMatricula;
        validacion.validarMatricula(nMatricula,2);
        alumno.setBoleta(nMatricula);
        sql=new string("UPDATE alumno set matricula= '" + alumno.getBoleta() + "' where matricula= '" + vMatricula  + "' ");
        break;
    case 6:
        cout << "\n--- Cursos ---" << endl;
        wConsultarCurso();
        cout << "\n--- Alumnos ---" << endl;
        wConsultarAlumno();
        wActualizarAlumno();
        break;
    default:
    	cout<<"salir ...\n";
    	//menu.mostrarMenu();
        break;
    }
    int size;
    size=sql->size()+1;
    char *query=new char[size];
    strcpy(query, sql->c_str());
    return query;
//    wActualizarAlumno();
}

// Borrar

int  Conexion::wBorrarAlumno() {

    try {
        connection c(cadenaConexion);
        if(c.is_open()) {
            work W(c); //AGREGADO ***  Crear un objeto transaccional.
            int size=sql->size();
            W.exec(this->borrarAlumno()); //AGREGADO  * Ejecutar consulta SQL * /
            W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃƒÂ³n.
            cout<<"*****************\n";
            wConsultarAlumno();
            menu.mostrarMenu();
        } else {
            cout<<"No se conecto a la Base de datos"<<endl;
            return 1;
        }
        c.disconnect();
    } catch (const std::exception &e) {
        cerr<<e.what()<<std::endl;
        return 1;
    }
    return 0;
    wConsultarAlumno();
    menu.mostrarMenu();
}

char* Conexion::borrarAlumno() {
    Alumno alumno;
    string nombre,matricula,pregunta;
    int opc;
    cout << "\n1-*Borrar a un alumno (Se puede borrar mientras el alumno no este inscrito dentro de un Curso)" << endl;
    cout << "2-Borrar toda la tabla (Se puede borrar mientras ningun alumno este inscrito dentro de un Curso)" << endl;
    cout << "3-Consultar Cursos" << endl;
    cout << "4-Salir al menu principal" << endl;
    cin>>opc;
    switch(opc) {
    case 1:
        cout << "\nMatricula " << endl;
        cin >> matricula;
        validacion.validarMatricula(matricula,3);		//3
        alumno.setBoleta(matricula);
        sql=new string("DELETE from alumno where matricula = '"+ alumno.getBoleta() +"'");
        break;
    case 2:
        cout << "\n¿Estas seguro S/N?" << endl;
    	cin >> pregunta;
    	if(pregunta == "S" || pregunta == "s") {
    	cout << "\nLa tabla fue ELIMINADA correctamente" << endl;
    	sql=new string("DELETE from alumno");
    	} else { cout << "\n-No se realizaron cambios a la tabla- \n" << endl; menu.mostrarMenu(); }
        break;
    case 3:
        cout << "\n--- Cursos ---" << endl;
        wConsultarCurso();
        cout << "\n--- Alumnos ---" << endl;
        wConsultarAlumno();
        wBorrarAlumno();
        break;
    default:
        cout<<"salir ...\n";
        menu.mostrarMenu();
        break;
    }
    int size;
    size=sql->size()+1;
    char *query=new char[size];
    strcpy(query, sql->c_str());
    return query;
}

//************************************************** PROFESOR **************************************************
int  Conexion::wConsultarProfesor() {
    try {
        connection c(cadenaConexion);
        if(c.is_open()) {
            cout<<"Se conecto a la BD: "<<" "<<c.dbname();
            nontransaction N(c); // * Crear un objeto no transaccional. *
            int size=sql->size();
            result R(N.exec(this->consultarProfesor())); // * Ejecutar consulta SQL *
            cout<<"\n Matricula\tnombre\t\t Primer apellido\t Segundo apellido "<<endl;
            cout<<"=================================================="<<endl;
            for(result::const_iterator c=R.begin(); c!=R.end(); ++c) {
            //char* insertarProfesor(string matriculaprofesor,string nombre, string primerapellido, string segundoapellido);
                cout<<" "<<c[0].as<string>()<<"\t\t";
                cout<<" "<<c[1].as<string>()<<"\t\t";
                cout<<" "<<c[2].as<string>()<<"\t\t";
                cout<<" "<<c[3].as<string>()<<endl;
            }
        } else {
            cout<<"No se conecto a la Base de datos"<<endl;
            return 1;
        }
        c.disconnect();
    } catch (const std::exception &e) {
        cerr<<e.what()<<std::endl;
        return 1;
    }
    return 0;
}
char* Conexion::consultarProfesor() {
    sql=new string("select * from profesor");
    int size;
    size=sql->size()+1;
    char *query=new char[size];
    strcpy(query, sql->c_str());
    return query;

}
// Insert
int  Conexion::wInsertarProfesor() {
    try {
        connection c(cadenaConexion);
        if(c.is_open()) {
            work W(c); //AGREGADO *** / * Crear un objeto transaccional. * /
            int size=sql->size();
            Profesor* profesor;
            profesor = new Profesor();
            //insert into profesor(matriculaprofesor , nombre, primerapellido ,segundoapellido) values('48715967','carlos','diaz','camacho');
            string nombre,primerapellido,segundoapellido,matriculaprofesor;
            cout<<"--Profesor--"<<endl;
            cout<<"Nombre y apellidos deben empezar con Mayusculas\nNombre(s):"<<endl;
            std::getline(std::cin >> std::ws, nombre);				//4
            validacion.validarInformacion(nombre,4);
            profesor->setNombre(nombre);
            cout<<"Apellido paterno:"<<endl;
            cin>>primerapellido;
            validacion.validarInformacion(primerapellido,4);
            profesor->setPrimerApellido(primerapellido);
            cout<<"Apellido materno:"<<endl;
            cin>>segundoapellido;
            validacion.validarInformacion(segundoapellido,4);
            profesor->setSegundoApellido(segundoapellido);
            cout<<"La matricula debe ser de 10 caracteres\nIngrese matricula del profesor:"<<endl;
            cin>>matriculaprofesor;
            validacion.validarMatricula(matriculaprofesor,4);
            profesor->setMatriculaProfesor(matriculaprofesor);
            W.exec(this->insertarProfesor(profesor->getMatriculaProfesor(),profesor->getNombre(), profesor->getPrimerApellido(), profesor->getSegundoApellido()));
            cout << "Profesor creado exitosamente" << endl;
            W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃƒÂ³n.
            cout<<"*****************\n"<<endl;
            wConsultarProfesor();
            menu.mostrarMenu();
        } else {
            cout<<"No se conecto a la Base de datos"<<endl;
            return 1;
        }
        c.disconnect();
    } catch (const std::exception &e) {
        cerr<<e.what()<<std::endl;
        return 1;
    }
    return 0;
}

char* Conexion::insertarProfesor(string matriculaprofesor,string nombre, string primerapellido, string segundoapellido) {
    sql=new string( "INSERT INTO profesor (matriculaprofesor,nombre,primerapellido,segundoapellido)" \
                    "VALUES (\'" + matriculaprofesor + "\', \'" + nombre + "\', \'" + primerapellido + "\', \'" + segundoapellido + "\');");
    int size;
    size=sql->size()+1;
    char *query=new char[size];
    strcpy(query, sql->c_str());
    return query;

}
// Actualizar

int  Conexion::wActualizarProfesor() {
    try {
        connection c(cadenaConexion);
        if(c.is_open()) {
            work W(c); //AGREGADO  * Crear un objeto transaccional.
            int size=sql->size();
            W.exec(this->actualizarProfesor()); //AGREGADO ** * Ejecutar consulta SQL * /
            W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃƒÂ³n.
            cout<<"*****************\n";
            wConsultarProfesor();
            menu.mostrarMenu();
        } else {
            cout<<"No se conecto a la Base de datos"<<endl;
            return 1;
        }
        c.disconnect();
    } catch (const std::exception &e) {
        cerr<<e.what()<<std::endl;
        return 1;
    }
    return 0;
}

char* Conexion::actualizarProfesor() {
    string nuevonombre,nombrexistente;
    int dia,mes,year;
    string nsegundoapellido,nprimerapellido,nMatricula,vMatricula;
    Profesor profesor;
    string claveProfesor;
    cout << "Dame la matricula del Profesor a modificar" << endl;
    cin>>claveProfesor;
    profesor.setMatriculaProfesor(claveProfesor);
    int opc;
    cout << "\nCambio de" << endl;
    cout << "1-Nombre" << endl;
    cout << "2-Primer apellido" << endl;
    cout << "3-Segundo apellido" << endl;
    cout << "4-Matricula* (Se puede cambiar mientras el profesor no este inscrito dentro de un Curso)" << endl;
    cout << "5-Consultar Cursos" << endl;
    cout << "6-Salir al menu principal" << endl;
    cin>>opc;
    switch(opc) {
    case 1:
        cout << "Cambiar nombre a " << endl;
        std::getline(std::cin >> std::ws, nuevonombre);			//5
        validacion.validarInformacion(nuevonombre,5);
        profesor.setNombre(nuevonombre);
        sql=new string("UPDATE profesor set nombre= '" + profesor.getNombre() + "' where matriculaprofesor= '" + profesor.getMatriculaProfesor()  + "' ");
        break;
    case 2:
        cout << "Cambiar Primer apellido a: " << endl;
        cin >> nprimerapellido;
        validacion.validarInformacion(nprimerapellido,5);
        profesor.setPrimerApellido(nprimerapellido);
        sql=new string("UPDATE profesor set primerapellido= '" + profesor.getPrimerApellido() + "' where matriculaprofesor= '" + profesor.getMatriculaProfesor()  + "' ");
        break;
    case 3:
        cout << "Cambiar a Segundo apellido a: " << endl;
        cin >> nsegundoapellido;
        validacion.validarInformacion(nsegundoapellido,5);
        profesor.setSegundoApellido(nsegundoapellido);
        sql=new string("UPDATE profesor set segundoapellido= '" + profesor.getSegundoApellido() + "' where matriculaprofesor= '" + profesor.getMatriculaProfesor()  + "' ");
        break;
    case 4:
        cout << "\nMatricula actual : " << endl;
        cin>>vMatricula;
        validacion.validarMatricula(vMatricula,5);
        cout << "\nCambiar a : " << endl;
        cin>>nMatricula;
        validacion.validarMatricula(nMatricula,5);
        profesor.setMatriculaProfesor(nMatricula);
        sql=new string("UPDATE profesor set matriculaprofesor= '" + profesor.getMatriculaProfesor() + "' where matriculaprofesor= '" + vMatricula  + "' ");
        break;
    case 5:
        cout << "\n--- Cursos ---" << endl;
        wConsultarCurso();
        cout << "\n--- Profesores ---" << endl;
        wConsultarProfesor();
        wActualizarProfesor();
        break;
    default:
        cout<<"salir ...\n";
        menu.mostrarMenu();
        break;
    }
    int size;
    size=sql->size()+1;
    char *query=new char[size];
    strcpy(query, sql->c_str());
    return query;
}

// Borrar

int  Conexion::wBorrarProfesor() {
    try {
        connection c(cadenaConexion);
        if(c.is_open()) {
            work W(c); //AGREGADO ***  Crear un objeto transaccional.
            int size=sql->size();
            W.exec(this->borrarProfesor()); //AGREGADO  * Ejecutar consulta SQL * /
            W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃƒÂ³n.
            cout<<"*****************\n";
            wConsultarProfesor();
            menu.mostrarMenu();
        } else {
            cout<<"No se conecto a la Base de datos"<<endl;
            return 1;
        }
        c.disconnect();
    } catch (const std::exception &e) {
        cerr<<e.what()<<std::endl;
        return 1;
    }
    return 0;
}

char* Conexion::borrarProfesor() {
    Profesor profesor;
    string nombre,matricula,seg;
	int opc;
    cout << "\n1-*Borrar a un profesor (Se puede borrar mientras el profesor no este inscrito dentro de un Curso)" << endl;
    cout << "2-Borrar toda la tabla (SSe puede borrar mientras ningun profesor este inscrito dentro de un Curso)" << endl;
    cout << "3-Colsultar Cursos" << endl;
    cout << "4-Salir al menu principal" << endl;
    cin>>opc;
    switch(opc) {
    case 1:
        cout << "\nMatricula " << endl;
        cin >> matricula;					//6
        validacion.validarMatricula(matricula,6);
        profesor.setMatriculaProfesor(matricula);
        sql=new string("DELETE from profesor where matriculaprofesor = '"+ profesor.getMatriculaProfesor() +"'");
        break;
    case 2:
    	cout << "\n¿Estas seguro S/N?" << endl;
    	cin >> seg;
    	//getline(cin, seg);
    	if(seg == "S" || seg == "s") {
    		cout << "\nLa tabla fue ELIMINADA correctamente" << endl;
    	sql=new string("DELETE from profesor");
    	} else { cout << "\n-No se realizaron cambios a la tabla- \n" << endl; menu.mostrarMenu(); }
        break;
    case 3:
        cout << "\n--- Cursos ---" << endl;
        wConsultarCurso();
        cout << "\n--- Profesores ---" << endl;
        wConsultarProfesor();
        wBorrarProfesor();
        cout << "3-Colsultar Cursos" << endl;
        break;
    default:
        cout<<"salir ...\n";
        menu.mostrarMenu();
        break;
    }

    int size;
    size=sql->size()+1;
    char *query=new char[size];
    strcpy(query, sql->c_str());
    return query;
}

//************************************************** MATERIA **************************************************

int  Conexion::wConsultarMateria() {

    try {
        connection c(cadenaConexion);
        if(c.is_open()) {
            cout<<"Se conecto a la BD: "<<" "<<c.dbname();
            nontransaction N(c); // * Crear un objeto no transaccional. *
            int size=sql->size();
            result R(N.exec(this->consultarMateria())); // * Ejecutar consulta SQL *
            //insert into materia (idmateria ,nombre ) values('1CV11','POO');
            cout<<"\n Id_materia\tNombre\t"<<endl;
            cout<<"=================================================="<<endl;
            for(result::const_iterator c=R.begin(); c!=R.end(); ++c) {
                cout<<" "<<c[0].as<string>()<<"\t\t";
                cout<<" "<<c[1].as<string>()<<endl;
            }
        } else {
            cout<<"No se conecto a la Base de datos"<<endl;
            return 1;
        }
        c.disconnect();
    } catch (const std::exception &e) {
        cerr<<e.what()<<std::endl;
        return 1;
    }
    return 0;
}

char* Conexion::consultarMateria() {
    sql=new string("select * from materia");
    int size;
    size=sql->size()+1;
    char *query=new char[size];
    strcpy(query, sql->c_str());
    return query;

}
// Insert
int  Conexion::wInsertarMateria() {
    try {
        connection c(cadenaConexion);
        if(c.is_open()) {
            work W(c); //AGREGADO *** / * Crear un objeto transaccional. * /
            int size=sql->size();
            Materia* materia;
            materia = new Materia();
            //insert into materia (idmateria ,nombre ) values('1CV11','POO');
            string idmateria,nombre;
            cout<<"La id debe de ser de 5 caracteres\nId materia:"<<endl;
            cin>>idmateria;
            validacion.validarIdMateria(idmateria,1); // ->1 Validar materia
            materia->setIdmateria(idmateria);
            cout<<"El nombre debe empezar con mayusculas\nNombre:"<<endl;
            std::getline(std::cin >> std::ws, nombre);
            validacion.validarNombreMateria(nombre,1);	  // validar Nombre Materia(1)
            materia->setNombre(nombre);
            W.exec(this->insertarMateria(materia->getIdmateria(),materia->getNombre()));
            cout << "Valores insertados exitosamente" << endl;
            W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃƒÂ³n.
            cout<<"*****************\n"<<endl;
            wConsultarMateria();
            menu.mostrarMenu();
        } else {
            cout<<"No se conecto a la Base de datos"<<endl;
            return 1;
        }
        c.disconnect();
    } catch (const std::exception &e) {
        cerr<<e.what()<<std::endl;
        return 1;
    }
    return 0;
}


char* Conexion::insertarMateria(string idmateria,string nombre) {
    sql=new string( "INSERT INTO materia (idmateria,nombre)" \
                    "VALUES (\'" + idmateria + "\', \'" + nombre + "\');");
    int size;
    size=sql->size()+1;
    char *query=new char[size];
    strcpy(query, sql->c_str());
    return query;

}
// Actualizar

int  Conexion::wActualizarMateria() {
    try {
        connection c(cadenaConexion);
        if(c.is_open()) {
            work W(c); //AGREGADO  * Crear un objeto transaccional.
            int size=sql->size();
            W.exec(this->actualizarMateria()); //AGREGADO ** * Ejecutar consulta SQL * /
            //cout << "Campo actualizado exitosamente" << endl;
            W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃƒÂ³n.
            cout<<"*****************\n";
            wConsultarMateria();
            menu.mostrarMenu();
        } else {
            cout<<"No se conecto a la Base de datos"<<endl;
            return 1;
        }
        c.disconnect();
    } catch (const std::exception &e) {
        cerr<<e.what()<<std::endl;
        return 1;
    }
    return 0;
}

char* Conexion::actualizarMateria() {
    string nuevonombre,nombrexistente;
    int dia,mes,year;
    string nsegundoapellido,nprimerapellido,nId,vId;
    Materia materia;
    string claveMateria;
    cout << "Dame la clave de la Materia a modificar" << endl;
    cin>>claveMateria;
    validacion.validarIdMateria(claveMateria,2); 		// ->2 Validar materia
    materia.setIdmateria(claveMateria);
    int opc;
    cout << "\nCambio de" << endl;
    cout << "1-Nombre" << endl;
    cout << "2-Id* (Se puede actualizar mientras la materia no este asginada dentro de un Curso)"<< endl;
    cout << "3-Colsultar Cursos" << endl;
    cout << "4-Salir al menu principal" << endl;
    cin>>opc;
    switch(opc) {
    case 1:
        cout << "Cambiar nombre a " << endl;
        //cin >> nuevonombre;
        std::getline(std::cin >> std::ws, nuevonombre);
        //validacion.validarInformacion(nuevonombre,8);			// 8
        validacion.validarNombreMateria(nuevonombre,2);	  // validar Nombre Materia(1)
        materia.setNombre(nuevonombre);
        sql=new string("UPDATE materia set nombre= '" + materia.getNombre() + "' where idmateria= '" + materia.getIdmateria()  + "' ");
        break;
    case 2:
        cout << "\nId actual : " << endl;
        cin>>vId;
        validacion.validarIdMateria(vId,2);
        cout << "\nCambiar a : " << endl;
        cin>>nId;
        validacion.validarIdMateria(vId,2);
        materia.setIdmateria(nId);
        sql=new string("UPDATE materia set idmateria= '" + materia.getIdmateria() + "' where idmateria= '" + vId + "' ");
        break;
    case 3:
        cout << "\n--- Cursos ---" << endl;
        wConsultarCurso();
        cout << "\n--- Materias ---" << endl;
        wConsultarMateria();
        wActualizarMateria();
        break;
    default:
        cout<<"salir ...\n";
        menu.mostrarMenu();
        break;
    }
    int size;
    size=sql->size()+1;
    char *query=new char[size];
    strcpy(query, sql->c_str());
    return query;
}

// Borrar

int  Conexion::wBorrarMateria() {

    try {
        connection c(cadenaConexion);
        if(c.is_open()) {
            work W(c); //AGREGADO ***  Crear un objeto transaccional.
            int size=sql->size();
            W.exec(this->borrarMateria()); //AGREGADO  * Ejecutar consulta SQL * /
            cout << "Los valores fueron borrados exitosamente" << endl;
            W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃƒÂ³n.
            cout<<"*****************\n";
            wConsultarMateria();
            menu.mostrarMenu();
        } else {
            cout<<"No se conecto a la Base de datos"<<endl;
            return 1;
        }
        c.disconnect();
    } catch (const std::exception &e) {
        cerr<<e.what()<<std::endl;
        return 1;
    }
    return 0;
}

char* Conexion::borrarMateria() {
    Materia materia;
    string nombre,idMateria,pregunta;
    int opc;
    cout << "\n1-Borrar una materia*(Se puede borrar mientras la materia no este asginada dentro de un Curso)" << endl;
    cout << "2-Borrar toda la tabla* (Se puede borrar mientras ninguna materia este inscrita dentro de un Curso)" << endl;
    cout << "3-Colsultar Cursos" << endl;
    cout << "4-Salir al menu principal" << endl;
    cin>>opc;
    switch(opc) {
    case 1:
        cout << "\nId materia " << endl;
        cin >> idMateria;
        validacion.validarIdMateria(idMateria,3); //  	->3 Validar materia
        materia.setIdmateria(idMateria);
        sql=new string("DELETE from materia where idmateria = '"+ materia.getIdmateria() +"'");
        break;
    case 2:
        cout << "\n¿Estas seguro S/N?" << endl;
    	cin >> pregunta;
    	if(pregunta == "S" || pregunta == "s") {
    		cout << "\nLa tabla fue ELIMINADA correctamente" << endl;
    		sql=new string("DELETE from materia");
    	} else { cout << "\n-No se realizaron cambios a la tabla- \n" << endl; menu.mostrarMenu(); }
        break;
    case 3:
        cout << "\n--- Cursos ---" << endl;
        wConsultarCurso();
        cout << "\n--- Materias ---" << endl;
        wConsultarMateria();
        wBorrarMateria();
        break;
    default:
        cout<<"salir ...\n";
        menu.mostrarMenu();
        break;
    }

    int size;
    size=sql->size()+1;
    char *query=new char[size];
    strcpy(query, sql->c_str());
    return query;
}
//********************** CURSO

int  Conexion::wConsultarCurso() {
    try {
        connection c(cadenaConexion);
        if(c.is_open()) {
            cout<<"Se conecto a la BD: "<<" "<<c.dbname();
            nontransaction N(c); // * Crear un objeto no transaccional. *
            int size=sql->size();
            result R(N.exec(this->consultarCurso())); // * Ejecutar consulta SQL *
            //insert into materia (idmateria ,nombre ) values('1CV11','POO');
            cout<<"\n Matricula Alumno\tId_materia\tMatricula Profesor\tCalificacion"<<endl;
            cout<<"=================================================="<<endl;
            for(result::const_iterator c=R.begin(); c!=R.end(); ++c) {
                cout<<" "<<c[0].as<string>()<<"\t\t";
                cout<<" "<<c[1].as<string>()<<"\t\t";
                cout<<" "<<c[2].as<string>()<<"\t\t";
                cout<<" "<<c[3].as<string>()<<endl;
            }
        } else {
            cout<<"No se conecto a la Base de datos"<<endl;
            return 1;
        }
        c.disconnect();
    } catch (const std::exception &e) {
        cerr<<e.what()<<std::endl;
        return 1;
    }
    return 0;
}

char* Conexion::consultarCurso() {
    sql=new string("select * from curso");
    int size;
    size=sql->size()+1;
    char *query=new char[size];
    strcpy(query, sql->c_str());
    return query;

}
// Insert
//Alumno alumno;
int  Conexion::wCrearCurso() {
    try {
        connection c(cadenaConexion);
        if(c.is_open()) {
            work W(c); //AGREGADO *** / * Crear un objeto transaccional. * /
            int size=sql->size();
            Curso* curso;
            curso = new Curso();
            //char* crearCurso(string matricula,string idmateria,string matriculaprofesor,int calificacion)
            string matriculaAlumno,idmateria,matriculaprofesor;
            int calificacion;
            cout<<"La matricula debe ser de 10 caracteres\nMatricula de alumno:"<<endl;
            cin>>matriculaAlumno;
            validacion.validarMatricula(matriculaAlumno,8);			// 8 -> Validar matricula
            curso->setMatriculaAlumno(matriculaAlumno);
            cout<<"La matricula debe ser de 5 caracteres\nId_materia:"<<endl;
            cin>>idmateria;
            validacion.validarIdMateria(idmateria,4); //  	->4 Validar materia
            curso->setIdmateria(idmateria);
            cout<<"La matricula debe ser de 10 caracteres\nMatricula de profesor:"<<endl;
            cin>>matriculaprofesor;
            validacion.validarMatricula(matriculaprofesor,8);			// 8 -> Validar matricula
            curso->setMatriculaProfesor(matriculaprofesor);
            curso->setCalificacion(0); //Se asigna 0 por defecto
            W.exec(this->crearCurso(curso->getMatriculaAlumno(),curso->getIdmateria(),curso->getMatriculaProfesor(),curso->getCalificacion()));
            W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃƒÂ³n.
            cout<<"*****************\n"<<endl;
            wConsultarCurso();
            menu.mostrarMenu();
        } else {
            cout<<"No se conecto a la Base de datos"<<endl;
            return 1;
        }
        c.disconnect();
    } catch (const std::exception &e) {
        cerr<<e.what()<<std::endl;
        return 1;
    }
    return 0;
}

char* Conexion::crearCurso(string matriculaAlumno,string idmateria,string matriculaprofesor,int calificacion) {
//matricula idmateria matriculaprofesor int calificacion
    sql=new string( "INSERT INTO curso (matricula,idmateria,matriculaprofesor,calificacion)" \
                    "VALUES (\'" + matriculaAlumno + "\', \'" + idmateria + "\', \'" + matriculaprofesor + "\',\'" + std::to_string(calificacion) +  "\');");
    int size;
    size=sql->size()+1;
    char *query=new char[size];
    strcpy(query, sql->c_str());
    return query;

}
////// ACTUALIZAR CALFICACION
int  Conexion::wAsingarCalificacion() {
    try {
        connection c(cadenaConexion);
        if(c.is_open()) {
            work W(c); //AGREGADO  * Crear un objeto transaccional.
            int size=sql->size();
            W.exec(this->asingarCalificacion()); //AGREGADO ** * Ejecutar consulta SQL * /
            cout << "Calificacion asignada exitosamente" << endl;
            W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃƒÂ³n.
            cout<<"*****************\n";
            wConsultarCurso();
            menu.mostrarMenu();
        } else {
            cout<<"No se conecto a la Base de datos"<<endl;
            return 1;
        }
        c.disconnect();
    } catch (const std::exception &e) {
        cerr<<e.what()<<std::endl;
        return 1;
    }
    return 0;
}

char* Conexion::asingarCalificacion() {
    Curso curso;

    string matriculaAlumno,idmateria,matriculaprofesor;
    int calificacion;
    //int reset = 0;
    cout<<"Dame la Matricula del alumno:"<<endl;
    cin>>matriculaAlumno;
    validacion.validarMatricula(matriculaAlumno,9);			// 9 -> Validar matricula
    curso.setMatriculaAlumno(matriculaAlumno);
    cout<<"Dame la clave de la materia:"<<endl;
    cin>>idmateria;
    validacion.validarIdMateria(idmateria,5); //  	->5 Validar materia
    curso.setIdmateria(idmateria);
    cout<<"Dame la matricula del profesor:"<<endl;
    cin>>matriculaprofesor;
    //validacion.validarMatricula(matriculaprofesor,9);			// 9 -> Validar matricula
    curso.setMatriculaProfesor(matriculaprofesor);
    cout<<"La calificacion debe de ser entre 0-10 y nomas de 2 caracteres \nDame la calificacion:"<<endl;
    //calificacion = 0;
    cin>>calificacion;
    //validacion.validarCadena(calificacion,3);
    validacion.validarCadenaCalificacion(calificacion,3);
    validacion.validarCalificacion(calificacion);			// Validar calificacion
    curso.setCalificacion(calificacion);
    sql=new string("UPDATE curso set calificacion= '" + std::to_string(curso.getCalificacion()) + "' where idmateria= '" + curso.getIdmateria()  + "' AND matricula='" + curso.getMatriculaAlumno()  + "'  ");
//UPDATE curso set calificacion = 6 where idmateria= '1CV15' and matricula= '25478412';
    int size;
    size=sql->size()+1;
    char *query=new char[size];
    strcpy(query, sql->c_str());
    return query;
}

int  Conexion::wBorrarCurso() {
    try {
        connection c(cadenaConexion);
        if(c.is_open()) {
            work W(c); //AGREGADO ***  Crear un objeto transaccional.
            int size=sql->size();
            W.exec(this->borrarCurso()); //AGREGADO  * Ejecutar consulta SQL * /
            cout << "El curso fue borrado exitosamente" << endl;
            W.commit(); //COMMIT es el comando SQL que se utiliza para almacenar los cambios realizados por una transacciÃƒÂ³n.
            cout<<"*****************\n";
            wConsultarCurso();
            menu.mostrarMenu();
        } else {
            cout<<"No se conecto a la Base de datos"<<endl;
            return 1;
        }
        c.disconnect();
    } catch (const std::exception &e) {
        cerr<<e.what()<<std::endl;
        return 1;
    }
    return 0;
}

char* Conexion::borrarCurso() {
    Curso curso;
    string matriculaAlumno,matriculaprofesor,idMateria,pregunta;
    int opc;
    cout << "\n1-Borrar alumno de un curso" << endl;
    cout << "2-Borrar profesor de un curso" << endl;
    cout << "3-Borrar un curso* (Todos los alumnos y profesores inscritos seran borrados del curso)" << endl;
    cout << "4-Borrar todos los cursos* (Todos los alumnos y profesores inscritos seran borrados del Cursos)" << endl;
    cout << "5-Salir al menu principal" << endl;
    cin>>opc;
    switch(opc) {
    case 1:
        cout << "\nMatricula de alumno " << endl;
        cin >> matriculaAlumno;
        validacion.validarMatricula(matriculaAlumno,10);			// 10 -> Validar matricula
        curso.setMatriculaAlumno(matriculaAlumno);
        cout << "\nSecuencia de materia" << endl;
        cin >> idMateria;
        validacion.validarIdMateria(idMateria,6); //  	->6 Validar materia
        curso.setIdmateria(idMateria);
        //sql=new string("DELETE from curso where matricula = '"+ curso.getMatriculaAlumno() +"'");
        sql=new string("DELETE from curso where matricula= '" + curso.getMatriculaAlumno()  + "' AND idmateria='" + curso.getIdmateria()  + "'  ");

        break;
    case 2:
        cout << "\nMatricula de profesor" << endl;
        cin >> matriculaprofesor;
        validacion.validarMatricula(matriculaprofesor,10);			// 10 -> Validar matricula
        curso.setMatriculaProfesor(matriculaprofesor);
        cout << "\nSecuencia de materia" << endl;
        cin >> idMateria;
        validacion.validarIdMateria(idMateria,6); //  	->6 Validar materia
        curso.setIdmateria(idMateria);
        sql=new string("DELETE from curso where idmateria= '" + curso.getIdmateria()  + "' AND matriculaprofesor='" + curso.getMatriculaProfesor()  + "'  ");
        break;
    case 3:
        cout << "\nId de la materia" << endl;
        cin >> idMateria;
        validacion.validarIdMateria(idMateria,6); //  	->6 Validar materia
        curso.setIdmateria(idMateria);
        sql=new string("DELETE from curso where idmateria = '"+ curso.getIdmateria() +"'");
        break;
    case 4:
    cout << "\n¿Estas seguro S/N?" << endl;
	cin >> pregunta;
	//getline(cin, seg);
	if(pregunta == "S" || pregunta == "s") {
		cout << "\nLa tabla fue ELIMINADA correctamente" << endl;
		sql=new string("DELETE from curso");
	} else { cout << "\n-No se realizaron cambios a la tabla- \n" << endl; menu.mostrarMenu(); }
    break;
    default:
        cout<<"salir ...\n";
        menu.mostrarMenu();
        break;
    }
    int size;
    size=sql->size()+1;
    char *query=new char[size];
    strcpy(query, sql->c_str());
    return query;

}
