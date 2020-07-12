/*
 * Validacion.cpp
 *
 *  Created on: Jul 11, 2020
 *      Author: curso
 */

#include "Validacion.h"
#include "Alumno.h"
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
    //Conexion conexion;
    //Validar que la primera letra sea Mayuscula
    if(islower(nombre.at(0) <= 'z' ? nombre.at(0) : 'A')) {
        cout << "--La primera letra debe ser Mayuscula --\n";
        //cout << "--OPC--\n"<< opc;
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
            /*case 9:
            	conexion.wBorrarAlumno();
            	break;*/
        }
    }
    //Validar que el nombre no tenga numeros
    if (std::all_of(begin(nombre), end(nombre), ::isalpha))
    {
        //std::cout << "Son letras" << std::endl;
        //break;
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
        /*case 9:
            conexion.wBorrarAlumno();
            break;
*/
        }
    }

    return 0;
}

char* Validacion::validarMatricula(string boleta,int opc) {
    for(int i = 0; i < boleta.length(); i++)
    {
        if((boleta[i] >= 'a' && boleta[i] <= 'z')||(boleta[i] >= 'A' && boleta[i] <= 'Z'))
            //if((aStrn[index] > 64 && aStrn[index] < 91) || (aStrn[index] > 96 && aStrn[index] < 123))
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

    if (boleta.size() == 10) { //if (boleta.size() <= 10) {
        //alumno.setBoleta(boleta);
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
    return 0;
}

int Validacion::validarFecha(int dia,int mes,int year,int opc) {
    if (std::to_string(dia).size() <= 2) { //if (boleta.size() <= 10) { Menor o igual que 2
        //alumno.setBoleta(boleta);
    }
    else {
        cout << "--Tienes que seguir el formato dado dd / mm / aaaa --";
        //conexion.wInsertarAlumno();
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
    if (std::to_string(mes).size() <= 2) { //if (boleta.size() <= 10) {
    }
    else {
        //cout << "Tienes que poner 2 caracteres";
        cout << "--Tienes que seguir el formato dado dd / mm / aaaa --";
        //conexion.wInsertarAlumno();
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
    if (std::to_string(year).size() == 4) { //if (boleta.size() <= 10) {
    }
    else {
        //cout << "Tienes que poner 4 caracteres";
        cout << "-- Tienes que seguir el formato dado dd / mm / aaaa --";
        //conexion.wInsertarAlumno();
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

    if (idmateria.size() == 5) { //if (boleta.size() <= 10) {
        //alumno.setBoleta(boleta);
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

        }
    }
    return 0;
}

int Validacion::validarCalificacion(int calificacion){
for(int i = 0; i < std::to_string(calificacion).length(); i++)
    {
        if((std::to_string(calificacion)[i] >= 'a' && std::to_string(calificacion)[i] <= 'z')||(std::to_string(calificacion)[i] >= 'A' && std::to_string(calificacion)[i] <= 'Z'))
            //if((aStrn[index] > 64 && aStrn[index] < 91) || (aStrn[index] > 96 && aStrn[index] < 123))
        {
            cout << "--Solo debes introducir numeros!--\n";
            conexion.wAsingarCalificacion();
         }
    }

for(int i = 0; i < std::to_string(calificacion).length(); i++)
    {
        if(std::to_string(calificacion)[i] <= 10 )
            //if((aStrn[index] > 64 && aStrn[index] < 91) || (aStrn[index] > 96 && aStrn[index] < 123))
        {
        	cout << "--Solo debes introducir una calificacion entre 0 - 10!--\n";
        	conexion.wAsingarCalificacion();//
         }
        /*else{

         }*/
    }

    if (std::to_string(calificacion).size() <= 2) { //if (boleta.size() <= 10) {
        //alumno.setBoleta(boleta);
    }
    else {
        cout << "--Tienes que introducir 10 caracteres--\n";
        conexion.wAsingarCalificacion();
     }
    return 0;
}
