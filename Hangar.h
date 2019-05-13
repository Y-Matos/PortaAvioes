#ifndef HANGAR_H
#define HANGAR_H
#include <string>
using std::string;

class Hangar
{
public:
	Hangar(const string &,const string &,const string &,const string &,const string &); // INICIALIZA COM TODOS OS TIPOS
	Hangar(); // INICIALIZA COM _VAZIO_ EM TODOS OS TIPOS
	Hangar(const Hangar &); // CONSTRUTOR DE COPIA
	~Hangar();
	
	void getTiposDeAviao() const;
	void setTipoDeAviao(const string &);

	void info() const;
	
private:
	int tiposAtivos; 
	
	static const int NUMDETIPOS = 5;
	string tiposNome[NUMDETIPOS];
	
};

#endif // HANGAR_H
