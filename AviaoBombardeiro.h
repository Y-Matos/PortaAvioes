#ifndef AVIAOBOMBARDEIRO_H
#define AVIAOBOMBARDEIRO_H
#include "Aviao.h"

class AviaoBombardeiro : public Aviao
{
	friend ostream &operator<< (ostream &output, const AviaoBombardeiro&);
public:
	AviaoBombardeiro(const string&, int, int,int,int);
	~AviaoBombardeiro();
	AviaoBombardeiro(const AviaoBombardeiro &);// Construtor de copia
	
	int getNumeroDeBombas() const;
	
	//---------------- SOBRECARGA DE OPERADORES -----------------

	const AviaoBombardeiro &operator= (const AviaoBombardeiro&); // copia uma aeronave para outra
	bool operator == (const AviaoBombardeiro&) const; // testa se aeronaves são iguais
	bool operator != (const AviaoBombardeiro&) const; // testa se aeronaves são diferentes
		
private:
	int numeroDeBombas;
};

#endif // AVIAOBOMBARDEIRO_H
