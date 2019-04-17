#include "Aviao.h"
#ifndef PORTAAVIOES_H
#define PORTAAVIOES_H
#include <string>
using std::string;

class PortaAvioes{

public:
	PortaAvioes(int, string &, int, int);// construtor
	PortaAvioes();// construtor sobrecarregado
	PortaAvioes(const PortaAvioes &);// construtor de copia
    
	void setTripulacaoInicial(int);
    
	void adicionaTripulacao(int); // recebe um inteiro e adiciona à tripulacão do Porta Avioes
	void adicionaTripulacao();// nao recebe parametros então adiciona 1 à tripulacão do Porta Avioes

	void getTripulacaoQuantidade() const;

	void setNomeDoCapitao(string &);
	void getNomeDoCapitao() const; 
    
	void setAvioesDisponiveis(int);
	void getAvioesDisponiveis() const;
	
	void setDecolagensRealizadas(int);
	void getDecolagensRealizadas() const;

	static void getFrotaTotalAtiva();//metodo static
	
	Aviao hangar;

private:
	int tripulacaoQuantidade;
	int avioesDisponiveis;
	int decolagensRealizadas;
	string nomeDoCapitao;

	const int tripulacaoMaxima = 500;
	static int frotaTotalAtiva;
	static const int velocidadeMaxima;
	
	

};

#endif // PORTAAVIOES_H
