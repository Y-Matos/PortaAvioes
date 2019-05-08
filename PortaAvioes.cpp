#include "PortaAvioes.h"
#include "Hangar.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

int PortaAvioes::frotaTotalAtiva = 0; // inicializa atributo static frotaTotalAtiva
const int PortaAvioes::VELOCIDADEMAXIMA = 30; // inicializa atributo const static velocidadeMaxima
const int PortaAvioes::TRIPULACAOMAXIMA = 500;
string PortaAvioes::nomeDosTenentes[3] = {"_Vazio_","_Vazio_","_Vazio_"};

//----Construtores e Destrutores------------------------------------------------------------------------------------------------------------------------------------------------------------------

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
:hangarPrincipal(), aviaoTeste("XB-70 VALKYRIE", 3310, 176.950)
{
    cout << "\nTripulacao Inicial nao informada, valor padrao carregado." << std::endl;
    setTripulacaoInicial(0);

    this->frotaTotalAtiva++;
}

PortaAvioes::PortaAvioes(const PortaAvioes &origem) // construtor de copia
:hangarPrincipal(), aviaoTeste("XB-70 VALKYRIE", 3310, 176.950)
{
	
	this->nomeDoCapitao = origem.nomeDoCapitao;
	this->avioesDisponiveis = origem.avioesDisponiveis;
	this->decolagensRealizadas = origem.decolagensRealizadas;
	this->tripulacaoQuantidade = origem.tripulacaoQuantidade;

	this->frotaTotalAtiva++;
	
}

PortaAvioes::~PortaAvioes()
{
	this->frotaTotalAtiva--;
}

void PortaAvioes::info() const
{	
	cout << "---------------------------------------" << endl;
    cout << "------- INFO DO PORTA AVIOES ----------\n" << endl;
    getNomeDoCapitao();
	getTenentes();
    getAvioesDisponiveis();
    getDecolagensRealizadas();
    getTripulacaoQuantidade();
    getFrotaTotalAtiva();
	cout << "\n";
    hangarPrincipal.info();
    aviaoTeste.info();
}

//-------Funcoes Set---------------------------------------------------------------------------------------------------------------------------------------------------------

void PortaAvioes::setNomeDoCapitao(const string &nome)
{

	if(nome.length() <= 40)	{
	
		nomeDoCapitao = nome;
	
	}
	else if(nome.length() > 40){
		nomeDoCapitao = nome.substr(0,40);

		cout << "Numero de caracteres excedeu o limite, primeiros 40 caracteres utilizados" << endl;
	}

}
 
void PortaAvioes::setNovoTenente(const string &nome)
{
	int contador = 0;
	
	for(contador = 0; contador < NUMDETENENTES;contador++){
		if(nomeDosTenentes[contador] == "_Vazio_"){
			if(nome.length() <= 40)	{
				nomeDosTenentes[contador] = nome;
				break;
			}
			else if(nome.length() > 40){
				nomeDosTenentes[contador] = nome.substr(0,40);
				cout << "Numero de caracteres excedeu o limite, primeiros 40 caracteres utilizados" << endl;
				break;
			}
		}
	}

}
 
void PortaAvioes::setTripulacaoInicial(int tripulacaoInicial)
{
    if(tripulacaoInicial >= 0 && tripulacaoInicial <= TRIPULACAOMAXIMA) 
		this->tripulacaoQuantidade = tripulacaoInicial;

	if(tripulacaoInicial < 0 || tripulacaoInicial > TRIPULACAOMAXIMA){
		
		this->tripulacaoQuantidade = 0;
		
		cout << "Valor invalido inserido. \nTripulacao Inicial definida com o valor padrao.\n"; 

	}

}

void PortaAvioes::setDecolagensRealizadas(int numeroDeDecolagens)
{
	if(numeroDeDecolagens >= 0) 
		this->decolagensRealizadas = numeroDeDecolagens;

	if(numeroDeDecolagens < 0){
		
		this->decolagensRealizadas = 0;
		
		cout << "Valor invalido inserido ( < 0 ). \nNumero de Decolagens Realizadas definido com o valor padrao.\n"; 

	}
	
}

void PortaAvioes::setAvioesDisponiveis(int numeroDeAvioes)
{
	if(numeroDeAvioes >= 0) 
		this->avioesDisponiveis = numeroDeAvioes;

	if(numeroDeAvioes < 0){
		
		this->avioesDisponiveis = 0;
		
		cout << "Valor invalido inserido ( < 0 ). \nNumero de Avioes Disponiveis definido com o valor padrao.\n"; 

	}
	
}

void PortaAvioes::adicionaTripulacao(int novaTripulacao)
{
	if(novaTripulacao>=1 && novaTripulacao <= TRIPULACAOMAXIMA-tripulacaoQuantidade){
    
		this->tripulacaoQuantidade += novaTripulacao;
	
		cout << "\nTripulacao adicionada com sucesso.\n";
	
	}
	if(novaTripulacao < 1 || novaTripulacao > TRIPULACAOMAXIMA-tripulacaoQuantidade){
		cout << "\nValor informado e invalido.\nTripulacao nao foi alterada.\n\n";
	}
}

void PortaAvioes::adicionaTripulacao()
{
    
    tripulacaoQuantidade++;
    
    cout << "\nNenhum valor informado, adicionado 1 tripulante." << std::endl;
    
    getTripulacaoQuantidade();

}

void PortaAvioes::cadastraTipoDeAviao(const string &novoTipo){
	ponteiroHangar = &hangarPrincipal;
	
	if(novoTipo.length() <= 20){
		ponteiroHangar->setTipoDeAviao(novoTipo);
	}else if(novoTipo.length() > 20){
		ponteiroHangar->setTipoDeAviao(novoTipo.substr(0,20));
		cout << "Numero de caracteres excedeu o limite, primeiros 20 caracteres utilizados" << endl;
	}
}

void PortaAvioes::atualizaHangar(Hangar *novoHangar){
	hangarPrincipal.setNovoHangar(novoHangar);
}
//-------Funcoes Get-----------------------------------------------------------------------------------------------------------------------------------------------------------------

void PortaAvioes::getAvioesDisponiveis() const
{

	cout << "\nO numero de Avioes Disponiveis e de : " << avioesDisponiveis << std::endl;

}

void PortaAvioes::getNomeDoCapitao() const
{
	 cout << "\nO nome do Capitao e: " << nomeDoCapitao << endl;
}

void PortaAvioes::getDecolagensRealizadas() const
{

	cout << "\nO numero de Decolagens Realizadas e de : " << decolagensRealizadas << std::endl;

}

void PortaAvioes::getTripulacaoQuantidade() const
{

	cout << "\nA tripulacao atual e de : " << tripulacaoQuantidade << std::endl;

}

void PortaAvioes::getFrotaTotalAtiva()
{
  cout << "\nO numero de Porta Avioes ativos atualmente e de: " <<frotaTotalAtiva << endl;
}

void PortaAvioes::getTenentes() const
{
	int contador = 0;
	
	for(contador = 0; contador < NUMDETENENTES;contador++){
		cout << "Tenente "<< contador+1 << " - " <<nomeDosTenentes[contador] << "\n";
	}
}
