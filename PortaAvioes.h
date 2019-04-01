#ifndef PORTAAVIOES_H
#define PORTAAVIOES_H
#include <string>
using std::string;

class PortaAvioes
{
public:
    PortaAvioes();
    ~PortaAvioes();
    adicionaTripulacao(int novaTripulacao){
        tripulacaoQuantidade += novaTripulacao;
    }

private:
    int tripulacaoQuantidade;
};

#endif // PORTAAVIOES_H
