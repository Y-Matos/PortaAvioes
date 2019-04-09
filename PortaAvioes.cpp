#include "PortaAvioes.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

PortaAvioes::PortaAvioes(int tripulacaoInicial, string &nome){
    
	setTripulacaoInicial(tripulacaoInicial);
	
	setNomeDoCapitao(nome);
	
}

PortaAvioes::PortaAvioes(){
    cout << "\nTripulacao Inicial nao informada, valor padrao carregado." << std::endl;
    setTripulacaoInicial(0);
}

void PortaAvioes::setNomeDoCapitao(string &nome){

	if(nome.length() <= 40)	{
	
		nomeDoCapitao = nome;
	
	}
	else if(nome.length() > 40){
		nomeDoCapitao = nome.substr(0,40);

		cout << "Numero de caracteres excedeu o limite, primeiros 40 caracteres utilizados" << endl;
	}

	getNomeDoCapitao();

}
 
const void PortaAvioes::getNomeDoCapitao(){
	 cout << "\nO nome do Capitao e: " << nomeDoCapitao << endl;
 }
 
void PortaAvioes::setTripulacaoInicial(int tripulacaoInicial){
    if(tripulacaoInicial >= 0) 
		tripulacaoQuantidade = tripulacaoInicial;

	if(tripulacaoInicial < 0){
		
		tripulacaoQuantidade = 0;
		
		cout << "Valor invalido inserido ( < 0 ). \nTripulacao Inicial definida com o valor padrao.\n"; 

	}

    cout << "\nA tripulacao inicial e de : " << tripulacaoQuantidade << std::endl;

}

const void PortaAvioes::getTripulacaoQuantidade(){

	cout << "\nA tripulacao atual e de : " << tripulacaoQuantidade << std::endl;

}

void PortaAvioes::adicionaTripulacao(int novaTripulacao){
	if(novaTripulacao>=1){
    
		tripulacaoQuantidade += novaTripulacao;
	
		cout << "\nTripulacao adicionada com sucesso.\n";

    	getTripulacaoQuantidade();
	
	}
	if(novaTripulacao < 1){
		cout << "\nValor informado e invalido. ( < 1 )\nTripulacao nao foi alterada.\n\n";
	}
}

void PortaAvioes::adicionaTripulacao(){
    
    tripulacaoQuantidade++;
    
    cout << "\nNenhum valor informado, adicionado 1 tripulante." << std::endl;
    
    getTripulacaoQuantidade();

}
