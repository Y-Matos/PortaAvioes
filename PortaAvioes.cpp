#include "PortaAvioes.h"

#include <iostream>
using std::cout;

PortaAvioes::PortaAvioes(int tripulacaoInicial)
{
    defineTripulacaoInicial(tripulacaoInicial);
}

PortaAvioes::~PortaAvioes()
{

}

void PortaAvioes::defineTripulacaoInicial(int tripulacaoInicial)
{
    if(tripulacaoInicial >= 0) 
		tripulacaoQuantidade = tripulacaoInicial;

	if(tripulacaoInicial < 0){
		
		tripulacaoQuantidade = 0;
		
		cout << "Valor invalido inserido ( < 0 ). \nTripulacao Inicial definida com o valor padrao.\n"; 

	}

    cout << "\nA tripulacao inicial e de : " << tripulacaoQuantidade << std::endl;

}

void PortaAvioes::adicionaTripulacao(int novaTripulacao)
{
	if(novaTripulacao>=1){
    
		tripulacaoQuantidade += novaTripulacao;
	
		cout << "\nTripulacao adicionada com sucesso.\n";

    	cout << "\nA nova tripulacao e de : " << tripulacaoQuantidade << std::endl;
	
	}
	if(novaTripulacao < 1){
		cout << "\nValor informado e invalido. ( < 1 )\nTripulacao nao foi alterada.\n\n";
	}
}
