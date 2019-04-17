#include "PortaAvioes.h"
#include "Aviao.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

int main(){

	string nomeDoCapitao;
	string nomeModelo = "";
	int numModelo;
	
	cout << "Insira o nome do capitao: " << endl;
	getline(cin, nomeDoCapitao);
	
	PortaAvioes portaAviao1(10, nomeDoCapitao,5, 2);
	
	PortaAvioes::getFrotaTotalAtiva();// usando metodo static no main
	
	portaAviao1.hangar.getTiposDeAviao();//mostra os valores do array da classe aviao
	
	cout << "Insira o numero do Modelo a ser atualizado: " << endl;
	cin >> numModelo;
	cout << "Insira o nome do Modelo a ser atualizado: " << endl;
	cin >> nomeModelo;
	portaAviao1.hangar.setTiposDeAviao(numModelo,nomeModelo);// recebe o numero do modelo e o nome a ser alterado;
	
	portaAviao1.hangar.getTiposDeAviao();// mostra o array agora com um valor atualizado;
	
	return 0;
	
}