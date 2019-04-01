#ifndef PORTAAVIOES_H
#define PORTAAVIOES_H
#include <string>
using std::string;

class PortaAvioes
{
public:
    PortaAvioes();
    ~PortaAvioes();
    int adicionaTripulacao(int novaTripulacao){
        tripulacaoQuantidade += novaTripulacao;
        
        return tripulacaoQuantidade;
    }

private:
    int tripulacaoQuantidade;
};

#endif // PORTAAVIOES_H
