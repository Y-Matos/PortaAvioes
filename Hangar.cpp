#include "Hangar.h"

#include <iostream>
using std::cout;

//----Construtores e Destrutores------------------------------------------------------------------------------------------------------------------------------------------------------------------

Hangar::Hangar(const string &tipo1,const string &tipo2,const string &tipo3,const string &tipo4,const string &tipo5){
	this->tiposNome[0] = tipo1;
	this->tiposNome[1] = tipo2;
	this->tiposNome[2] = tipo3;
	this->tiposNome[3] = tipo4;
	this->tiposNome[4] = tipo5;
	
	this->tiposAtivos = 5;
}

Hangar::Hangar()
{
	for(int contador = 0; contador < this->NUMDETIPOS; contador++){
		this->tiposNome[contador] = "_Vazio_";
	}
	this->tiposAtivos = 0;
}

Hangar::Hangar(const Hangar &origem){
	for(int contador = 0; contador < this->NUMDETIPOS; contador++){
		this->tiposNome[contador] = origem.tiposNome[contador];
	}
	this->tiposAtivos = origem.tiposAtivos;
	
}

Hangar::~Hangar()
{
}

//-------Funcoes Set---------------------------------------------------------------------------------------------------------------------------------------------------------

void Hangar::setTipoDeAviao(const string &nome)
{
	int contador = 0;
	
	for(contador = 0; contador < NUMDETIPOS;contador++){
		if(tiposNome[contador] == "_Vazio_"){
			if(nome.length() <= 40)	{
				tiposNome[contador] = nome;
				break;
			}
			else if(nome.length() > 40){
				tiposNome[contador] = nome.substr(0,40);
				cout << "Numero de caracteres excedeu o limite, primeiros 40 caracteres utilizados" << "\n";
				break;
			}
		}
	}
	tiposAtivos++;
}

//-------Funcoes Get-----------------------------------------------------------------------------------------------------------------------------------------------------------------

void Hangar::getTiposDeAviao() const
{
	if(tiposAtivos>0){
		cout << "----------------------------------------" << "\n";
		cout << "----------- INFO DO HANGAR -------------" << "\n";
	}else{
		cout << "------------ HANGAR VAZIO --------------"<< "\n";
	}
	
	for(int contador=0; contador < tiposAtivos; contador++){
		cout << "Classe "<< contador+1 << " - " <<tiposNome[contador] << "\n";
	}
	cout << "\n";
}


void Hangar::info() const
{

    getTiposDeAviao();
    
}