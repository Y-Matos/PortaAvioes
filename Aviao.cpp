#include "Aviao.h"

#include <iostream>
using std::cout;

//----Construtores e Destrutores------------------------------------------------------------------------------------------------------------------------------------------------------------------

Aviao::Aviao(const string &nomeDoAviao,int velocidadeMaxima ,int capacidadeTanque)
{
    this->nomeDoAviao = setNomeDoAviao(nomeDoAviao);
	this->velocidadeMaxima = setVelocidadeMaxima(velocidadeMaxima);
	this->capacidadeTanque = setCapacidadeTanque(capacidadeTanque);
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

string Aviao::setNomeDoAviao(const string &nomeDoAviao)
{
	if(nomeDoAviao.length() <= 40)	{
	
		return nomeDoAviao;
	
	}
	else if(nomeDoAviao.length() > 40){
		return nomeDoAviao.substr(0,40);

		cout << "Numero de caracteres excedeu o limite, primeiros 40 caracteres utilizados" << "\n";
	}
	return "";
}

int Aviao::setVelocidadeMaxima(int velocidadeMaxima)
{
	if(velocidadeMaxima > 0 && velocidadeMaxima <= ( VELOCIDADEDOSOM*6.7 ) ){ // Mach 6.7 é a velocidade do Jato mais Rapido
		return velocidadeMaxima; 
	}else {
		return VELOCIDADEDOSOM;
	}
}

int Aviao::setCapacidadeTanque(int capacidadeTanque)
{
	if(capacidadeTanque > 0 ){
		return capacidadeTanque; 
	}else {
		return 1000;
	}
}

//-------Funcoes Get-----------------------------------------------------------------------------------------------------------------------------------------------------------------

void Aviao::getNomeDoAviao() const
{
    cout << "O nome do aviao eh: " << this->nomeDoAviao << "\n";
}

void Aviao::getVelocidadeMaxima() const
{
    cout << "A velocidade maxima do aviao eh: " << this->velocidadeMaxima << "km/h" << "\n";
}

void Aviao::getCapacidadeTanque() const
{
    cout << "A capacidade do tanque do aviao eh: " << this->capacidadeTanque << "L" << "\n";
}

void Aviao::info(int index) const
{
	cout << "--------------------------------------------------" << "\n";
    cout << "-------------- INFO DO AVIAO #" << index+1 << " -----------------\n" << "\n";
	getNomeDoAviao();
    getVelocidadeMaxima();
    getCapacidadeTanque();
    
}
