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

//conexion = new Conexion();
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
////////HOLGADO
/*bool Validacion::isnumber(const char *s) {
	   char* e = NULL;
	   (void) strtol(s, &e, 0);
	   return e != NULL && *e == (char) 0;
	}*/

/*bool check_number(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      return true;
}*/



int Validacion::validarCadena(int numero,int opc) {
/*
	cin>>numero;
	 if (cin.fail())
	 cout << "Not an int\n";
*/
	int temp = 0;
	bool valid= false;
	//cin>>numero;
	if (cin.good())
	        {
		//cout << "Bien." << endl;
				//valid = true;
	        }
	        else
	        {
	            //something went wrong, we reset the buffer's state to good
	            cin.clear();
	            //and empty it
	            cin.ignore(numeric_limits<streamsize>::max(),'\n');
	            cout << "Solo se aceptan numeros." << endl;
	            //conexion.wInsertarAlumno();
	            switch(opc) {
	            //ALUMNO
	            case 1:
	            	conexion.wInsertarAlumno();
	            	break;
	            case 2:
	            	conexion.wActualizarAlumno();
	            	break;
				/*case 3:
					conexion.wAsingarCalificacion();
					break;*/
	            }

	        }
	 if (std::to_string(numero).size() <= 2) { //if (boleta.size() <= 10) { Menor o igual que 2
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

return 0;
}
////////

int Validacion::validarFecha(int year,int opc) {

    if (std::to_string(year).size() == 4) { //if (boleta.size() <= 10) {
    }
    else {
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
     	//if(calificacion <= 10) GOOD ONE

		if(calificacion >= 0 && calificacion <= 10)
		//if(std::to_string(calificacion)[i] <= 10  || std::to_string(calificacion)[i] >= 10  )
        {
        	//cout << "--Valores introducidos correctamente!--\n";
			//cout << "--Valores introducidos correctamente!--\n";
         }
        else if (calificacion >= 11){
        	//cout << "--Solo debes introducir una calificacion entre 0 - 10!--\n";
        	  //      	conexion.wAsingarCalificacion();//
        	cout << "\n--ANTES DEL CLEAR --: "<< calificacion;
        	std::to_string(calificacion).clear();
        	cout << "\n--DESPUES DEL CLEAR --: "<< calificacion;
        		//resetar = calificacion;

        	cout << "\n--DESPUES DEL CALIFICACION = 0 --: "<< calificacion;
        	cout << "--Solo debes introducir una calificacion entre 0 - 10!--\n";
//checar por que no quita el numero mayor a 10 como limpiar la memoria
        	 cin.clear();
        	 cin.ignore();
         	calificacion=0;
         	//conexion.wAsingarCalificacion();//
         	menu.mostrarMenu();
        	}


        				//return 0;
         }
  //  }

    if (std::to_string(calificacion).size() <= 2) { //if (boleta.size() <= 10) {
    	//if (18 < age && age < 30)
        //alumno.setBoleta(boleta);
    }
    else {
        cout << "--Tienes que introducir solo 2 caracteres--\n";
        conexion.wAsingarCalificacion();
     }
    return 0;
}

int Validacion::validarCadenaCalificacion(int numero,int opc) {
	Menu menu;
/*
	cin>>numero;
	 if (cin.fail())
	 cout << "Not an int\n";
*/
	int temp = 0;
	bool valid= false;
	//cin>>numero;
	if (cin.good())
	        {
		//cout << "Bien." << endl;
				//valid = true;
	        }
	        else
	        {
	            //something went wrong, we reset the buffer's state to good
	            cin.clear();
	            //and empty it
	            cin.ignore(numeric_limits<streamsize>::max(),'\n');
	            cout << "Solo se aceptan numeros." << endl;
	            //free(&numero);
				//conexion.wAsingarCalificacion();
	            menu.mostrarMenu();
	        }
return 0;
}

int Validacion::validarOpc(int opc) {
	Menu menu;
/*
	cin>>numero;
	 if (cin.fail())
	 cout << "Not an int\n";
*/
	int temp = 0;
	bool valid= false;
	//cin>>numero;
	if (cin.good())
	        {
		//cout << "Bien." << endl;
				//valid = true;
	        }
	        else
	        {
	            //something went wrong, we reset the buffer's state to good
	            cin.clear();
	            //and empty it
	            cin.ignore(numeric_limits<streamsize>::max(),'\n');
	            cout << "Solo se aceptan numeros." << endl;
	            //free(&numero);
				//conexion.wAsingarCalificacion();
	            menu.mostrarMenu();
	        }
return 0;
}
