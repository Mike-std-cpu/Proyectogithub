/*#include "Alumno.h"
 * #include "AlumnoBS.h"
#include "AlumnoBD.h"*/
#include "Conexion.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int opc,actOpc;
    Conexion *prueba;
    prueba=new Conexion();
    do {
        cout<<"\n1. Registrar alumno. "<<endl;
        cout<<"2. Registrar profesor. "<<endl;
        cout<<"3. Registrar materias. "<<endl;
        cout<<"4. Administrar grupos. "<<endl;
        cout<<"5. Asignar materias a profesor y inscribir alumno a un curso. "<<endl;
        cout<<"6.*Inscribir alumno a un curso. "<<endl;
        cout<<"7. Ingresar calificaciones. "<<endl;
        cout<<"8. Salir."<<endl<<endl;
        cin>>opc;
        switch(opc) {
        case 1:
        	//cout << "\n -- ALUMNO --\n1-Registrar un Alumno \n2-Eliminar un Alumno \n3-Actualizar un alumno \n4-Consultar Alumno " << endl;
        	cout << "\n -- ALUMNO --\n1-Registrar \n2-Eliminar \n3-Actualizar \n4-Consultar " << endl;
        	cin>>actOpc;
        	if(actOpc == 1) {
        		prueba->wInsertarAlumno();
        		prueba->wConsultarAlumno();
        		} else if(actOpc == 2) {
        		    cout << "\nEliminar una fila de Alumno " << endl;
        		    cout << "\n-Tabla actual- " << endl;
        		    prueba->wConsultarAlumno();
        		    prueba->wBorrarAlumno();
        		    cout << "\n-Tabla actualizada- " << endl;
        		    prueba->wConsultarAlumno();
        		} else if(actOpc == 3) {
        		    cout << "\nActualizar informacion de un alumno " << endl;
        		    cout << "\n-Tabla actual- " << endl;
        		    prueba->wConsultarAlumno();
        		    prueba->wActualizarAlumno();
        		    cout << "\n-Tabla actualizada- " << endl;
        		    prueba->wConsultarAlumno();
        		} else if(actOpc == 4) {
        		    prueba->wConsultarAlumno();
        		} else { cout << "\n-Opcion Invalida- \n" << endl; }
            break;
        case 2:
        	cout << "\n -- PROFESOR --\n1-Registrar \n2-Eliminar \n3-Actualizar \n4-Consultar " << endl;
        	cin>>actOpc;
        	if(actOpc == 1) {
        	    prueba->wInsertarProfesor();
        	    prueba->wConsultarProfesor();
        	} else if(actOpc == 2) {
        	    cout << "\nEliminar una fila de Alumno " << endl;
        	    cout << "\n-Tabla actual- " << endl;
        	    prueba->wConsultarProfesor();
        	    prueba->wBorrarProfesor();
        	    cout << "\n-Tabla actualizada- " << endl;
        	    prueba->wConsultarProfesor();
        	} else if(actOpc == 3) {
        	    cout << "\nActualizar informacion de un profesor " << endl;
        	    cout << "\n-Tabla actual- " << endl;
        	    prueba->wConsultarProfesor();
        	    prueba->wActualizarProfesor();
        	    cout << "\n-Tabla actualizada- " << endl;
        	    prueba->wConsultarProfesor();
        	} else if(actOpc == 4) {
        	    prueba->wConsultarProfesor();
        	} else { cout << "\n-Opcion Invalida- \n" << endl; }
            break;
        case 3:
        	cout << "\n -- MATERIA --\n1-Registrar \n2-Eliminar \n3-Actualizar \n4-Consultar " << endl;
        	cin>>actOpc;
        	if(actOpc == 1) {
        	    prueba->wInsertarMateria();
        	    prueba->wConsultarMateria();
        	} else if(actOpc == 2) {
        	    cout << "\nEliminar una fila de Alumno " << endl;
        	    cout << "\n-Tabla actual- " << endl;
        	    prueba->wConsultarMateria();
        	    prueba->wBorrarMateria();
        	    cout << "\n-Tabla actualizada- " << endl;
        	    prueba->wConsultarMateria();
        	} else if(actOpc == 3) {
        	    cout << "\nActualizar informacion de un profesor " << endl;
        	    cout << "\n-Tabla actual- " << endl;
        	    prueba->wConsultarMateria();
        	    prueba->wActualizarMateria();
        	    cout << "\n-Tabla actualizada- " << endl;
        	    prueba->wConsultarMateria();
        	} else if(actOpc == 4) {
        	    prueba->wConsultarMateria();
        	} else { cout << "\n-Opcion Invalida- \n" << endl; }
            break;
        case 4:
            //cout << "\n--Actualizar-- \n1-Alumno\n2-Profesor\n3-Materia\n--Borrar--\n4-Eliminar Alumno \n5-Eliminar Profesor\n6-Eliminar Materia\n--Consultas--\n7-Consultar Alumno\n8-Consultar Profesor\n9-Consultar Materia\n10-Consultar Cursos\n11-Eliminar Cursos" << endl;
        	cout << "\n -- Curso --\n1-Consultar \n2-Eliminar" << endl;
        	cin>>actOpc;
            if(actOpc == 1) {
            	cout << "\n--- Cursos ---" << endl;
            	prueba->wConsultarCurso();
            } else if(actOpc == 2) {
            	cout << "\nEliminar un Curso " << endl;
            	 cout << "\n-Tabla actual- " << endl;
            	 prueba->wConsultarCurso();
            	 prueba->wBorrarCurso();
            	 cout << "\n-Tabla actualizada- " << endl;
            	 prueba->wConsultarCurso();
            } else { cout << "\n-Opcion Invalida- \n" << endl; }
            break;
        case 5:
        	cout << "\n--- ALUMNOS---" << endl;
        	prueba->wConsultarAlumno();
        	cout << "\n--- PROFESORES---" << endl;
        	prueba->wConsultarProfesor();
        	cout << "\n--- MATERIAS---" << endl;
        	prueba->wConsultarMateria();
        	prueba->wCrearCurso();
        	cout << "\nCurso creado exitosamente\n" << endl;
        	prueba->wConsultarCurso();
        break;
        case 6:
        	cout<<" "<<endl;
        break;
        case 7:
        	prueba->wConsultarCurso();
        	prueba->wAsingarCalificacion();
        	cout << "\nCalificacion asignada exitosamente\n" << endl;
        	prueba->wConsultarCurso();
        break;
        default:
        cout<<"Se ha cerrado el programa."<<endl;
        break;
        }
    } while(opc != 8);
    return 0;
}
