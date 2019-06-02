#ifndef AVIAO_H
#define AVIAO_H
#include <string>
using std::string;

using std::ostream;

class Aviao
{
	friend ostream &operator<< (ostream &output, const Aviao&); // Imprime Dados do Avião
public:
    Aviao(const string&, int, int);// Construtor que recebe todos os argumentos
	Aviao();// Construtor que não recebe nenhum dos argumentos
	Aviao(const Aviao &);// Construtor de copia
    ~Aviao();
    
	void info(int) const;
	
	void setNomeDoAviao(const string &);
	void setVelocidadeMaxima(int);
	void setCapacidadeTanque(int);
	
    string getNomeDoAviao() const;
    int getVelocidadeMaxima() const;
    int getCapacidadeTanque() const;

	//---------------- SOBRECARGA DE OPERADORES -----------------
	
	const Aviao &operator= (const Aviao&); // copia um avião para outro
	bool operator == (const Aviao&) const; // testa se aviões são iguais
	bool operator != (const Aviao&) const; // testa se aviões são diferentes
	bool operator < (const Aviao &origem) const; // testa se um avião é mais lento que outro
	bool operator > (const Aviao &origem) const; // testa se um avião é mais rápido que outro
	
private:
    string nomeDoAviao;
    int velocidadeMaxima;
    int capacidadeTanque;
	
	const static int VELOCIDADEDOSOM = 1234;
};

#endif // AVIAO_H