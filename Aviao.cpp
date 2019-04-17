#include "Aviao.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

Aviao::Aviao()
{
	initTiposDeAviao();
}

Aviao::~Aviao()
{
}

void Aviao::initTiposDeAviao()
{
	for(int contador=0; contador < numDeTipos; contador++){
		tiposDeAviao[contador] = "_vazio_";
	}
}

void Aviao::getTiposDeAviao() const
{
	cout << "\n";
	for(int contador=0; contador < numDeTipos; contador++){
		cout << "Modelo "<< contador+1 << " - " <<tiposDeAviao[contador] << "\n";
	}
	cout << "\n";
}

void Aviao::setTiposDeAviao(int tipoSelecionado, string &nomeModelo)
{

	tiposDeAviao[tipoSelecionado-1] = nomeModelo;
}