#include "Hangar.h"
#include "Aviao.h"

#ifndef PORTAAVIOES_H
#define PORTAAVIOES_H

#include <string>
using std::string;

class PortaAvioes
{

	friend void callCadastroHangar(const string &nomeModelo, const int indice){
		hangarPrincipal.cadastraTipoDeAviao(const string &nomeModelo, const int indice);
	}
	
public:
	PortaAvioes(int,const string &, int, int); // Construtor que recebe todos os argumentos
	PortaAvioes(); // Construtor que não recebe nenhum dos argumentos
	PortaAvioes(const PortaAvioes &);// Construtor de copia
	~PortaAvioes();

	void setTripulacaoInicial(int);
    
	void adicionaTripulacao(int); // recebe um inteiro e adiciona à tripulacão do Porta Avioes
	void adicionaTripulacao();// nao recebe parametros então adiciona 1 à tripulacão do Porta Avioes

	void getTripulacaoQuantidade() const;

	void setNomeDoCapitao(const string &);
	void getNomeDoCapitao() const; 
    
	void setAvioesDisponiveis(int);
	void getAvioesDisponiveis() const;
	
	void setDecolagensRealizadas(int);
	void getDecolagensRealizadas() const;

	static void getFrotaTotalAtiva();//metodo static
	
	void info() const;

private:
	
	Hangar hangarPrincipal;
	Aviao aviaoTeste;
	
	
	int tripulacaoQuantidade;
	int avioesDisponiveis;
	int decolagensRealizadas;
	string nomeDoCapitao;

	static const int tripulacaoMaxima = 500;
	static int frotaTotalAtiva;
	static const int velocidadeMaxima;
	
    
    
};

#endif // PORTAAVIOES_H
