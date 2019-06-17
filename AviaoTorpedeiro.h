#ifndef AVIAOTORPEDEIRO_H
#define AVIAOTORPEDEIRO_H
#include "Aviao.h"

class AviaoTorpedeiro : public Aviao
{
	friend ostream &operator<< (ostream &output, const AviaoTorpedeiro&);
public:
	AviaoTorpedeiro(const string&, int, int,int,int);
	~AviaoTorpedeiro();
	AviaoTorpedeiro(const AviaoTorpedeiro &);// Construtor de copia
		
	int getNumeroDeTorpedos() const;
	
	//---------------- SOBRECARGA DE OPERADORES -----------------

	const AviaoTorpedeiro &operator= (const AviaoTorpedeiro&); // copia uma aeronave para outra
	bool operator == (const AviaoTorpedeiro&) const; // testa se aeronaves são iguais
	bool operator != (const AviaoTorpedeiro&) const; // testa se aeronaves são diferentes
private:
	int numeroDeTorpedos;
};

#endif // AVIAOTORPEDEIRO_H
