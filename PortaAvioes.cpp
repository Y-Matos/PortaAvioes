#include "PortaAvioes.h"
#include "Hangar.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

int PortaAvioes::frotaTotalAtiva = 0; // inicializa atributo static frotaTotalAtiva
const int PortaAvioes::velocidadeMaxima = 30; // inicializa atributo const static velocidadeMaxima

void PortaAvioes::info() const
{	
	cout << "---------------------------------------" << endl;
    cout << "------- INFO DO PORTA AVIOES ----------\n" << endl;
    getNomeDoCapitao();
    getAvioesDisponiveis();
    getDecolagensRealizadas();
    getTripulacaoQuantidade();
    getFrotaTotalAtiva();
	cout << "\n";
    hangarPrincipal.info();
    aviaoTeste.info();
}

PortaAvioes::PortaAvioes(int tripulacaoInicial,const string &nome, int avioesDisponiveis, int decolagensRealizadas) // Construtor que recebe todos os argumentos
:hangarPrincipal(), aviaoTeste("XB-70 VALKYRIE", 3310, 176.950)
{
    
	setTripulacaoInicial(tripulacaoInicial);
	
	setNomeDoCapitao(nome);
	
	setAvioesDisponiveis(avioesDisponiveis);
	
	setDecolagensRealizadas(decolagensRealizadas);

	this->frotaTotalAtiva++;
	
	cout<< "\n--------------- Porta Avioes Criado com Sucesso -----------" << endl;
}

PortaAvioes::PortaAvioes() // Construtor que não recebe nenhum dos argumentos
:hangarPrincipal(), aviaoTeste("XB-70 VALKYRIE", 3310, 300)
{
    cout << "\nTripulacao Inicial nao informada, valor padrao carregado." << std::endl;
    setTripulacaoInicial(0);

    this->frotaTotalAtiva++;
}

PortaAvioes::PortaAvioes(const PortaAvioes &origem) // construtor de copia
:hangarPrincipal(), aviaoTeste("XB-70 VALKYRIE", 3310, 300)
{
	
	this->nomeDoCapitao = origem.nomeDoCapitao;
	this->avioesDisponiveis = origem.avioesDisponiveis;
	this->decolagensRealizadas = origem.decolagensRealizadas;
	this->tripulacaoQuantidade = origem.tripulacaoQuantidade;

	this->frotaTotalAtiva++;
	
}

void PortaAvioes::setNomeDoCapitao(const string &nome)
{

	if(nome.length() <= 40)	{
	
		this->nomeDoCapitao = nome;
	
	}
	else if(nome.length() > 40){
		this->nomeDoCapitao = nome.substr(0,40);

		cout << "Numero de caracteres excedeu o limite, primeiros 40 caracteres utilizados" << endl;
	}

	getNomeDoCapitao();

}
 
void PortaAvioes::getNomeDoCapitao() const
{
	 cout << "\nO nome do Capitao e: " << this->nomeDoCapitao << endl;
}
 
void PortaAvioes::setTripulacaoInicial(int tripulacaoInicial)
{
    if(tripulacaoInicial >= 0 && tripulacaoInicial <= tripulacaoMaxima) 
		tripulacaoQuantidade = tripulacaoInicial;

	if(tripulacaoInicial < 0 || tripulacaoInicial > tripulacaoMaxima){
		
		tripulacaoQuantidade = 0;
		
		cout << "Valor invalido inserido. \nTripulacao Inicial definida com o valor padrao.\n"; 

	}

    cout << "\nA tripulacao inicial e de : " << this->tripulacaoQuantidade << std::endl;

}

void PortaAvioes::getTripulacaoQuantidade() const
{

	cout << "\nA tripulacao atual e de : " << this->tripulacaoQuantidade << std::endl;

}

void PortaAvioes::adicionaTripulacao(int novaTripulacao)
{
	if(novaTripulacao>=1 && novaTripulacao <= tripulacaoMaxima-tripulacaoQuantidade){
    
		this->tripulacaoQuantidade += novaTripulacao;
	
		cout << "\nTripulacao adicionada com sucesso.\n";

    	getTripulacaoQuantidade();
	
	}
	if(novaTripulacao < 1 || novaTripulacao > tripulacaoMaxima-tripulacaoQuantidade){
		cout << "\nValor informado e invalido.\nTripulacao nao foi alterada.\n\n";
	}
}

void PortaAvioes::adicionaTripulacao()
{
    
    this->tripulacaoQuantidade++;
    
    cout << "\nNenhum valor informado, adicionado 1 tripulante." << std::endl;
    
    getTripulacaoQuantidade();

}

void PortaAvioes::setAvioesDisponiveis(int numeroDeAvioes)
{
	if(numeroDeAvioes >= 0) 
		this->avioesDisponiveis = numeroDeAvioes;

	if(numeroDeAvioes < 0){
		
		this->avioesDisponiveis = 0;
		
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
		this->decolagensRealizadas = numeroDeDecolagens;

	if(numeroDeDecolagens < 0){
		
		this->decolagensRealizadas = 0;
		
		cout << "Valor invalido inserido ( < 0 ). \nNumero de Decolagens Realizadas definido com o valor padrao.\n"; 

	}
	
	getDecolagensRealizadas();
	
}

void PortaAvioes::getDecolagensRealizadas() const
{

	cout << "\nO numero de Decolagens Realizadas e de : " << this->decolagensRealizadas << std::endl;

}

void PortaAvioes::getFrotaTotalAtiva()
{
  cout << "\nO numero de Porta Avioes ativos atualmente e de: " << frotaTotalAtiva << endl;
}
