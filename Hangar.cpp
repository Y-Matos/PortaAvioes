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

string Hangar::getTiposDeAviao(int contador) const
{
	return tiposNome[contador];
}


void Hangar::info() const
{
	
	if(tiposAtivos>0){
		cout << "----------------------------------------" << "\n";
		cout << "----------- INFO DO HANGAR -------------" << "\n";
	}else{
		cout << "------------ HANGAR VAZIO --------------"<< "\n";
	}
	
	for(int contador=0; contador < tiposAtivos; contador++){
		cout << "Classe "<< contador+1 << " - " << getTiposDeAviao(contador) << "\n";
	}
	cout << "\n";
}

//---------------- SOBRECARGA DE OPERADORES -----------------

ostream& operator << (ostream &output, const Hangar& origem)
{
	if(origem.tiposAtivos > 0){
		cout << "----------------------------------------" << "\n";
		cout << "----------- INFO DO HANGAR -------------" << "\n";
	}else{
		cout << "------------ HANGAR VAZIO --------------"<< "\n";
	}
	
	for(int contador=0; contador < origem.tiposAtivos; contador++){
		cout << "Classe "<< contador+1 << " - " << origem.getTiposDeAviao(contador) << "\n";
	}
	cout << "\n";
	
	return output;
}

const Hangar &Hangar::operator= (const Hangar &origem)
{
	if(this != &origem)
	{
		this->tiposAtivos = origem.tiposAtivos;
		
		for(int contador = 0; contador < NUMDETIPOS;contador++)
		{
			this->tiposNome[contador] = origem.tiposNome[contador];
		}
	}
	return *this;
}

bool Hangar::operator == (const Hangar &origem) const
{
	if(this->tiposAtivos != origem.tiposAtivos)
	{
		return false;
	}
	for(int contador=0; contador<origem.tiposAtivos; ++contador)
	{
		if(this->tiposNome[contador] != origem.tiposNome[contador])
		{
			return false;
		}
	}
	return true;

}

bool Hangar::operator != (const Hangar &origem) const
{
		return !(*this == origem);
}

string &Hangar::operator[] (int index)
{
	if(index < 0 || index >= NUMDETIPOS)
	{
		cout << "\nIndex fora dos limites \n";
		cout << "Index 0 sera utilizado\n"; 
		return tiposNome[0];
	}
	return tiposNome[index];
}

string Hangar::operator[] (int index) const
{
	if(index < 0 || index >= NUMDETIPOS)
	{
		cout << "\nIndex fora dos limites \n";
		cout << "Index 0 utilizado\n"; 
		return tiposNome[0];
	}
	return tiposNome[index];
}