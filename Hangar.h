#ifndef HANGAR_H
#define HANGAR_H
#include <string>
using std::string;

class Hangar
{
public:
	Hangar(const int);
	//Hangar();
	//Hangar();
	~Hangar();
	
	void getTiposDeAviao() const;
	void cadastraTipoDeAviao(const string &, const int);
	void adicionaTipoDeAviao(const string &);
	
    void info() const;
    
private:
	
	int numDeTipos;	
	string *tiposNome;
	
};

#endif // HANGAR_H
