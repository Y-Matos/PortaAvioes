#ifndef BALAO_H
#define BALAO_H
#include "Aeronave.h"

class Balao : public Aeronave
{
	friend ostream &operator<< (ostream &output, const Balao&);
public:
	Balao(const string&, int, int,int);
	~Balao();
	Balao(const Balao &);// Construtor de copia
	
	void setAlturaMaxima(int);
	int getAlturaMaxima() const;
		
	//---------------- SOBRECARGA DE OPERADORES -----------------

	const Balao &operator= (const Balao&); // copia uma aeronave para outra
	bool operator == (const Balao&) const; // testa se aeronaves são iguais
	bool operator != (const Balao&) const; // testa se aeronaves são diferentes
	
private:
	int alturaMaxima;
};

#endif // BALAO_H
