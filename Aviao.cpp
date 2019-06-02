#include "Aviao.h"

#include <iostream>
using std::cout;

//----Construtores e Destrutores------------------------------------------------------------------------------------------------------------------------------------------------------------------

Aviao::Aviao(const string &nomeDoAviao,int velocidadeMaxima ,int capacidadeTanque)
{
	setNomeDoAviao(nomeDoAviao);
	setVelocidadeMaxima(velocidadeMaxima);
	setCapacidadeTanque(capacidadeTanque);
}

Aviao::Aviao()
{
	cout << "Nenhum parametro informado. Valores Padrões Carregados." << "\n";
	this->nomeDoAviao = "Nome Aviao Padrao";
	this->velocidadeMaxima = VELOCIDADEDOSOM;
	this->capacidadeTanque = 1000;
}

Aviao::Aviao(const Aviao &origem)
{
	this->nomeDoAviao = origem.nomeDoAviao;
	this->velocidadeMaxima = origem.velocidadeMaxima;
	this->capacidadeTanque = origem.capacidadeTanque;
}

Aviao::~Aviao()
{
}

//-------Funcoes Set---------------------------------------------------------------------------------------------------------------------------------------------------------

void Aviao::setNomeDoAviao(const string &nomeDoAviao)
{
	if(nomeDoAviao.length() <= 40)	{
	
		this->nomeDoAviao = nomeDoAviao;
	
	}
	else if(nomeDoAviao.length() > 40){
		this->nomeDoAviao = nomeDoAviao.substr(0,40);

		cout << "Numero de caracteres excedeu o limite, primeiros 40 caracteres utilizados" << "\n";
	}
}

void Aviao::setVelocidadeMaxima(int velocidadeMaxima)
{
	if((velocidadeMaxima > 0) && velocidadeMaxima <= ( VELOCIDADEDOSOM*6.7 ) ){ // Mach 6.7 é a velocidade do Jato mais Rapido
		this->velocidadeMaxima = velocidadeMaxima; 
	}else {
		this->velocidadeMaxima = VELOCIDADEDOSOM;
	}
}

void Aviao::setCapacidadeTanque(int capacidadeTanque)
{
	if(capacidadeTanque > 0 ){
		this->capacidadeTanque = capacidadeTanque; 
	}else {
		this->capacidadeTanque = 1000;
	}
}

//-------Funcoes Get-----------------------------------------------------------------------------------------------------------------------------------------------------------------

string Aviao::getNomeDoAviao() const
{
	return this->nomeDoAviao;
}

int Aviao::getVelocidadeMaxima() const
{
	return this->velocidadeMaxima;
}

int Aviao::getCapacidadeTanque() const
{
	return this->capacidadeTanque;
}

void Aviao::info(int index) const
{
	cout << "--------------------------------------------------" << "\n";
    cout << "-------------- INFO DO AVIAO #" << index+1 << " -----------------\n" << "\n";
    cout << "O nome do aviao eh: " << getNomeDoAviao() << "\n";
    cout << "A velocidade maxima do aviao eh: " << getVelocidadeMaxima() << "km/h" << "\n";
    cout << "A capacidade do tanque do aviao eh: " << getCapacidadeTanque() << "L" << "\n";
    
}

	//---------------- SOBRECARGA DE OPERADORES -----------------
	
ostream& operator << (ostream &output, const Aviao &origem)
{
	output << "--------------------------------------------------" << "\n";
	output << "-------------- INFO DO AVIAO ---------------------\n" << "\n";
	output << "O nome do aviao eh: " << origem.getNomeDoAviao() << "\n";
	output << "A velocidade maxima do aviao eh: " << origem.getVelocidadeMaxima() << "km/h" << "\n";
	output << "A capacidade do tanque do aviao eh: " << origem.getCapacidadeTanque() << "L" << "\n";
	
	return output;
}

const Aviao &Aviao::operator= (const Aviao &origem)
{
	if(this != &origem)
	{
		this->nomeDoAviao = origem.nomeDoAviao;
		this->velocidadeMaxima = origem.velocidadeMaxima;
		this->capacidadeTanque = origem.capacidadeTanque;
	}
	return *this;
}

bool Aviao::operator == (const Aviao &origem) const
{
	if(this->nomeDoAviao != origem.nomeDoAviao)
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

bool Aviao::operator != (const Aviao &origem) const
{
	return !(*this == origem);
}

bool Aviao::operator < (const Aviao &origem) const
{
	if(this->velocidadeMaxima < origem.velocidadeMaxima)
	{
		return true;
	}

	return false;
}

bool Aviao::operator > (const Aviao &origem) const
{
	if(this->velocidadeMaxima > origem.velocidadeMaxima)
	{
		return true;
	}

	return false;
}