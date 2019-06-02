#ifndef PORTAAVIOES_H
#define PORTAAVIOES_H

#include "Hangar.h"
#include "Aviao.h"

#include <cstddef> 
using std::size_t;
using std::ostream;

#include <string>
using std::string;

class PortaAvioes
{
	friend ostream &operator<< (ostream &output, const PortaAvioes&);
	// AUXILIAR PARA COPIA DO ARRAY DE PONTEIROS
	friend void swap(PortaAvioes &, PortaAvioes &);

public:
	PortaAvioes(int,const string &, int, size_t); // Construtor que recebe todos os argumentos
	PortaAvioes(); // Construtor que não recebe nenhum dos argumentos
	PortaAvioes(const PortaAvioes &);// Construtor de copia
	~PortaAvioes();

	void setTripulacao(int);
	int getTripulacaoQuantidade() const;

	void setNomeDoCapitao(const string &);
	string getNomeDoCapitao() const; 

	void setNovoTenente(const string &);
	string getTenentes(int) const;
	void listaTenentes() const;

	void setPilotosDisponiveis(int);
	int getPilotosDisponiveis() const;

	void setCapacidade(int);
	int getCapacidade() const;

	int getNumDeAvioesAtivos() const;
	
	void cadastraTipoDeAviao(const string &);
	void getTiposDeAviao() const;

	void adicionaNovoAviao(const Aviao &);
	void getListaAvioes() const;

	void info() const;
	
	//---------------- SOBRECARGA DE OPERADORES -----------------
	
	
	const PortaAvioes &operator= (PortaAvioes);
	bool operator == (const PortaAvioes&) const;
	bool operator != (const PortaAvioes&) const;
	string &operator[] (int);
	string operator[] (int) const ;
	


private:
	Hangar hangarPrincipal;
	
	int numDeAvioesAtivos;
	size_t capacidade;
	Aviao **arrayAviao;

	void expandeArray();

	//atributos membro

	int tripulacaoQuantidade;
	int pilotosDisponiveis;
	string nomeDoCapitao;

	const int TRIPULACAOMAXIMA = 500;

	static const int NUMDETENENTES = 5;
	static string nomeDosTenentes[NUMDETENENTES];

};

#endif // PORTAAVIOES_H
