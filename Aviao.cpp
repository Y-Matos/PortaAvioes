#include "Aviao.h"
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Aviao::Aviao()
: nomeDoAviao("NomeTeste"), velocidadeMaxima(500),capacidadeTanque(200)
{
    nomeDoAviao="NomeTeste";
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
    cout << "A velocidade maxima do aviao eh: " << velocidadeMaxima << endl;
}

void Aviao::getCapacidadeTanque() const
{
    cout << "A capacidade do tanque do aviao eh: " << capacidadeTanque << endl;
}

void Aviao::info() const
{
    getNomeDoAviao();
    getVelocidadeMaxima();
    getCapacidadeTanque();
    
}
