#include "Helicoptero.h"

Helicoptero::Helicoptero(const string &nomeDoHelicoptero,int velocidadeMaxima ,int capacidadeTanque, int rpmDoRotor)
:Aeronave(nomeDoHelicoptero,velocidadeMaxima,capacidadeTanque)
{
	this->rpmDoRotor = rpmDoRotor;
}

Helicoptero::~Helicoptero()
{
}

Helicoptero::Helicoptero(const Helicoptero&origem)
{
		this->setNomeDaAeronave(origem.getNomeDaAeronave());
		this->setVelocidadeMaxima(origem.getVelocidadeMaxima());
		this->setCapacidadeTanque(origem.getCapacidadeTanque());
		this->rpmDoRotor = origem.rpmDoRotor;
}


int Helicoptero::getRpmDoRotor() const
{
	return this->rpmDoRotor;
}

void Helicoptero::setRpmDoRotor(int rpmDoRotor)
{
	if(rpmDoRotor > 0 ){
		this->rpmDoRotor = rpmDoRotor; 
	}else {
		this->rpmDoRotor = 1000;
	}
}

//---------------- SOBRECARGA DE OPERADORES -----------------
	
ostream& operator << (ostream &output, const Helicoptero &origem)
{
	output << static_cast< Aeronave >(origem);
	output << "O Rotor do Helicoptero faz: " << origem.getRpmDoRotor() << " RPM" << "\n";
	
	return output;
}

const Helicoptero &Helicoptero::operator= (const Helicoptero &origem)
{
	if(this != &origem)
	{
		this->setNomeDaAeronave(origem.getNomeDaAeronave());
		this->setVelocidadeMaxima(origem.getVelocidadeMaxima());
		this->setCapacidadeTanque(origem.getCapacidadeTanque());
		this->rpmDoRotor = origem.rpmDoRotor;
	}
	return *this;
}

bool Helicoptero::operator == (const Helicoptero &origem) const
{
	
	if(this != &origem)
	{
		if( static_cast<Aeronave>(*this) != static_cast<Aeronave>(origem) )
			return false;
		
		if(this->rpmDoRotor != origem.rpmDoRotor)
			return false;
		
	}
	return true;
}

bool Helicoptero::operator != (const Helicoptero &origem) const
{
	return !(*this == origem);
}
