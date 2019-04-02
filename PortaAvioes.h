#ifndef PORTAAVIOES_H
#define PORTAAVIOES_H
#include <string>
using std::string;

class PortaAvioes
{
public:
    PortaAvioes(int);// construtor
    ~PortaAvioes();
    void defineTripulacaoInicial(int);
    void adicionaTripulacao(int);

private:
    int tripulacaoQuantidade;
};

#endif // PORTAAVIOES_H
