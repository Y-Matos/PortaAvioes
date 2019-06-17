#ifndef HELICOPTERO_H
#define HELICOPTERO_H
#include "Aeronave.h"

class Helicoptero : public Aeronave
{
	friend ostream &operator<< (ostream &output, const Helicoptero&);
public:

	Helicoptero(const string&, int, int, int);
	~Helicoptero();
	Helicoptero(const Helicoptero &);// Construtor de Helicoptero
	
	void setRpmDoRotor(int);
	int getRpmDoRotor() const;
	
	//---------------- SOBRECARGA DE OPERADORES -----------------
	
	const Helicoptero &operator= (const Helicoptero&); // copia uma aeronave para outra
	bool operator == (const Helicoptero&) const; // testa se aeronaves são iguais
	bool operator != (const Helicoptero&) const; // testa se aeronaves são diferentes
	
private:
	int rpmDoRotor;
};

#endif // HELICOPTERO_H
