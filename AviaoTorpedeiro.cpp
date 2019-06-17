#include "AviaoTorpedeiro.h"

AviaoTorpedeiro::AviaoTorpedeiro(const string &nomeDoAviao,int velocidadeMaxima ,int capacidadeTanque, int empuxoDoMotor, int numDeTorpedos)
:Aviao(nomeDoAviao,velocidadeMaxima,capacidadeTanque,empuxoDoMotor)
{
	this->numeroDeTorpedos = numDeTorpedos;
}

AviaoTorpedeiro::~AviaoTorpedeiro()
{
}

AviaoTorpedeiro::AviaoTorpedeiro(const AviaoTorpedeiro&origem)
:Aviao(origem)
{
		this->setNomeDaAeronave(origem.getNomeDaAeronave());
		this->setVelocidadeMaxima(origem.getVelocidadeMaxima());
		this->setCapacidadeTanque(origem.getCapacidadeTanque());
		this->setEmpuxoDoMotor(origem.getEmpuxoDoMotor());
		this->numeroDeTorpedos = origem.numeroDeTorpedos;
}


int AviaoTorpedeiro::getNumeroDeTorpedos() const
{
	return this->numeroDeTorpedos;
}

//---------------- SOBRECARGA DE OPERADORES -----------------
	
ostream& operator << (ostream &output, const AviaoTorpedeiro &origem)
{
	output << static_cast< Aviao >(origem);
	output << "Numero de Torpedos do aviao eh: " << origem.getNumeroDeTorpedos() << "\n";
	
	return output;
}

const AviaoTorpedeiro &AviaoTorpedeiro::operator= (const AviaoTorpedeiro &origem)
{
	if(this != &origem)
	{	
		this->setNomeDaAeronave(origem.getNomeDaAeronave());
		this->setVelocidadeMaxima(origem.getVelocidadeMaxima());
		this->setCapacidadeTanque(origem.getCapacidadeTanque());
		this->setEmpuxoDoMotor(origem.getEmpuxoDoMotor());
		this->numeroDeTorpedos = origem.numeroDeTorpedos;
	}
	return *this;
}

bool AviaoTorpedeiro::operator == (const AviaoTorpedeiro &origem) const
{
	
	if(this != &origem)
	{
		if( static_cast<Aviao>(*this) != static_cast<Aviao>(origem) )
			return false;
		
		if(this->numeroDeTorpedos != origem.numeroDeTorpedos)
			return false;
		
	}
	return true;
}

bool AviaoTorpedeiro::operator != (const AviaoTorpedeiro &origem) const
{
	return !(*this == origem);
}
