#include "Hangar.h"
#include "Aviao.h"

#ifndef PORTAAVIOES_H
#define PORTAAVIOES_H

#include <string>
using std::string;

class PortaAvioes
{
public:
	PortaAvioes(int,const string &, int, int); // Construtor que recebe todos os argumentos
	PortaAvioes(); // Construtor que não recebe nenhum dos argumentos
	PortaAvioes(const PortaAvioes &);// Construtor de copia
	~PortaAvioes();

	void setTripulacao(int);
	void getTripulacaoQuantidade() const;

	void setNomeDoCapitao(const string &);
	void getNomeDoCapitao() const; 

	void setNovoTenente(const string &);
	void getTenentes() const;

	void setPilotosDisponiveis(int);
	void getPilotosDisponiveis() const;

	void setCapacidade(int);
	void getCapacidade() const;

	static void getNumDeAvioesAtivos();//metodo static

	void cadastraTipoDeAviao(const string &);
	void getTiposDeAviao() const;

	void adicionaNovoAviao(const Aviao &);
	void getListaAvioes() const;

	void info() const;

private:

	Hangar hangarPrincipal;
	Hangar *ponteiroHangar;
	Aviao **arrayAviao;

	static int numDeAvioesAtivos;

	void expandeArray();

	//atributos membro

	int tripulacaoQuantidade;
	int pilotosDisponiveis;
	int capacidade;
	string nomeDoCapitao;

	const int TRIPULACAOMAXIMA = 500;

	static const int NUMDETENENTES = 5;
	static string nomeDosTenentes[NUMDETENENTES];

};

#endif // PORTAAVIOES_H
