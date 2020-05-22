#ifndef PERSONA_H
#define PERSONA_H
#include<vector>
#include<string>
using namespace std;

class persona
{
	public:
		persona();
		persona(string,string ,string );
		string getNombre();
		string getApellido();
		string getPassword();
		int getKey();
		vector<string>& getMensajes();
		string cifradoAdelante (string,int);
		string cifradoAtras (string,int);
		
		~persona();
	private:
		string nombre;
		string apellido;
		string password;
		int llave;
		vector<string> mensajes;
		
};

#endif
