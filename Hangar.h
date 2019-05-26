#ifndef HANGAR_H
#define HANGAR_H
#include <string>
using std::string;

using std::ostream;

class Hangar
{
public:
	Hangar(const string &,const string &,const string &,const string &,const string &); // INICIALIZA COM TODOS OS TIPOS
	Hangar(); // INICIALIZA COM _VAZIO_ EM TODOS OS TIPOS
	Hangar(const Hangar &); // CONSTRUTOR DE COPIA
	~Hangar();
	
	string getTiposDeAviao(int) const;
	void setTipoDeAviao(const string &);

	void info() const;
	
	
	//---------------- SOBRECARGA DE OPERADORES -----------------
	
	friend ostream &operator << (ostream &output, const Hangar&); // Imprime Dados do Hangar
	const Hangar &operator = (const Hangar&); // copia um avião para outro
	bool operator == (const Hangar&) const; // testa se hangar são iguais
	bool operator != (const Hangar&) const; // testa se hangar são diferentes
	string &operator[] (int); 
	string operator[] (int) const;

private:
	int tiposAtivos; 
	
	static const int NUMDETIPOS = 5;
	string tiposNome[NUMDETIPOS];
	
};

#endif // HANGAR_H
