#include "Hangar.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

Hangar::Hangar()
{

	initTiposDeAviao();
}

Hangar::~Hangar()
{
}

void Hangar::initTiposDeAviao()
{
	for(int contador=0; contador < numDeTipos; contador++){
		tiposDeAviao[contador] = "_vazio_";
	}
}

void Hangar::getTiposDeAviao() const
{
	cout << "\n";
	for(int contador=0; contador < numDeTipos; contador++){
		cout << "Classe "<< contador+1 << " - " <<tiposDeAviao[contador] << "\n";
	}
	cout << "\n";
}

void Hangar::setTiposDeAviao(int tipoSelecionado, string &nomeModelo)
{

	tiposDeAviao[tipoSelecionado-1] = nomeModelo;
}

void Hangar::info() const
{
	cout << "----------------------------------------" << endl;
    cout << "----------- INFO DO HANGAR -------------\n" << endl;
    getTiposDeAviao();
    
}