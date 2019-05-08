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
	portaAviao1.cadastraTipoDeAviao("JATO ATAQUE");
	portaAviao1.cadastraTipoDeAviao("JATO BOMBARDEIRO");
	
	portaAviao1.setNovoTenente("Henry Avery");
	portaAviao1.setNovoTenente("Nathan Drake");
	
	cout << "Imprimindo Info De Todas As Classes: " << endl;
	portaAviao1.info();// mostra o array agora com um valor atualizado;
	
	
	cout << "------------------------------------------------------------------------------------" << endl;
	
	PortaAvioes *ptrPortaAvioes = new PortaAvioes(15, "Jack Sparrow",8, 6); // Cria um Novo Objeto Porta Avioes
	Hangar *ptrNovoHangar = new Hangar("Jato Ataque","Jato Bombardeio","Aviao Resgate","Aviao Reconhecimento","Aviao Transporte");
	
	ptrPortaAvioes->atualizaHangar(ptrNovoHangar);
	delete ptrNovoHangar;
	
	cout << "Imprimindo Info De Todas As Classes: " << endl;
	ptrPortaAvioes->info();// mostgra o array agora com um valor atualizado;
	
	ptrPortaAvioes->getFrotaTotalAtiva(); // Mostra a Quantidade de Porta Avioes Que foram criados
	
	delete ptrPortaAvioes;
	cout << "\nPorta Avioes Deletado" << endl;
	
	
	ptrPortaAvioes->getFrotaTotalAtiva();
	
	
	
	
	return 0;
	
}