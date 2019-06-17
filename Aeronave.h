#ifndef AERONAVE_H
#define AERONAVE_H
#include <iostream>
using std::cout;

#include <string>
using std::string;

using std::ostream;

class Aeronave
{
public:
	friend ostream &operator<< (ostream &output, const Aeronave&); // Imprime Dados do Avião
public:
    Aeronave(const string&, int, int);// Construtor que recebe todos os argumentos
	Aeronave();// Construtor que não recebe nenhum dos argumentos
	Aeronave(const Aeronave &);// Construtor de copia
    virtual ~Aeronave();
    
	void info(int) const;
	
	void setNomeDaAeronave(const string &);
	void setVelocidadeMaxima(int);
	void setCapacidadeTanque(int);
	
    string getNomeDaAeronave() const;
    int getVelocidadeMaxima() const;
    int getCapacidadeTanque() const;

	//---------------- SOBRECARGA DE OPERADORES -----------------
	
	const Aeronave &operator= (const Aeronave&); // copia uma aeronave para outra
	bool operator == (const Aeronave&) const; // testa se aeronaves são iguais
	bool operator != (const Aeronave&) const; // testa se aeronaves são diferentes
	bool operator < (const Aeronave &origem) const; // testa se uma aeronave é mais lenta que outra
	bool operator > (const Aeronave &origem) const; // testa se uma aeronave é mais rápida que outra
	
private:
    string nomeDaAeronave;
    int velocidadeMaxima;
    int capacidadeTanque;
	
	const static int VELOCIDADEDOSOM = 1234;
};

#endif // AERONAVE_H
