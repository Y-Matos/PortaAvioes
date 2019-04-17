#include "PortaAvioes.h"
#include "Aviao.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

int PortaAvioes::frotaTotalAtiva = 0; // inicializa atributo static frotaTotalAtiva
const int PortaAvioes::velocidadeMaxima = 30; // inicializa atributo const static velocidadeMaxima


PortaAvioes::PortaAvioes(int tripulacaoInicial, string &nome, int avioesDisponiveis, int decolagensRealizadas)
:hangar()
{
    
	setTripulacaoInicial(tripulacaoInicial);
	
	setNomeDoCapitao(nome);
	
	setAvioesDisponiveis(avioesDisponiveis);
	
	setDecolagensRealizadas(decolagensRealizadas);

	frotaTotalAtiva++;
	
	cout<< "\n--------------- Porta Avioes Criado com Sucesso -----------" << endl;
}

PortaAvioes::PortaAvioes()
{
    cout << "\nTripulacao Inicial nao informada, valor padrao carregado." << std::endl;
    setTripulacaoInicial(0);

    frotaTotalAtiva++;
}

PortaAvioes::PortaAvioes(const PortaAvioes &origem)
{// construtor de copia
	
	nomeDoCapitao = origem.nomeDoCapitao;
	avioesDisponiveis = origem.avioesDisponiveis;
	decolagensRealizadas = origem.decolagensRealizadas;
	tripulacaoQuantidade = origem.tripulacaoQuantidade;

  frotaTotalAtiva++;
	
}

void PortaAvioes::setNomeDoCapitao(string &nome)
{

	if(nome.length() <= 40)	{
	
		nomeDoCapitao = nome;
	
	}
	else if(nome.length() > 40){
		nomeDoCapitao = nome.substr(0,40);

		cout << "Numero de caracteres excedeu o limite, primeiros 40 caracteres utilizados" << endl;
	}

	getNomeDoCapitao();

}
 
void PortaAvioes::getNomeDoCapitao() const
{
	 cout << "\nO nome do Capitao e: " << nomeDoCapitao << endl;
}
 
void PortaAvioes::setTripulacaoInicial(int tripulacaoInicial)
{
    if(tripulacaoInicial >= 0 && tripulacaoInicial <= tripulacaoMaxima) 
		tripulacaoQuantidade = tripulacaoInicial;

	if(tripulacaoInicial < 0 || tripulacaoInicial > tripulacaoMaxima){
		
		tripulacaoQuantidade = 0;
		
		cout << "Valor invalido inserido. \nTripulacao Inicial definida com o valor padrao.\n"; 

	}

    cout << "\nA tripulacao inicial e de : " << tripulacaoQuantidade << std::endl;

}

void PortaAvioes::getTripulacaoQuantidade() const
{

	cout << "\nA tripulacao atual e de : " << tripulacaoQuantidade << std::endl;

}

void PortaAvioes::adicionaTripulacao(int novaTripulacao)
{
	if(novaTripulacao>=1 && novaTripulacao <= tripulacaoMaxima-tripulacaoQuantidade){
    
		tripulacaoQuantidade += novaTripulacao;
	
		cout << "\nTripulacao adicionada com sucesso.\n";

    	getTripulacaoQuantidade();
	
	}
	if(novaTripulacao < 1 || novaTripulacao > tripulacaoMaxima-tripulacaoQuantidade){
		cout << "\nValor informado e invalido.\nTripulacao nao foi alterada.\n\n";
	}
}

void PortaAvioes::adicionaTripulacao()
{
    
    tripulacaoQuantidade++;
    
    cout << "\nNenhum valor informado, adicionado 1 tripulante." << std::endl;
    
    getTripulacaoQuantidade();

}

void PortaAvioes::setAvioesDisponiveis(int numeroDeAvioes)
{
	if(numeroDeAvioes >= 0) 
		avioesDisponiveis = numeroDeAvioes;

	if(numeroDeAvioes < 0){
		
		avioesDisponiveis = 0;
		
		cout << "Valor invalido inserido ( < 0 ). \nNumero de Avioes Disponiveis definido com o valor padrao.\n"; 

	}
	
	getAvioesDisponiveis();
	
}

void PortaAvioes::getAvioesDisponiveis() const
{

	cout << "\nO numero de Avioes Disponiveis e de : " << avioesDisponiveis << std::endl;

}

void PortaAvioes::setDecolagensRealizadas(int numeroDeDecolagens)
{
	if(numeroDeDecolagens >= 0) 
		decolagensRealizadas = numeroDeDecolagens;

	if(numeroDeDecolagens < 0){
		
		decolagensRealizadas = 0;
		
		cout << "Valor invalido inserido ( < 0 ). \nNumero de Decolagens Realizadas definido com o valor padrao.\n"; 

	}
	
	getDecolagensRealizadas();
	
}

void PortaAvioes::getDecolagensRealizadas() const
{

	cout << "\nO numero de Decolagens Realizadas e de : " << decolagensRealizadas << std::endl;

}

void PortaAvioes::getFrotaTotalAtiva()
{
  cout << "\nO numero de Porta Avioes ativos atualmente e de: " << frotaTotalAtiva << endl;
}