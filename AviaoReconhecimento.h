#ifndef AVIAORECONHECIMENTO_H
#define AVIAORECONHECIMENTO_H
#include "Aviao.h"

class AviaoReconhecimento : public Aviao
{
	friend ostream &operator<< (ostream &output, const AviaoReconhecimento&);
public:
	AviaoReconhecimento(const string&, int, int, int, int);
	~AviaoReconhecimento();
	AviaoReconhecimento(const AviaoReconhecimento &);// Construtor de copia
	
	int getAlcanceDoRadar() const;
	
	//---------------- SOBRECARGA DE OPERADORES -----------------

	const AviaoReconhecimento &operator= (const AviaoReconhecimento&); // copia uma aeronave para outra
	bool operator == (const AviaoReconhecimento&) const; // testa se aeronaves são iguais
	bool operator != (const AviaoReconhecimento&) const; // testa se aeronaves são diferentes
		
private:
	int alcanceDoRadar;
};

#endif // AVIAORECONHECIMENTO_H
