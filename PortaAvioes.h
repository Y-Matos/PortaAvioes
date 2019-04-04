#ifndef PORTAAVIOES_H
#define PORTAAVIOES_H

#include <string>
using std::string;

class PortaAvioes
{
public:
    PortaAvioes(int);// construtor
    PortaAvioes();
    ~PortaAvioes();
    void defineTripulacaoInicial(int);
    void adicionaTripulacao(int); // recebe um inteiro e adiciona à tripulacão do Porta Avioes
    void adicionaTripulacao();
    
private:
    int tripulacaoQuantidade;
};

#endif // PORTAAVIOES_H
