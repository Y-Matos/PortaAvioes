#include "Hangar.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

//----Construtores e Destrutores------------------------------------------------------------------------------------------------------------------------------------------------------------------

Hangar::Hangar(const string &tipo1,const string &tipo2,const string &tipo3,const string &tipo4,const string &tipo5){
	this->tiposNome[0] = tipo1;
	this->tiposNome[1] = tipo2;
	this->tiposNome[2] = tipo3;
	this->tiposNome[3] = tipo4;
	this->tiposNome[4] = tipo5;
}

Hangar::Hangar()
{
	for(int contador = 0; contador < this->NUMDETIPOS; contador++){
		this->tiposNome[contador] = "_VAZIO_";
	}
}

Hangar::Hangar(const Hangar &origem){
	for(int contador = 0; contador < this->NUMDETIPOS; contador++){
		this->tiposNome[contador] = origem.tiposNome[contador];
	}
}

Hangar::~Hangar()
{
}

//-------Funcoes Set---------------------------------------------------------------------------------------------------------------------------------------------------------

void Hangar::setTipoDeAviao(const string &nomeModelo)
{
	int contador;
	for(contador = 0; tiposNome[contador] != "_VAZIO_"; contador++){}
	
	tiposNome[contador] = nomeModelo;
	
	
}

void Hangar::setNovoHangar(Hangar *novoHangar){
	
	for(int contador = 0; contador < this->NUMDETIPOS; contador++){
		this->tiposNome[contador] = novoHangar->tiposNome[contador];
	}
	
}

//-------Funcoes Get-----------------------------------------------------------------------------------------------------------------------------------------------------------------

void Hangar::getTiposDeAviao() const
{
	cout << "\n";
	for(int contador=0; contador < NUMDETIPOS; contador++){
		cout << "Classe "<< contador+1 << " - " <<tiposNome[contador] << "\n";
	}
	cout << "\n";
}


void Hangar::info() const
{
	cout << "----------------------------------------" << endl;
    cout << "----------- INFO DO HANGAR -------------\n" << endl;
    getTiposDeAviao();
    
}