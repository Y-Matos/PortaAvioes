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

	void setTripulacaoInicial(int);
    
	void adicionaTripulacao(int); // recebe um inteiro e adiciona à tripulacão do Porta Avioes
	void adicionaTripulacao();// nao recebe parametros então adiciona 1 à tripulacão do Porta Avioes

	void getTripulacaoQuantidade() const;

	void setNomeDoCapitao(const string &);
	void getNomeDoCapitao() const; 
	
	void setNovoTenente(const string &);
    void getTenentes() const;
	
	void setAvioesDisponiveis(int);
	void getAvioesDisponiveis() const;
	
	void setDecolagensRealizadas(int);
	void getDecolagensRealizadas() const;

	static void getFrotaTotalAtiva();//metodo static
	
	void atualizaHangar(Hangar*); // Metodo que recebe ponteiro da Classe Hangar 
	void cadastraTipoDeAviao(const string &);
	
	void info() const;
	
	
private:
	
	Hangar hangarPrincipal;
	Aviao aviaoTeste;
	
	Hangar *ponteiroHangar;
	Aviao *ponteiroAviao;
	
	int tripulacaoQuantidade;
	int avioesDisponiveis;
	int decolagensRealizadas;
	string nomeDoCapitao;

	static const int TRIPULACAOMAXIMA;
	static int frotaTotalAtiva;
	static const int VELOCIDADEMAXIMA;
	
	static const int NUMDETENENTES = 3;
    static string nomeDosTenentes[NUMDETENENTES];

};

#endif // PORTAAVIOES_H
