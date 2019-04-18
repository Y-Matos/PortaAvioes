#ifndef AVIAO_H
#define AVIAO_H
#include <string>
using std::string;

class Aviao
{
public:
    Aviao();
    ~Aviao();
    
    void getNomeDoAviao() const;
    void getVelocidadeMaxima() const;
    void getCapacidadeTanque() const;
    
    void info() const;

private:
    string nomeDoAviao;
    int velocidadeMaxima;
    int capacidadeTanque;
};

#endif // AVIAO_H
