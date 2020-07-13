/*
 * Menu.cpp
 *
 *  Created on: Jul 10, 2020
 *      Author: curso
 */

#include "Menu.h"
#include "Validacion.h"
#include "Conexion.h"
Menu::Menu() {
	// TODO Auto-generated constructor stub

}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}
int opc=0;

void Menu::mostrarMenu() {
	 int actOpc;//opc;
	 	Validacion *validacion;
	 	validacion=new Validacion();
	    Conexion *conexion;
	    conexion=new Conexion();
	    do {
	        cout<<"\n1. Registrar alumno. "<<endl;
	        cout<<"2. Registrar profesor. "<<endl;
	        cout<<"3. Registrar materias. "<<endl;
	        cout<<"4. Administrar grupos. "<<endl;
	        cout<<"5. Asignar materias a profesor y inscribir alumno a un curso. "<<endl;
	        cout<<"6. Ingresar calificaciones. "<<endl;
	        cout<<"8. Salir."<<endl<<endl;
	        cin>>opc;
		    //VALIDAR OPC PARA QUE SOLO ACEPTE NUMEROS
	       validacion->validarOpc(opc);
	        switch(opc) {
	        case 1:
	        	cout << "\n -- ALUMNO --\n1-Registrar \n2-Eliminar \n3-Actualizar \n4-Consultar " << endl;
	        	cin>>actOpc;
	        	if(actOpc == 1) {
	        		conexion->wConsultarAlumno();
	        		conexion->wInsertarAlumno();
	        		} else if(actOpc == 2) {
	        		    cout << "\nEliminar un  de Alumno " << endl;
	        		    cout << "\n-Tabla actual- " << endl;
	        		    conexion->wConsultarAlumno();
	        		    conexion->wBorrarAlumno();
	        		} else if(actOpc == 3) {
	        		    cout << "\nActualizar informacion de un alumno " << endl;
	        		    cout << "\n-Tabla actual- " << endl;
	        		    conexion->wConsultarAlumno();
	        		    conexion->wActualizarAlumno();
	        		} else if(actOpc == 4) {
	        			conexion->wConsultarAlumno();
	        		} else { cout << "\n-Opcion Invalida- \n" << endl; mostrarMenu();}
	            break;
	        case 2:
	        	cout << "\n -- PROFESOR --\n1-Registrar \n2-Eliminar \n3-Actualizar \n4-Consultar " << endl;
	        	cin>>actOpc;
	        	if(actOpc == 1) {
	        		conexion->wConsultarProfesor();
	        		conexion->wInsertarProfesor();
	        	} else if(actOpc == 2) {
	        	    cout << "\nEliminar a un Profesor " << endl;
	        	    cout << "\n-Tabla actual- " << endl;
	        	    conexion->wConsultarProfesor();
	        	    conexion->wBorrarProfesor();
	        	} else if(actOpc == 3) {
	        	    cout << "\nActualizar informacion de un profesor " << endl;
	        	    cout << "\n-Tabla actual- " << endl;
	        	    conexion->wConsultarProfesor();
	        	    conexion->wActualizarProfesor();
	        	} else if(actOpc == 4) {
	        		conexion->wConsultarProfesor();
	        	} else { cout << "\n-Opcion Invalida- \n" << endl; mostrarMenu();}
	            break;
	        case 3:
	        	cout << "\n -- MATERIA --\n1-Registrar \n2-Eliminar \n3-Actualizar \n4-Consultar " << endl;
	        	cin>>actOpc;
	        	if(actOpc == 1) {
	        		conexion->wConsultarMateria();
	        		conexion->wInsertarMateria();
	        	} else if(actOpc == 2) {
	        	    cout << "\nEliminar una Materia" << endl;
	        	    cout << "\n-Tabla actual- " << endl;
	        	    conexion->wConsultarMateria();
	        	    conexion->wBorrarMateria();
	        	} else if(actOpc == 3) {
	        	    cout << "\nActualizar informacion de un profesor " << endl;
	        	    cout << "\n-Tabla actual- " << endl;
	        	    conexion->wConsultarMateria();
	        	    conexion->wActualizarMateria();
	        	} else if(actOpc == 4) {
	        		conexion->wConsultarMateria();
	        	} else { cout << "\n-Opcion Invalida- \n" << endl; mostrarMenu();}
	            break;
	        case 4:
	            cout << "\n -- Curso --\n1-Consultar \n2-Eliminar" << endl;
	        	cin>>actOpc;
	            if(actOpc == 1) {
	            	cout << "\n--- Cursos ---" << endl;
	            	conexion->wConsultarCurso();
	            } else if(actOpc == 2) {
	            	cout << "\nEliminar un Curso " << endl;
	            	 cout << "\n-Tabla actual- " << endl;
	            	 conexion->wConsultarCurso();
	            	 conexion->wBorrarCurso();
	            } else { cout << "\n-Opcion Invalida- \n" << endl; mostrarMenu();}
	            break;
	        case 5:
	        	cout << "\n--- ALUMNOS---" << endl;
	        	conexion->wConsultarAlumno();
	        	cout << "\n--- MATERIAS---" << endl;
	        	conexion->wConsultarMateria();
	        	cout << "\n--- PROFESORES---" << endl;
	        	conexion->wConsultarProfesor();
	        	conexion->wCrearCurso();
	        break;
	        case 6:
	        	conexion->wConsultarCurso();
	        	conexion->wAsingarCalificacion();
	        	//cout << "\nCalificacion asignada exitosamente\n" << endl;
	        	conexion->wConsultarCurso();
	        break;
	        default:
	        cout<<"Se ha cerrado el programa."<<endl;
	        break;
	        }
	     } while(opc <= 6);
	  delete conexion;
	  delete validacion;
}
