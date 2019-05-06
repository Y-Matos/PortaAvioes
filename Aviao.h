#ifndef AVIAO_H
#define AVIAO_H
#include <string>
using std::string;

class Aviao
{
public:
    Aviao(const string&, int, int);// Construtor que recebe todos os argumentos
	Aviao();// Construtor que não recebe nenhum dos argumentos
	Aviao(const Aviao &);// Construtor de copia
    ~Aviao();
    
	string setNomeDoAviao(const string &);
	int setVelocidadeMaxima(int);
	int setCapacidadeTanque(int);
	
    void getNomeDoAviao() const;
    void getVelocidadeMaxima() const;
    void getCapacidadeTanque() const;
    
    void info() const;

private:
    string nomeDoAviao;
    int velocidadeMaxima;
    int capacidadeTanque;
	
	const static int velocidadeDoSom = 1234;
};

#endif // AVIAO_H
