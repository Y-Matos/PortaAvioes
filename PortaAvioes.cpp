#include "PortaAvioes.h"
#include "Hangar.h"

#include <algorithm> // std::copy
#include <iostream>
using std::cout;


string PortaAvioes::nomeDosTenentes[NUMDETENENTES] = {"_Vazio_","_Vazio_","_Vazio_","_Vazio_","_Vazio_"};

//----Construtores e Destrutores------------------------------------------------------------------------------------------------------------------------------------------------------------------

PortaAvioes::PortaAvioes(int tripulacaoInicial,const string &nome, int pilotosDisponiveis, size_t capacidade) // Construtor que recebe todos os argumentos
:hangarPrincipal(), numDeAvioesAtivos(0) , capacidade(capacidade)
{
	
	setTripulacao(tripulacaoInicial);

	setNomeDoCapitao(nome);

	setPilotosDisponiveis(pilotosDisponiveis);

	this->arrayAviao = new Aviao*[capacidade];

	cout<< "\n--------------- Porta Avioes Criado com Sucesso -----------" << "\n";

}

PortaAvioes::PortaAvioes() // Construtor que não recebe nenhum dos argumentos
:hangarPrincipal(), numDeAvioesAtivos(0)
{
	this->nomeDoCapitao = "Joao Ninguem";
	this->pilotosDisponiveis = 1;
	this->capacidade = 1;
	this->tripulacaoQuantidade = 1;
	
	this->arrayAviao = new Aviao*[capacidade];
	
	cout<< "\n--------------- Porta Avioes Criado com Sucesso -----------" << "\n";
}

PortaAvioes::PortaAvioes(const PortaAvioes &origem) // construtor de copia
:hangarPrincipal(), capacidade(origem.capacidade), arrayAviao(capacidade ? new Aviao*[capacidade]:nullptr)
{
	this->hangarPrincipal = origem.hangarPrincipal;
	this->nomeDoCapitao = origem.nomeDoCapitao;
	this->pilotosDisponiveis = origem.pilotosDisponiveis;
	this->numDeAvioesAtivos = origem.numDeAvioesAtivos;
	this->tripulacaoQuantidade = origem.tripulacaoQuantidade;
	
	std::copy(origem.arrayAviao,origem.arrayAviao + capacidade, arrayAviao);
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
	cout << "\nO nome do Capitao e: " << getNomeDoCapitao() << "\n";
	listaTenentes();
	
	cout << "\nO numero de Pilotos Disponiveis e de : " << getPilotosDisponiveis() << "\n";
	cout << "\nA Quantidade De Avioes Suportada e de : " << getCapacidade() << "\n";
	cout << "\nA tripulacao atual e de : " << getTripulacaoQuantidade() << "\n";
	cout << "\nO numero de Avioes ativos atualmente e de: " << getNumDeAvioesAtivos() << "\n";
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
	int capacity = capacidade;
	if(this->numDeAvioesAtivos >= capacity)
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

	if(novoTipo.length() <= 20)
	{
		this->hangarPrincipal.setTipoDeAviao(novoTipo);
	}else if(novoTipo.length() > 20){
		this->hangarPrincipal.setTipoDeAviao(novoTipo.substr(0,20));
		cout << "Numero de caracteres excedeu o limite, primeiros 20 caracteres utilizados" << "\n";
	}
}

//-------Funcoes Get-----------------------------------------------------------------------------------------------------------------------------------------------------------------

int PortaAvioes::getPilotosDisponiveis() const
{

	return this->pilotosDisponiveis;

}

string PortaAvioes::getNomeDoCapitao() const
{
	return this->nomeDoCapitao;
}

int PortaAvioes::getCapacidade() const
{

	return this->capacidade;

}

int PortaAvioes::getTripulacaoQuantidade() const
{

	return this->tripulacaoQuantidade;

}

int PortaAvioes::getNumDeAvioesAtivos() const
{
	return this->numDeAvioesAtivos;
}

string PortaAvioes::getTenentes(int contador) const
{
	return this->nomeDosTenentes[contador];
}

//-------Funcoes LISTA-----------------------------------------------------------------------------------------------------------------------------------------------------------------

void PortaAvioes::listaTenentes() const
{
	for(int contador = 0; contador < NUMDETENENTES;contador++){
		cout << "Tenente "<< contador+1 << " - " << getTenentes(contador) << "\n";
	}
}

void PortaAvioes::getTiposDeAviao() const
{
	this->hangarPrincipal.info();
}

void PortaAvioes::getListaAvioes() const
{
	if(this->numDeAvioesAtivos==0){
		cout << "------- NENHUM AVIAO CADASTRADO --------"<< "\n\n";
	}
	for(int contador=0;  contador< this->numDeAvioesAtivos; contador++)
	{
		this->arrayAviao[contador]->info(contador);
	}

}

//---------------- SOBRECARGA DE OPERADORES -----------------

const PortaAvioes &PortaAvioes::operator= (PortaAvioes origem)
{
	swap(*this,origem);
	return *this;

}

ostream& operator<<(ostream &output, const PortaAvioes& origem)
{
	output << "---------------------------------------" << "\n";
    output << "------- INFO DO PORTA AVIOES ----------\n" << "\n";
	output << "\nO nome do Capitao e: " << origem.getNomeDoCapitao() << "\n";
	origem.listaTenentes();
	
	output << "\nO numero de Pilotos Disponiveis e de : " << origem.getPilotosDisponiveis() << "\n";
	output << "\nA Quantidade De Avioes Suportada e de : " << origem.getCapacidade() << "\n";
	output << "\nA tripulacao atual e de : " << origem.getTripulacaoQuantidade() << "\n";
	output << "\nO numero de Avioes ativos atualmente e de: " << origem.getNumDeAvioesAtivos() << "\n";
	output << "\n";
    origem.hangarPrincipal.info(); // Chama a Função Info da Classe Hangar
	origem.getListaAvioes();       // Chama a Função Info da Classe Aviao
	return output;
}

bool PortaAvioes::operator == (const PortaAvioes &origem) const
{
	if(this->capacidade != origem.capacidade)
		return false;
	if(this->numDeAvioesAtivos != origem.numDeAvioesAtivos)
		return false;
	if(this->tripulacaoQuantidade != origem.tripulacaoQuantidade)
		return false;
	if(this->pilotosDisponiveis != origem.pilotosDisponiveis)
		return false;
	if(this->nomeDoCapitao != origem.nomeDoCapitao)
		return false;
	
	if(this->hangarPrincipal != origem.hangarPrincipal)
	{
		return false;
	}
	for(int contador=0; contador < origem.numDeAvioesAtivos ; contador++ )
	{
		if(this->arrayAviao[contador] != origem.arrayAviao[contador]){
			return false;
		}
	}
	
	return true;
}

bool PortaAvioes::operator != (const PortaAvioes &origem) const
{
	return !(*this == origem);
}

string &PortaAvioes::operator[] (int index)
{
	if(index < 0 || index >= NUMDETENENTES)
	{
		cout << "\nIndex fora dos limites \n";
		cout << "Index 0 sera utilizado\n"; 
		return this->nomeDosTenentes[0];
	}
	return this->nomeDosTenentes[index];
}

string PortaAvioes::operator[] (int index) const
{
	if(index < 0 || index >= NUMDETENENTES)
	{
		cout << "\nIndex fora dos limites \n";
		cout << "Index 0 utilizado\n"; 
		return this->nomeDosTenentes[0];
	}
	return this->nomeDosTenentes[index];
}

// AUXILIAR PARA COPIA DO ARRAY DE PONTEIROS
void swap(PortaAvioes& primeiro, PortaAvioes& segundo)
{
		using std::swap;
		swap(primeiro.numDeAvioesAtivos, segundo.numDeAvioesAtivos);
		swap(primeiro.tripulacaoQuantidade, segundo.tripulacaoQuantidade);
		swap(primeiro.pilotosDisponiveis, segundo.pilotosDisponiveis);
		swap(primeiro.nomeDoCapitao, segundo.nomeDoCapitao);
		swap(primeiro.capacidade, segundo.capacidade);
		swap(primeiro.arrayAviao, segundo.arrayAviao);
}
