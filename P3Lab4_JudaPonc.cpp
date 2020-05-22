#include <iostream>
#include "persona.h"
#include<vector>

using namespace std;
string nombre, apellido, password;

vector <persona> personas;
int main(int argc, char** argv) {
	bool exit = true;
		while(exit){
		
	cout<<"                     ***CLI-MESSENGER-SERVICE***   "<<endl;
	cout<<" (1) Registrarse"<<endl;
	cout<<" (2) Ingresar"<<endl;
	cout<<" (0) Salir"<<endl;
	int opcion;
	cin >> opcion;
	switch(opcion) {
			case 1:{
			cout<<" -> Ingrese su nombre: ";
			cin >> nombre;
			cout<<" -> Ingrese su apellido: ";
			cin>> apellido;
			cout<<" -> Ingrese su contrasena: ";
			cin>> password;
			cout<<" Ha sido registrado con exito: "<<endl;
			personas.push_back(persona(nombre,apellido,password));	
			cout<<" Su usuario es: ";
		//	for(int = 0)
				break;
			}
			case 2:{
				
			
				
				break;
			}
			
			
			default:
				exit = false;
				break;
		}
	}

	
	return 0;
}
