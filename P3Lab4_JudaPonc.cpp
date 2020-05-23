#include <iostream>
#include "persona.cpp"
#include<vector>

using namespace std;
string nombre, apellido, password;
int personaIngresada;

vector <persona> personas;
string cifradoAdelante (string,int);
string cifradoAtras (string, int);
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
					string mensaje;
					switch(option){
						case 1:{
							int destinoMensaje;
							cout<<" Usuarios: "<<endl;
								for (int i = 0; i < personas.size(); i++){
									cout << ". " << personas[i].getNombre() << endl;
								}
							
							int destinatario;
							string newmensaje;
							cout << "Seleccione destinatario: "; 
							cout<<"-NOTA: la lista empieza en 0"<<endl;
							cin >> destinatario;
							cout<<"-NOTA: No ingrese espacios, en lugar de ello, coloque un '_'."<<endl;
							cout << endl;
							string mensaje;
							cout << "Escribe el mensaje: "; 
							cin >> mensaje;
						if(personas[destinatario].getKey() !=0){
							
							for (int random = personas[destinatario].getKey(); random > 0 ; random--){
								string *separarPalabra = NULL;
								separarPalabra = new string [mensaje.size()/random+1];	
								int letras = 0;	
								for (int i = 0; i < mensaje.size()/random+1; i++){
									
									for (int j = 0; j < random; j++){
											separarPalabra[i] += mensaje[letras];
											letras ++; 
									}
								}		
								for (int i = 0; i < mensaje.size()/random+1; i++){
									if (i % 2 == 0){
											separarPalabra[i] = cifradoAdelante(separarPalabra[i],random);
										} else {
											separarPalabra[i] = cifradoAtras(separarPalabra[i],random);
										}
									}
									newmensaje = "";
									for (int i = 0;i < mensaje.size()/random+1; i++){
										for (int j = 0; j < random; j++){
												newmensaje += separarPalabra[i][j];
										}
									}
									mensaje = newmensaje;
											
							}
							personas[destinatario].getMensajes().push_back((char)personaIngresada + mensaje);
							cout<<"***Mensaje enviado exitosamente***"<<endl;
								
						}
					
							
							break;
						}
						
						case 2: {
								if (personas[personaIngresada].getMensajes().size() == 0){
									cout << "Tu lista de mensajes esta vacia." << endl;
								} else {
									cout << "***Ver mensajes***:" << endl;
									for (int i = 0; i < personas[personaIngresada].getMensajes().size(); i++){				
										personas[personaIngresada].getMensajes()[i];
										cout <<  personas[personaIngresada].getMensajes()[i] << endl; 			
									}
								}
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



string cifradoAdelante (string word, int key){
	string newCadena = "";
	for (int i = 0; i < word.size(); i++){
		char ascii = word[i];
		ascii += key;
		newCadena += ascii;
	}
	
	return newCadena;
}

string cifradoAtras (string word, int key){
	string newCadena = "";
	for (int i = 0; i < word.size(); i++){
		char ascii = word[i];
		ascii -= key;
		newCadena += ascii;
	}
	
	return newCadena;
}

