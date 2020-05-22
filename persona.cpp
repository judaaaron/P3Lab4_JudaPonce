#include "persona.h"
#include<cstdlib>
#include <ctime>
#include<iomanip>
#include<string>



persona::persona()
{
	
}

string persona::getNombre(){
	return nombre;
}

string persona::getApellido(){
	return apellido;
}

string persona::getPassword(){
	return password;
}

int persona::getKey(){
	return llave;
}

vector <string>& persona::getMensajes(){
	
	return mensajes;
}
persona::persona(string nombre,string apellido,string password){
	this->nombre=nombre;
	this->apellido=apellido;
	this->password=password;
	this->llave= 1 + rand() % 15;
}


persona::~persona()
{
	
	
	
}
