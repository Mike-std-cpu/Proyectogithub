/*
 * Validacion.cpp
 *
 *  Created on: Jul 11, 2020
 *      Author: curso
 */

#include "Validacion.h"
#include "Alumno.h"
#include "Menu.h"
#include "Conexion.h"
#include <ctype.h> //validar Mayusculas
#include <cctype>
#include <algorithm>

Validacion::Validacion() {
    // TODO Auto-generated constructor stub

}

Validacion::~Validacion() {
    // TODO Auto-generated destructor stub
}
Conexion conexion;


char* Validacion::validarInformacion(string nombre,int opc) {

    //Validar que la primera letra sea Mayuscula
    if(islower(nombre.at(0) <= 'z' ? nombre.at(0) : 'A')) {
        cout << "--La primera letra debe ser Mayuscula --\n";
        switch(opc) {
        //ALUMNO
        case 1:
            conexion.wInsertarAlumno();
            break;
        case 2:
            conexion.wActualizarAlumno();
            break;
        //PROFESOR
        case 4:
            conexion.wInsertarProfesor();
            break;
        case 5:
            conexion.wActualizarProfesor();
            break;
            //case 6:
            //  conexion.wBorrarProfesor();
            break;
        //MATERIA
        case 7:
            conexion.wInsertarMateria();
            break;
        case 8:
            conexion.wActualizarMateria();
            break;

        }
    }
    //Validar que el nombre no tenga numeros
    if (std::all_of(begin(nombre), end(nombre), ::isalpha))
    {
       //cout << "Son letras" << std::endl;

    } else {
        std::cout << "--Solo debes introducir letras!--" << std::endl;
        switch(opc) {
        case 1:
            conexion.wInsertarAlumno();
            break;
        case 2:
            conexion.wActualizarAlumno();
            break;
        //PROFESOR
        case 4:
            conexion.wInsertarProfesor();
            break;
        case 5:
            conexion.wActualizarProfesor();
            break;
        //case 6:
        //conexion.wBorrarProfesor();
        //break;
        //MATERIA
        case 7:
            conexion.wInsertarMateria();
            break;
        case 8:
            conexion.wActualizarMateria();
            break;

        }
    }

    return 0;
}

char* Validacion::validarMatricula(string boleta,int opc) {
    //Validar que solo se introduzcan enteros dentro de un String
	for(int i = 0; i < boleta.length(); i++)
    {
        if((boleta[i] >= 'a' && boleta[i] <= 'z')||(boleta[i] >= 'A' && boleta[i] <= 'Z'))
        {
            cout << "--Solo debes introducir numeros!--\n";
            //conexion.wInsertarAlumno();
            switch(opc) {
            //ALUMNO
            case 1:
                conexion.wInsertarAlumno();
                break;
            case 2:
                conexion.wActualizarAlumno();
                break;
            case 3:
                conexion.wBorrarAlumno();
                break;
            //PROFESOR
            case 4:
                conexion.wInsertarProfesor();
                break;
            case 5:
                conexion.wActualizarProfesor();
                break;
            case 6:
                conexion.wBorrarProfesor();
                break;
                //MATERIA
                //case 7:
                //	conexion.wInsertarMateria();
                break;
            case 8:
                conexion.wCrearCurso();
                break;
            case 9:
                conexion.wAsingarCalificacion();
                break;
            case 10:
                conexion.wBorrarCurso();
                break;
            }
        }
    }

    if (boleta.size() == 10) {
    	//
    }
    else {
        cout << "--Tienes que introducir 10 caracteres--\n";
        //conexion.wInsertarAlumno();
        switch(opc) {
        //ALUMNO
        case 1:
            conexion.wInsertarAlumno();
            break;
        case 2:
            conexion.wActualizarAlumno();
            break;
        case 3:
            conexion.wBorrarAlumno();
            break;
        //PROFESOR
        case 4:
            conexion.wInsertarProfesor();
            break;
        case 5:
            conexion.wActualizarProfesor();
            break;
        case 6:
            conexion.wBorrarProfesor();
            break;
            //MATERIA
            //case 7:
            //	conexion.wInsertarMateria();
            //break;
        case 8:
            conexion.wCrearCurso();
            break;
        case 9:
            conexion.wAsingarCalificacion();
            break;
        case 10:
            conexion.wBorrarCurso();
            break;
        }
    }
    return 0;
}


int Validacion::validarCadena(int numero,int opc) {

	//cin>>numero;
	//Validar que solo se introduzcan valores enteros
	if (cin.good())
	        {
		//cout << "Bien." << endl;
	        }
	        else
	        {
	        	//Limpiar el buffer si no se introduzco un int
	            cin.clear();
	            cin.ignore(numeric_limits<streamsize>::max(),'\n');
	            cout << "Solo se aceptan numeros." << endl;
	            switch(opc) {
	            //ALUMNO
	            case 1:
	            	conexion.wInsertarAlumno();
	            	break;
	            case 2:
	            	conexion.wActualizarAlumno();
	            	break;
				}

	        }
	//Validacion para dia y mes solo aceptar maximo 2 caracteres.
	if (std::to_string(numero).size() <= 2) {
		//Bien
	    }
	    else {
	        cout << "--Tienes que seguir el formato dado dd / mm / aaaa --";
	        switch(opc) {
	        //ALUMNO
	        case 1:
	            conexion.wInsertarAlumno();
	            break;
	        case 2:
	            conexion.wActualizarAlumno();
	            break;

	        }
	    }

return 0;
}
////////

int Validacion::validarFecha(int year,int opc) {
	//Validacion para el año solo aceptar 4 caracteres no mas no menos.
    if (std::to_string(year).size() == 4) {
    	//Bien
    }
    else {
        cout << "-- Tienes que seguir el formato dado dd / mm / aaaa --";
        switch(opc) {
        //ALUMNO
        case 1:
            conexion.wInsertarAlumno();
            break;
        case 2:
            conexion.wActualizarAlumno();
            break;
        }
    }
    return 0;
}


char* Validacion::validarIdMateria(string idmateria,int opc) {
	//Validacion para solo aceptar 5 caracteres no mas no menos.
    if (idmateria.size() == 5) {
    	//Bien
    }
    else {
        cout << "--Tienes que introducir 5 caracteres--\n";
        //conexion.wInsertarAlumno();
        switch(opc) {
        //MATERIA
        case 1:
            conexion.wInsertarMateria();
            break;
        case 2:
            conexion.wActualizarMateria();
            break;
        case 3:
            conexion.wBorrarMateria();
            break;
        //CURSO
        case 4:
            conexion.wCrearCurso();
            break;
        case 5:
            conexion.wAsingarCalificacion();
            break;
        case 6:
            conexion.wBorrarCurso();
            break;
        }
    }
    return 0;
}

int Validacion::validarCalificacion(int calificacion){

	Menu menu;

	int resetar= 0; //SOLO ACEPTAR del 0 al 10
	for(int i = 0; i < std::to_string(calificacion).length(); i++)
    {
     	if(calificacion >= 0 && calificacion <= 10)
		{
        	//cout << "--Valores introducidos correctamente!--\n";
		}
        else if (calificacion >= 11){
        	std::to_string(calificacion).clear();
        	cout << "\n--DESPUES DEL CALIFICACION = 0 --: "<< calificacion;
        	cout << "--Solo debes introducir una calificacion entre 0 - 10!--\n";
        	cin.clear();
        	 cin.ignore();
         	calificacion=0;
         	menu.mostrarMenu();
        	}
         }
  	//Validacion para solo aceptar maximo 2 caracteres
    if (std::to_string(calificacion).size() <= 2) {

    }
    else {
        cout << "--Tienes que introducir solo 2 caracteres--\n";
        conexion.wAsingarCalificacion();
     }
    return 0;
}

int Validacion::validarCadenaCalificacion(int numero,int opc) {
	Menu menu;
	//Validar que solo se introduzcan valores enteros
	//cin>>numero;
	if (cin.good())
	        {
			//cout << "Bien." << endl;
	        }
	        else
	        {
	        	//Limpiar el buffer si no se introduzco un int
	            cin.clear();
	            cin.ignore(numeric_limits<streamsize>::max(),'\n');
	            cout << "Solo se aceptan numeros." << endl;
	            menu.mostrarMenu();
	        }
return 0;
}

int Validacion::validarOpc(int opc) {
	Menu menu;
	//Validar que solo se introduzcan valores enteros
	//cin>>numero;
	if (cin.good())
	        {
		//cout << "Bien." << endl;
	        }
	        else
	        {
	            //Limpiar el buffer si no se introduzco un int
	            cin.clear();
	            cin.ignore(numeric_limits<streamsize>::max(),'\n');
	            cout << "Solo se aceptan numeros." << endl;
	            menu.mostrarMenu();
	        }
return 0;
}

char* Validacion::validarNombreMateria(string nombre,int opc) {
    //Validar que la primera letra sea Mayuscula
    if(islower(nombre.at(0) <= 'z' ? nombre.at(0) : 'A')) {
        cout << "--La primera letra debe ser Mayuscula --\n";
        //cout << "--OPC--\n"<< opc;
        switch(opc) {
        //ALUMNO
        case 1:
            conexion.wInsertarMateria();
            break;
        case 2:
            conexion.wActualizarMateria();
            break;
        }
    }
  return 0;
}
