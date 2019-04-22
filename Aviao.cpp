#include "Aviao.h"
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Aviao::Aviao(const string &nomeDoAviao,int velocidadeMaxima ,int capacidadeTanque)
{
    this->nomeDoAviao = nomeDoAviao;
	this->velocidadeMaxima = velocidadeMaxima;
	this->capacidadeTanque = capacidadeTanque;
}

Aviao::~Aviao()
{
}

void Aviao::getNomeDoAviao() const
{
    cout << "O nome do aviao eh: " << nomeDoAviao << endl;
}

void Aviao::getVelocidadeMaxima() const
{
    cout << "A velocidade maxima do aviao eh: " << velocidadeMaxima << "km/h" << endl;
}

void Aviao::getCapacidadeTanque() const
{
    cout << "A capacidade do tanque do aviao eh: " << capacidadeTanque << "L" << endl;
}

void Aviao::info() const
{
	cout << "---------------------------------------" << endl;
    cout << "----------- INFO DO AVIAO -------------\n" << endl;
	getNomeDoAviao();
    getVelocidadeMaxima();
    getCapacidadeTanque();
    
}
