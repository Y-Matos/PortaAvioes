#include "PortaAvioes.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

int main(){

	string nomeDoCapitao;
	
	cout << "Insira o nome do capitao: " << endl;
	getline(cin, nomeDoCapitao);
	
	PortaAvioes portaAviao1(10, nomeDoCapitao,5, 2);
	
	cout<< "\n\n\n-------- Criando Copia ------- ";
	
	PortaAvioes copiaPortaAviao(portaAviao1);// criando copia do primeiro objeto
    
	copiaPortaAviao.adicionaTripulacao(15);
	
	copiaPortaAviao.getTripulacaoQuantidade();
	copiaPortaAviao.getNomeDoCapitao();
	copiaPortaAviao.getAvioesDisponiveis();
	copiaPortaAviao.getDecolagensRealizadas();
	
	PortaAvioes::getFrotaTotalAtiva();// usando metodo static no main

	return 0;
	
}