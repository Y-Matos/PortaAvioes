#include "Aviao.h"

#include <iostream>
using std::cout;

Aviao::Aviao(const string &nomeDoAviao,int velocidadeMaxima ,int capacidadeTanque, int empuxoDoMotor)
:Aeronave(nomeDoAviao,velocidadeMaxima,capacidadeTanque)
{
	setEmpuxoDoMotor(empuxoDoMotor);
}

Aviao::~Aviao()
{
	
}

Aviao::Aviao(const Aviao&origem)
{
		this->setNomeDaAeronave(origem.getNomeDaAeronave());
		this->setVelocidadeMaxima(origem.getVelocidadeMaxima());
		this->setCapacidadeTanque(origem.getCapacidadeTanque());
		this->empuxoDoMotor = origem.empuxoDoMotor;
}






int Aviao::getEmpuxoDoMotor() const
{
	return this->empuxoDoMotor;
}

void Aviao::setEmpuxoDoMotor(int empuxoDoMotor)
{
	if(empuxoDoMotor > 0 ){
		this->empuxoDoMotor = empuxoDoMotor; 
	}else {
		this->empuxoDoMotor = 1000;
	}
}

//---------------- SOBRECARGA DE OPERADORES -----------------
	
ostream& operator << (ostream &output, const Aviao &origem)
{
	output << static_cast< Aeronave >(origem);
	output << "A forca de empuxo do aviao eh: " << origem.getEmpuxoDoMotor() << " lbs" << "\n";
	
	return output;
}

const Aviao &Aviao::operator= (const Aviao &origem)
{
	if(this != &origem)
	{
		this->setNomeDaAeronave(origem.getNomeDaAeronave());
		this->setVelocidadeMaxima(origem.getVelocidadeMaxima());
		this->setCapacidadeTanque(origem.getCapacidadeTanque());
		this->empuxoDoMotor = origem.empuxoDoMotor;
	}
	return *this;
}

bool Aviao::operator == (const Aviao &origem) const
{
	
	if(this != &origem)
	{
		if( static_cast<Aeronave>(*this) != static_cast<Aeronave>(origem) )
			return false;
		
		if(this->empuxoDoMotor != origem.empuxoDoMotor)
			return false;
		
	}
	return true;
}

bool Aviao::operator != (const Aviao &origem) const
{
	return !(*this == origem);
}
