#ifndef PORTAAVIOES_H
#define PORTAAVIOES_H
#include <string>
using std::string;

class PortaAvioes{

public:
    PortaAvioes(int, string &);// construtor
    PortaAvioes();// construtor sobrecarregado
    
    void setTripulacaoInicial(int);
    
	void adicionaTripulacao(int); // recebe um inteiro e adiciona à tripulacão do Porta Avioes
    void adicionaTripulacao();// nao recebe parametros então adiciona 1 à tripulacão do Porta Avioes

	const void getTripulacaoQuantidade();

	void setNomeDoCapitao(string &);
	const void getNomeDoCapitao(); 
    
private:
    int tripulacaoQuantidade;
	int avioesDisponiveis;
	int decolagensRealizadas;
	string nomeDoCapitao;

};

#endif // PORTAAVIOES_H
