#include "PortaAvioes.h"
#include "Hangar.h"

#include <iostream>
using std::cout;

int PortaAvioes::numDeAvioesAtivos = 0; // inicializa atributo static numDeAvioesAtivos
string PortaAvioes::nomeDosTenentes[NUMDETENENTES] = {"_Vazio_","_Vazio_","_Vazio_","_Vazio_","_Vazio_"};

//----Construtores e Destrutores------------------------------------------------------------------------------------------------------------------------------------------------------------------

PortaAvioes::PortaAvioes(int tripulacaoInicial,const string &nome, int pilotosDisponiveis, int capacidade) // Construtor que recebe todos os argumentos
:hangarPrincipal()
{

	setTripulacao(tripulacaoInicial);

	setNomeDoCapitao(nome);

	setPilotosDisponiveis(pilotosDisponiveis);

	setCapacidade(capacidade);

	this->arrayAviao = new Aviao*[capacidade];

	cout<< "\n--------------- Porta Avioes Criado com Sucesso -----------" << "\n";

}

PortaAvioes::PortaAvioes() // Construtor que não recebe nenhum dos argumentos
:hangarPrincipal()
{
	this->nomeDoCapitao = "Joao Ninguem";
	this->pilotosDisponiveis = 0;
	this->capacidade = 1;
	this->tripulacaoQuantidade = 0;
	
	this->arrayAviao = new Aviao*[capacidade];
}

PortaAvioes::PortaAvioes(const PortaAvioes &origem) // construtor de copia
:hangarPrincipal()
{
	
	this->nomeDoCapitao = origem.nomeDoCapitao;
	this->pilotosDisponiveis = origem.pilotosDisponiveis;
	this->capacidade = origem.capacidade;
	this->tripulacaoQuantidade = origem.tripulacaoQuantidade;

	this->arrayAviao = new Aviao*[capacidade];
	
}

PortaAvioes::~PortaAvioes()
{
	for(int contador=0; contador < this->numDeAvioesAtivos ; contador++ )
	{
		delete this->arrayAviao[contador];
	}
	delete [] arrayAviao;

}

void PortaAvioes::info() const
{	
	cout << "---------------------------------------" << "\n";
    cout << "------- INFO DO PORTA AVIOES ----------\n" << "\n";
    getNomeDoCapitao();
	getTenentes();
    getPilotosDisponiveis();
    getCapacidade();
    getTripulacaoQuantidade();
    getNumDeAvioesAtivos();
	cout << "\n";
    hangarPrincipal.info(); // Chama a Função Info da Classe Hangar
	getListaAvioes();       // Chama a Função Info da Classe Aviao
}

//-------Funcoes Set---------------------------------------------------------------------------------------------------------------------------------------------------------

void PortaAvioes::expandeArray()
{
	this->capacidade *= 2;
	
	Aviao **arrayAux = new Aviao*[this->capacidade];
	
	for(int contador=0; contador < this-> numDeAvioesAtivos; ++contador)
	{
		arrayAux[contador] = new Aviao(*this->arrayAviao[contador]);
	}
	
	for(int contador=0; contador < this-> numDeAvioesAtivos; ++contador)
	{
		delete this->arrayAviao[contador];
	}
	delete [] this->arrayAviao;
	
	this->arrayAviao = arrayAux;
	
}

void PortaAvioes::adicionaNovoAviao(const Aviao &novoAviao)
{
	if(this->numDeAvioesAtivos >= this->capacidade)
		expandeArray();
		
	this->arrayAviao[numDeAvioesAtivos++] = new Aviao(novoAviao);
	
}

void PortaAvioes::setNomeDoCapitao(const string &nome)
{

	if(nome.length() <= 40)	{
	
		this->nomeDoCapitao = nome;
	
	}
	else if(nome.length() > 40){
		this->nomeDoCapitao = nome.substr(0,40);

		cout << "Numero de caracteres excedeu o limite, primeiros 40 caracteres utilizados" << "\n";
	}

}
 
void PortaAvioes::setNovoTenente(const string &nome)
{
	int contador = 0;
	
	for(contador = 0; contador < NUMDETENENTES;contador++){
		if(this->nomeDosTenentes[contador] == "_Vazio_"){
			if(nome.length() <= 40)	{
				this->nomeDosTenentes[contador] = nome;
				break;
			}
			else if(nome.length() > 40){
				this->nomeDosTenentes[contador] = nome.substr(0,40);
				cout << "Numero de caracteres excedeu o limite, primeiros 40 caracteres utilizados" << "\n";
				break;
			}
		}
	}

}
 
void PortaAvioes::setTripulacao(int tripulacaoInicial)
{
    if(tripulacaoInicial >= 0 && tripulacaoInicial <= TRIPULACAOMAXIMA) 
		this->tripulacaoQuantidade = tripulacaoInicial;

	if(tripulacaoInicial < 0 || tripulacaoInicial > TRIPULACAOMAXIMA){
		
		this->tripulacaoQuantidade = 0;
		
		cout << "Valor invalido inserido. \nTripulacao Inicial definida com o valor padrao.\n"; 

	}

}

void PortaAvioes::setCapacidade(int novaCapacidade)
{
	if(novaCapacidade >= 0) 
		this->capacidade = novaCapacidade;
		
	if(novaCapacidade < 0){
		
		this->capacidade = 0;
		
		cout << "Valor invalido inserido ( < 0 ). \nNumero de Decolagens Realizadas definido com o valor padrao.\n"; 

	}
	
}

void PortaAvioes::setPilotosDisponiveis(int numeroDeAvioes)
{
	if(numeroDeAvioes >= 0) 
		this->pilotosDisponiveis = numeroDeAvioes;

	if(numeroDeAvioes < 0){
		
		this->pilotosDisponiveis = 0;
		
		cout << "Valor invalido inserido ( < 0 ). \nNumero de Pilotos Disponiveis definido com o valor padrao.\n"; 

	}
	
}

void PortaAvioes::cadastraTipoDeAviao(const string &novoTipo){
	this->ponteiroHangar = &hangarPrincipal;
	
	if(novoTipo.length() <= 20){
		this->ponteiroHangar->setTipoDeAviao(novoTipo);
	}else if(novoTipo.length() > 20){
		this->ponteiroHangar->setTipoDeAviao(novoTipo.substr(0,20));
		cout << "Numero de caracteres excedeu o limite, primeiros 20 caracteres utilizados" << "\n";
	}
}

//-------Funcoes Get-----------------------------------------------------------------------------------------------------------------------------------------------------------------

void PortaAvioes::getListaAvioes() const
{
	if(numDeAvioesAtivos==0){
		cout << "------- NENHUM AVIAO CADASTRADO --------"<< "\n\n";
	}
	for(int contador=0;  contador< numDeAvioesAtivos; contador++)
	{
		this->arrayAviao[contador]->info(contador);
	}

}

void PortaAvioes::getPilotosDisponiveis() const
{

	cout << "\nO numero de Pilotos Disponiveis e de : " << this->pilotosDisponiveis << "\n";

}

void PortaAvioes::getNomeDoCapitao() const
{
	 cout << "\nO nome do Capitao e: " << this->nomeDoCapitao << "\n";
}

void PortaAvioes::getCapacidade() const
{

	cout << "\nA Quantidade De Avioes Suportada e de : " << this->capacidade << "\n";

}

void PortaAvioes::getTripulacaoQuantidade() const
{

	cout << "\nA tripulacao atual e de : " << this->tripulacaoQuantidade << "\n";

}

void PortaAvioes::getNumDeAvioesAtivos()
{
  cout << "\nO numero de Avioes ativos atualmente e de: " << numDeAvioesAtivos << "\n";
}

void PortaAvioes::getTenentes() const
{
	int contador = 0;
	
	for(contador = 0; contador < NUMDETENENTES;contador++){
		cout << "Tenente "<< contador+1 << " - " <<this->nomeDosTenentes[contador] << "\n";
	}
}

void PortaAvioes::getTiposDeAviao() const
{
	this->hangarPrincipal.getTiposDeAviao();
}