#include "Balao.h"

Balao::Balao(const string &nomeDoBalao,int velocidadeMaxima ,int capacidadeTanque,int alturaMaxima)
:Aeronave(nomeDoBalao,velocidadeMaxima,capacidadeTanque)
{
	this->alturaMaxima = alturaMaxima;
}

Balao::~Balao()
{
}

Balao::Balao(const Balao&origem)
{
		this->setNomeDaAeronave(origem.getNomeDaAeronave());
		this->setVelocidadeMaxima(origem.getVelocidadeMaxima());
		this->setCapacidadeTanque(origem.getCapacidadeTanque());
		this->alturaMaxima = origem.alturaMaxima;
}


int Balao::getAlturaMaxima() const
{
	return this->alturaMaxima;
}

void Balao::setAlturaMaxima(int alturaMaxima)
{
	if(alturaMaxima > 0 ){
		this->alturaMaxima = alturaMaxima; 
	}else {
		this->alturaMaxima = 1000;
	}
}

//---------------- SOBRECARGA DE OPERADORES -----------------
	
ostream& operator << (ostream &output, const Balao &origem)
{
	output << static_cast< Aeronave >(origem);
	output << "A Altura Maxima do Balao eh: " << origem.getAlturaMaxima() << " metros" << "\n";
	
	return output;
}

const Balao &Balao::operator= (const Balao &origem)
{
	if(this != &origem)
	{
		this->setNomeDaAeronave(origem.getNomeDaAeronave());
		this->setVelocidadeMaxima(origem.getVelocidadeMaxima());
		this->setCapacidadeTanque(origem.getCapacidadeTanque());
		this->alturaMaxima = origem.alturaMaxima;
	}
	return *this;
}

bool Balao::operator == (const Balao &origem) const
{
	
	if(this != &origem)
	{
		if( static_cast<Aeronave>(*this) != static_cast<Aeronave>(origem) )
			return false;
		
		if(this->alturaMaxima != origem.alturaMaxima)
			return false;
		
	}
	return true;
}

bool Balao::operator != (const Balao &origem) const
{
	return !(*this == origem);
}
