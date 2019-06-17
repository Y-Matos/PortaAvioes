#ifndef AVIAO_H
#define AVIAO_H
#include "Aeronave.h"

class Aviao : public Aeronave
{
	friend ostream &operator<< (ostream &output, const Aviao&);
public:

	Aviao(const string&, int, int,int);
	~Aviao();
	Aviao(const Aviao &);// Construtor de copia
	
	void setEmpuxoDoMotor(int);
	int getEmpuxoDoMotor() const;
	
//---------------- SOBRECARGA DE OPERADORES -----------------

	const Aviao &operator= (const Aviao&); // copia uma aeronave para outra
	bool operator == (const Aviao&) const; // testa se aeronaves são iguais
	bool operator != (const Aviao&) const; // testa se aeronaves são diferentes
		
private:
	int empuxoDoMotor;
	
};

#endif // AVIAO_H