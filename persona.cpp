#include "persona.h"
#include<cstdlib>
#include <ctime>
#include<iomanip>

persona::persona()
{
}

persona::persona(string nombre,string apellido , string password){
	this->nombre=nombre;
	this->apellido=apellido;
	this->password=password;
	this->llave= 1 + rand() % 15;
}
persona::~persona()
{
}
