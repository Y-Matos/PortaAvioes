#include "PortaAvioes.h"

#include <iostream>

PortaAvioes::PortaAvioes(int tripulacaoInicial)
{
    defineTripulacaoInicial(tripulacaoInicial);
}

PortaAvioes::~PortaAvioes()
{

}

void PortaAvioes::defineTripulacaoInicial(int tripulacaoInicial){
    
    tripulacaoQuantidade = tripulacaoInicial;
    std::cout << "A tripulacao e de : " << tripulacaoQuantidade << std::endl;
}
