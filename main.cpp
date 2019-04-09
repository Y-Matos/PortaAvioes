#include "PortaAvioes.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

int main(){

	string nomeDoCapitao;
	
	cout << "Insira o nome do capitao: " << endl;
	getline(cin, nomeDoCapitao);

	PortaAvioes portaAviao1(10, nomeDoCapitao);
    
    portaAviao1.adicionaTripulacao(10);
    
    portaAviao1.adicionaTripulacao();
	
	return 0;
	
}