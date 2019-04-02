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
    std::cout << "A tripulacao inicial e de : " << tripulacaoQuantidade << std::endl;
}

void PortaAvioes::adicionaTripulacao(int novaTripulacao){
    tripulacaoQuantidade += novaTripulacao;
    std::cout << "A nova tripulacao e de : " << tripulacaoQuantidade << std::endl;
}
