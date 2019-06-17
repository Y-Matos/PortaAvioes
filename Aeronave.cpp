#include "Aeronave.h"

//----Construtores e Destrutores------------------------------------------------------------------------------------------------------------------------------------------------------------------

Aeronave::Aeronave(const string &nomeDaAeronave,int velocidadeMaxima ,int capacidadeTanque)
{
	setNomeDaAeronave(nomeDaAeronave);
	setVelocidadeMaxima(velocidadeMaxima);
	setCapacidadeTanque(capacidadeTanque);
}

Aeronave::Aeronave()
{
	this->nomeDaAeronave = "Nome Aeronave Padrao";
	this->velocidadeMaxima = VELOCIDADEDOSOM;
	this->capacidadeTanque = 1000;
}

Aeronave::Aeronave(const Aeronave &origem)
{
	this->nomeDaAeronave = origem.nomeDaAeronave;
	this->velocidadeMaxima = origem.velocidadeMaxima;
	this->capacidadeTanque = origem.capacidadeTanque;
}

Aeronave::~Aeronave()
{
}

//-------Funcoes Set---------------------------------------------------------------------------------------------------------------------------------------------------------

void Aeronave::setNomeDaAeronave(const string &nomeDaAeronave)
{
	if(nomeDaAeronave.length() <= 40)	{
	
		this->nomeDaAeronave = nomeDaAeronave;
	
	}
	else if(nomeDaAeronave.length() > 40){
		this->nomeDaAeronave = nomeDaAeronave.substr(0,40);

		cout << "Numero de caracteres excedeu o limite, primeiros 40 caracteres utilizados" << "\n";
	}
}

void Aeronave::setVelocidadeMaxima(int velocidadeMaxima)
{
	if((velocidadeMaxima > 0) && velocidadeMaxima <= ( VELOCIDADEDOSOM*6.7 ) ){ // Mach 6.7 é a velocidade do Jato mais Rapido
		this->velocidadeMaxima = velocidadeMaxima; 
	}else {
		this->velocidadeMaxima = VELOCIDADEDOSOM;
	}
}

void Aeronave::setCapacidadeTanque(int capacidadeTanque)
{
	if(capacidadeTanque > 0 ){
		this->capacidadeTanque = capacidadeTanque; 
	}else {
		this->capacidadeTanque = 1000;
	}
}

//-------Funcoes Get-----------------------------------------------------------------------------------------------------------------------------------------------------------------

string Aeronave::getNomeDaAeronave() const
{
	return this->nomeDaAeronave;
}

int Aeronave::getVelocidadeMaxima() const
{
	return this->velocidadeMaxima;
}

int Aeronave::getCapacidadeTanque() const
{
	return this->capacidadeTanque;
}

void Aeronave::info(int index) const
{
	cout << "--------------------------------------------------" << "\n";
    cout << "-------------- INFO DA AERONAVE #" << index+1 << " -----------------\n" << "\n";
    cout << "O nome da Aeronave eh: " << getNomeDaAeronave() << "\n";
    cout << "A velocidade maxima da Aeronave eh: " << getVelocidadeMaxima() << "km/h" << "\n";
    cout << "A capacidade do tanque da Aeronave eh: " << getCapacidadeTanque() << "L" << "\n";
    
}

	//---------------- SOBRECARGA DE OPERADORES -----------------
	
ostream& operator<< (ostream &output, const Aeronave &origem)
{
	output << "--------------------------------------------------" << "\n";
	output << "-------------- INFO DA AERONAVE ---------------------\n" << "\n";
	output << "O nome da Aeronave eh: " << origem.getNomeDaAeronave() << "\n";
	output << "A velocidade maxima da Aeronave eh: " << origem.getVelocidadeMaxima() << "km/h" << "\n";
	output << "A capacidade do tanque da Aeronave eh: " << origem.getCapacidadeTanque() << "L" << "\n";
	
	return output;
}

const Aeronave &Aeronave::operator= (const Aeronave &origem)
{
	if(this != &origem)
	{
		this->nomeDaAeronave = origem.nomeDaAeronave;
		this->velocidadeMaxima = origem.velocidadeMaxima;
		this->capacidadeTanque = origem.capacidadeTanque;
	}
	return *this;
}

bool Aeronave::operator == (const Aeronave &origem) const
{
	if(this->nomeDaAeronave != origem.nomeDaAeronave)
	{
		return false;
	}
	if(this->velocidadeMaxima != origem.velocidadeMaxima)
	{
		return false;
	}
	if(this->capacidadeTanque != origem.capacidadeTanque)
	{
		return false;
	}
	return true;
}

bool Aeronave::operator != (const Aeronave &origem) const
{
	return !(*this == origem);
}

bool Aeronave::operator < (const Aeronave &origem) const
{
	if(this->velocidadeMaxima < origem.velocidadeMaxima)
	{
		return true;
	}

	return false;
}

bool Aeronave::operator > (const Aeronave &origem) const
{
	if(this->velocidadeMaxima > origem.velocidadeMaxima)
	{
		return true;
	}

	return false;
}