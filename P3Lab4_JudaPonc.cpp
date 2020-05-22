#include <iostream>
#include "persona.h"
#include<vector>

using namespace std;
string nombre, apellido, password;
int personaIngresada;

vector <persona> personas;
int main(int argc, char** argv) {
	persona* prtpersona=NULL;
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
			cout<<endl;
			personas.push_back(persona(nombre,apellido,password));	
			cout<<" Su usuario es: "<<endl;
			cout << " Nombre: "<<personas[personas.size()-1].getNombre()<<endl;
			cout << " Apellido: "<<personas[personas.size()-1].getApellido()<<endl;
			cout << " Contrasena: "<<personas[personas.size()-1].getPassword()<<endl;
			cout<<endl;
				break;
			}
			case 2:{
				string userName, Password;
				cout<<"****LOG IN****"<<endl;
				cout<<" -> Ingrese su nombre: ";
				cin >> userName;
				cout<<" -> Ingrese su contrasena: ";
				cin>> Password;
				bool acceso=false;
				for(int i=0; i< personas.size(); i++){
					if(personas[i].getNombre() == userName && personas[i].getPassword() == Password){
						acceso=true;
						personaIngresada=i;
						break;
					}else{
						acceso=false;
					}
				}
				
				if(acceso==true){
					int option;
					cout<<"	***Bienvenido: "<< personas[personaIngresada].getNombre()<<"***"<<endl;
					cout<<"(1) Enviar mensaje"<<endl;
					cout<<"(2) Ver mensajes"<<endl;
					cout<<"(3) Ver mi llave"<<endl;
					cout<<"(4) Salir"<<endl;
					cout<<"->Ingrese su opcion: "<<endl;
					cin>>option;
					
					switch(option){
						case 1:{
							
							break;
						}
						
						case 2: {
							
							
							break;
						}
						
						
						case 3:{
							cout<<"-!- Su llave es: ["<<personas[personaIngresada].getKey()<<"]"<<endl;
							break;
						}
						
						case 4:{
							break;
							break;
						}
					}
				}else{
					cout<<" Nombre y/o contraseña incorrectos"<<endl;
					cout<<endl;
				}
				
			
				
				break;
			}
			
			
			default:
				exit = false;
				break;
		}
	}

	
	return 0;
}
