#include "AviaoReconhecimento.h"
#include "Aviao.h"

AviaoReconhecimento::AviaoReconhecimento(const string &nomeDoAviao,int velocidadeMaxima ,int capacidadeTanque, int empuxoDoMotor, int alcance)
:Aviao(nomeDoAviao,velocidadeMaxima,capacidadeTanque,empuxoDoMotor)
{
	this->alcanceDoRadar = alcance;
}

AviaoReconhecimento::~AviaoReconhecimento()
{
}

AviaoReconhecimento::AviaoReconhecimento(const AviaoReconhecimento&origem)
:Aviao(origem)
{
		this->setNomeDaAeronave(origem.getNomeDaAeronave());
		this->setVelocidadeMaxima(origem.getVelocidadeMaxima());
		this->setCapacidadeTanque(origem.getCapacidadeTanque());
		this->setEmpuxoDoMotor(origem.getEmpuxoDoMotor());
		this->alcanceDoRadar = origem.alcanceDoRadar;
}

int AviaoReconhecimento::getAlcanceDoRadar() const
{
	return this->alcanceDoRadar;
}

//---------------- SOBRECARGA DE OPERADORES -----------------
	
ostream& operator << (ostream &output, const AviaoReconhecimento &origem)
{
	output << static_cast< Aviao >(origem);
	output << "Alcance do Radar do Aviao eh: " << origem.getAlcanceDoRadar() << "\n";
	
	return output;
}

const AviaoReconhecimento &AviaoReconhecimento::operator= (const AviaoReconhecimento &origem)
{
	if(this != &origem)
	{	
		this->setNomeDaAeronave(origem.getNomeDaAeronave());
		this->setVelocidadeMaxima(origem.getVelocidadeMaxima());
		this->setCapacidadeTanque(origem.getCapacidadeTanque());
		this->setEmpuxoDoMotor(origem.getEmpuxoDoMotor());
		this->alcanceDoRadar = origem.alcanceDoRadar;
	}
	return *this;
}

bool AviaoReconhecimento::operator == (const AviaoReconhecimento &origem) const
{
	
	if(this != &origem)
	{
		if( static_cast<Aviao>(*this) != static_cast<Aviao>(origem) )
			return false;
		
		if(this->alcanceDoRadar != origem.alcanceDoRadar)
			return false;
		
	}
	return true;
}

bool AviaoReconhecimento::operator != (const AviaoReconhecimento &origem) const
{
	return !(*this == origem);
}
