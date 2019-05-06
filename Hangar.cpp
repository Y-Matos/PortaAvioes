#include "Hangar.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

Hangar::Hangar(const int nTipos)
{
	if (nTipos > 0)
	{
		tiposNome = new string[nTipos];
		this->numDeTipos = nTipos;
		cout << "/nHangar possui " << this->numDeTipos << " tipos de Avioes." << endl;
	}
	else
	{
		this->tiposNome = 0;
		this->numDeTipos = 0;
		cout << "/nNao foi cadastrado nenhum tipo de aviao." << endl;
	}
}

Hangar::~Hangar()
{
	delete [] tiposNome;
}

void Hangar::getTiposDeAviao() const
{
	cout << "\n";
	for(int contador=0; contador < numDeTipos; contador++){
		cout << "Classe "<< contador+1 << " - " <<tiposNome[contador] << "\n";
	}
	cout << "\n";
}

void Hangar::cadastraTipoDeAviao(const string &nomeModelo, const int indice)
{
	if (indice >= 0 && indice < numDeTipos){

		this->tiposNome[indice] = nomeModelo;

	}
	else
	{
		cout << "/nIndice inexistente" << endl;
	}
	
}

void Hangar::adicionaTipoDeAviao(const string &nomeModelo)
{
	string *aux = new string[numDeTipos];
	
	for( int indice = 0; indice < numDeTipos; indice++){
		aux[indice] = tiposNome[indice];
	}
	
	delete [] tiposNome;
	
	tiposNome = new string[++numDeTipos];
	
	for( int indice = 0; indice < numDeTipos-1; indice++){
		tiposNome[indice] = aux[indice];
	}
	
	tiposNome[numDeTipos-1] = nomeModelo;
	
	delete [] aux;
}

void Hangar::info() const
{
	cout << "----------------------------------------" << endl;
    cout << "----------- INFO DO HANGAR -------------\n" << endl;
    getTiposDeAviao();
    
}