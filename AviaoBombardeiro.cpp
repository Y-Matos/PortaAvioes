#include "AviaoBombardeiro.h"

AviaoBombardeiro::AviaoBombardeiro(const string &nomeDoAviao,int velocidadeMaxima ,int capacidadeTanque, int empuxoDoMotor, int numDeBombas)
:Aviao(nomeDoAviao,velocidadeMaxima,capacidadeTanque,empuxoDoMotor)
{
	this->numeroDeBombas = numDeBombas;
}

AviaoBombardeiro::~AviaoBombardeiro()
{
}

AviaoBombardeiro::AviaoBombardeiro(const AviaoBombardeiro&origem)
:Aviao(origem)
{
		this->setNomeDaAeronave(origem.getNomeDaAeronave());
		this->setVelocidadeMaxima(origem.getVelocidadeMaxima());
		this->setCapacidadeTanque(origem.getCapacidadeTanque());
		this->setEmpuxoDoMotor(origem.getEmpuxoDoMotor());
		this->numeroDeBombas = origem.numeroDeBombas;
}


int AviaoBombardeiro::getNumeroDeBombas() const
{
	return this->numeroDeBombas;
}

//---------------- SOBRECARGA DE OPERADORES -----------------
	
ostream& operator << (ostream &output, const AviaoBombardeiro &origem)
{
	output << static_cast< Aviao >(origem);
	output << "Numero de Bombas do aviao eh: " << origem.getNumeroDeBombas() << "\n";
	
	return output;
}

const AviaoBombardeiro &AviaoBombardeiro::operator= (const AviaoBombardeiro &origem)
{
	if(this != &origem)
	{	
		this->setNomeDaAeronave(origem.getNomeDaAeronave());
		this->setVelocidadeMaxima(origem.getVelocidadeMaxima());
		this->setCapacidadeTanque(origem.getCapacidadeTanque());
		this->setEmpuxoDoMotor(origem.getEmpuxoDoMotor());
		this->numeroDeBombas = origem.numeroDeBombas;
	}
	return *this;
}

bool AviaoBombardeiro::operator == (const AviaoBombardeiro &origem) const
{
	
	if(this != &origem)
	{
		if( static_cast<Aviao>(*this) != static_cast<Aviao>(origem) )
			return false;
		
		if(this->numeroDeBombas != origem.numeroDeBombas)
			return false;
		
	}
	return true;
}

bool AviaoBombardeiro::operator != (const AviaoBombardeiro &origem) const
{
	return !(*this == origem);
}
