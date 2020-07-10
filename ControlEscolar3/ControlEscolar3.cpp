#include "Menu.h"
#include "Alumno.h"
#include "Conexion.h"
/*#include "AlumnoVista.h"
#include "MedioContacto.h"
#include "Estudios.h"
#include "AlumnoBS.h"
#include "AlumnoBD.h"*/
#include <iostream>

using namespace std;

/*
void lista(){
	cout<<"         Menu      "<<endl;
	cout<<"1. Registrar alumno. "<<endl;
	cout<<"2. Registrar maestro. "<<endl;
	cout<<"3. Registrar materias. "<<endl;
	cout<<"4. Administrar grupos. "<<endl;
	cout<<"5. Asignar materias a profesor. "<<endl;
	cout<<"6. Inscribir alumno a un curso. "<<endl;
	cout<<"7. Salir."<<endl<<endl;

	cout<<"Ingrese un numero para acceder a una opcion del menu."<<endl;
}*/

int main(int argc, char **argv) {
int opc,actOpc;
Conexion *prueba;
prueba=new Conexion();
//string nombre,apellido1,apellido2,curp,boleta,tipo,valor,ultimo,certificado;
	//string primerapellido,segundoapellido,dia,mes,year,ano;
	//string boleta,nombre,primerapellido,segundoapellido,dia,mes,year;
/*Alumno* alumno;
alumno = new Alumno();*/
/*int dia,mes,ano;
				cout<<"Nombre(s):"<<endl;
				cin>>nombre;
				alumno->setNombre(nombre);
				cout<<"Apellido paterno:"<<endl;
				cin>>apellido1;
				alumno->setPrimerApellido(apellido1);
				cout<<"Apellido materno:"<<endl;
				cin>>apellido2;
				alumno->setSegundoApellido(apellido2);
				cout<<"Fecha de nacimiento dd mm aaaa:"<<endl;
				cin>>dia>>mes>>ano;
				alumno->setDia(dia);
				alumno->setMes(mes);
				alumno->setYear(ano);
				cout<<"Ingrese CURP:"<<endl;
				cin>>curp;
				alumno->setCurp(curp);
				cout<<"Ingrese boleta de alumno:"<<endl;
				cin>>boleta;
				alumno->setBoleta(boleta);
				cout<<"Nombre:"<<alumno->getBoleta()<<endl;*/
//	alumno->getBoleta(),alumno->getNombre(), alumno->getPrimerApellido(), alumno->getSegundoApellido(),alumno->getDia(),alumno->getMes(),alumno->getYear()
				/*nombre = alumno->getNombre();
				boleta = alumno.getBoleta();
				primerapellido = alumno.getPrimerApellido();
				segundoapellido = alumno.getSegundoApellido();
				dia = alumno.getDia();
				mes = alumno.getMes();
				year = alumno.getYear();*/
				//prueba->wInsertar();
				//prueba->insertar(boleta,nombre, apellido1, apellido2,dia,mes,ano);
				//prueba->insertar(alumno->getBoleta(),alumno->getNombre(), alumno->getPrimerApellido(), alumno->getSegundoApellido(),alumno->getDia(),alumno->getMes(),alumno->getYear());

/*AGREGADO ABAJO
				prueba->wInsertarAlumno();
				prueba->wConsultar();*/


	do{

		//cout<<"\n1- SELECT * FROM alumno \n";
			//cout<<"2- INSERT INTO  alumno \n";/*
			//cout<<"3- UPDATE alumno set nombre \n";
			//cout<<"4- DELETE alumno set nombre \n";
			//cout<<"5- Salir \n";

		cout<<"\n1. Registrar alumno. "<<endl;
		cout<<"2. Registrar maestro. "<<endl;
		cout<<"3. Registrar materias. "<<endl;
		cout<<"4. Administrar grupos. "<<endl;
		cout<<"5. Asignar materias a profesor. "<<endl;
		cout<<"6. Inscribir alumno a un curso. "<<endl;
		cout<<"7. Salir."<<endl<<endl;

		cin>>opc;
		switch(opc){
		case 1:
			//alumno.wRegistraAlumno();
		prueba->wInsertarAlumno();
		prueba->wConsultarAlumno();
		break;
		case 2:
		prueba->wInsertarProfesor();
		prueba->wConsultarProfesor();
		cout<<" "<<endl;
		break;
		case 3:
		prueba->wInsertarMateria();
		prueba->wConsultarMateria();
		cout<<" "<<endl;
		break;
		case 4:
		cout << "\n--Actualizar-- \n1-Alumno\n2-Profesor\n3-Materia\n--Borrar--\n4-Eliminar Alumno " << endl;
		cin>>actOpc;
		if(actOpc == 1){
		cout << "\nActualizar informacion de un alumno " << endl;
		cout << "\n-Tabla actual- " << endl;
		prueba->wConsultarAlumno();
		prueba->wActualizarAlumno();
		cout << "\n-Tabla actualizada- " << endl;
		prueba->wConsultarAlumno();
		cout<<" "<<endl;
		}else if(actOpc == 2){
			cout << "\nActualizar informacion de un profesor " << endl;
					cout << "\n-Tabla actual- " << endl;
					prueba->wConsultarProfesor();
					prueba->wActualizarProfesor();
					cout << "\n-Tabla actualizada- " << endl;
					prueba->wConsultarProfesor();
					cout<<" "<<endl;
		}else if(actOpc == 3){
			cout << "\nActualizar informacion de un materia " << endl;
					cout << "\n-Tabla actual- " << endl;
					prueba->wConsultarMateria();
					prueba->wActualizarMateria();
					cout << "\n-Tabla actualizada- " << endl;
					prueba->wConsultarMateria();
					cout<<" "<<endl;
		}else if(actOpc == 4){
			cout << "\nEliminar una fila de Alumno " << endl;
					cout << "\n-Tabla actual- " << endl;
					prueba->wConsultarAlumno();
					prueba->wBorrarAlumno();
					cout << "\n-Tabla actualizada- " << endl;
					prueba->wConsultarAlumno();
					cout<<" "<<endl;
		}
		else {
		    // print error message
		}
		break;
		case 5:
			cout<<"aaa"<<endl;
		break;
		case 6:
			cout<<"aaa"<<endl;
		break;
		case 7:
			//system("cls");
		cout<<"Se ha cerrado el programa."<<endl;
		break;
		}

	}while(opc != 7);
return 0;
}
