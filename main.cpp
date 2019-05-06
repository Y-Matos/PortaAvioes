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
	
	//PortaAvioes *portaAviao1 = new PortaAvioes(10, nomeDoCapitao,5, 2);
	
	cout << "Imprimindo Info De Todas As Classes: " << endl;
	portaAviao1.info();// mostra o array agora com um valor atualizado;
	
	cout << "------------------------------------------------------------------------------------" << endl;
	
	PortaAvioes *ptrHangar = new PortaAvioes(15, "Jack Sparrow",8, 6); // Cria um Novo Objeto Porta Avioes
	
	cout << "Imprimindo Info De Todas As Classes: " << endl;
	ptrHangar->info();// mostgra o array agora com um valor atualizado;
	
	ptrHangar->getFrotaTotalAtiva(); // Mostra a Quantidade de Porta Avioes Que foram criados
	
	delete ptrHangar;
	cout << "\nPorta Avioes Deletado" << endl;
	
	ptrHangar->getFrotaTotalAtiva();
	
	return 0;
	
}