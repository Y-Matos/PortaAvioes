#include "PortaAvioes.h"
#include "Hangar.h"

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
	
	PortaAvioes portaAviao1(10, nomeDoCapitao,5, 2);
	
	cout << "Imprimindo Info De Todas As Classes: " << endl;
	portaAviao1.info();// mostra o array agora com um valor atualizado;
	
	return 0;
	
}