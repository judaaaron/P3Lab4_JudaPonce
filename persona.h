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
		~persona();
	private:
		string nombre;
		string apellido;
		string password;
		int llave;
		vector<string> *mensajes;
		
};

#endif
