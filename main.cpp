#include "PortaAvioes.h"
#include "Hangar.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

void menuAlteracoes(int &escolha, PortaAvioes *&portaAvioes)
{
		cout << "------- SISTEMA DE CONTROLE - PORTA AVIOES -------" << "\n";
		cout << "---------------- ALTERAR DADOS -------------------" << "\n\n";

		cout << "\t" << "1 - Alterar Nome do Capitao "      << "\n";
		cout << "\t" << "2 - Alterar Numero de Pilotos Disponiveis" << "\n";
		cout << "\t" << "3 - Alterar Capacidade De Avioes"  << "\n";
		cout << "\t" << "4 - Alterar Numero de Tripulantes" << "\n";
		cout << "\t" << "5 - Retornar ao Menu Principal"    << "\n";
		cout << "Selecione uma opcao para avancar: ";
		cin >> escolha;
		
		system("cls");
		
		switch (escolha)
		{
			case 1:
			{
				string novoNome;
				cout << "------- SISTEMA DE CONTROLE - PORTA AVIOES -------" << "\n";
				cout << "---------------- ALTERAR DADOS -------------------" << "\n";
				cout << "--------------- ALTERAR CAPITAO ------------------" << "\n\n";
				
				portaAvioes->getNomeDoCapitao();
				
				cout << "\n" << "Insira o Nome Do Novo Capitao: ";
				cin.ignore();
				getline(cin, novoNome);
				
				portaAvioes->setNomeDoCapitao(novoNome);
				
				cout << "Capitao Alterado com Sucesso" << "\n\n";
				system("Pause");
				system("cls");
				break;
			}
			case 2:
			{
				int qtePilotos = 0;
				cout << "------- SISTEMA DE CONTROLE - PORTA AVIOES -------" << "\n";
				cout << "---------------- ALTERAR DADOS -------------------" << "\n";
				cout << "---------- ALTERAR NUMERO DE PILOTOS -------------" << "\n\n";
				
				portaAvioes->getPilotosDisponiveis();
				
				cout << "\n" << "Insira A Nova Quantidade De Pilotos: ";
				cin >> qtePilotos;
				
				portaAvioes->setPilotosDisponiveis(qtePilotos);
				
				cout << "Quantidade De Pilotos Alterada com Sucesso" << "\n\n";
				system("Pause");
				system("cls");
				break;
			}
			case 3:
			{
				int novaCapacidade = 0;
				cout << "------- SISTEMA DE CONTROLE - PORTA AVIOES -------" << "\n";
				cout << "---------------- ALTERAR DADOS -------------------" << "\n";
				cout << "-------------- ALTERAR CAPACIDADE ----------------" << "\n\n";
				
				portaAvioes->getCapacidade();
				
				cout << "\n" << "Insira A Nova Capacidade De Avioes: ";
				cin >> novaCapacidade;
				
				portaAvioes->setCapacidade(novaCapacidade);
				
				cout << "Capacidade De Avioes Alterada com Sucesso" << "\n\n";
				system("Pause");
				system("cls");
				break;
			}
			case 4:
			{
				int novoNumTripulantes = 0;
				cout << "------- SISTEMA DE CONTROLE - PORTA AVIOES -------" << "\n";
				cout << "---------------- ALTERAR DADOS -------------------" << "\n";
				cout << "------------- ALTERAR TRIPULACAO -----------------" << "\n\n";
				
				portaAvioes->getTripulacaoQuantidade();
				
				cout << "\n" << "Insira O Novo Numero de Tripulantes: ";
				cin >> novoNumTripulantes;
				
				portaAvioes->setTripulacao(novoNumTripulantes);
				
				cout << "Numero de Tripulantes Alterado com Sucesso" << "\n\n";
				system("Pause");
				system("cls");
				break;
			}
			case 5:
				break;
			default:
				cout << "\n ATENCAO : Opcao invalida selecionada. Por favor selecione uma das opcoes. \n" << "\n";
				system("PAUSE");
				break;
		}
}

void menuPrincipal(int &escolha, PortaAvioes *&portaAvioes)
{
		system("cls");
		
				
		cout << "------- SISTEMA DE CONTROLE - PORTA AVIOES -------" << "\n";
		cout << "---------------- MENU PRINCIPAL ------------------\n" << "\n";
		cout << "\n\t" << "1 - Acessar Info Porta Avioes" << "\n";
		cout << "\t" << "2 - Alterar Info Porta Avioes" << "\n";
		cout << "\t" << "3 - Adicionar Novo Tenente" << "\n";
		cout << "\t" << "4 - Cadastrar Novo Tipo de Aviao no Hangar" << "\n";
		cout << "\t" << "5 - Cadastrar Novo Aviao" << "\n";
		cout << "\t" << "6 - Finalizar Programa\n" << "\n";
		
		cout << "Selecione uma opcao para avancar: ";
		cin >> escolha;
		
		system("cls");
		
		switch (escolha)
		{
			case 1:
			{
				cout << *portaAvioes << "/n";
				system("PAUSE");
				break;
			}
			case 2:
			{
				do{
		
					menuAlteracoes(escolha, portaAvioes );
		
				}while(escolha!=5);
				
				break;
			}
			case 3:
			{
				string novoTenente;
				cout << "------- SISTEMA DE CONTROLE - PORTA AVIOES -------" << "\n";
				cout << "---------------- MENU TENENTES -------------------" << "\n";
				
				portaAvioes->listaTenentes();
				
				cout << "\n" << "Insira o Nome do Novo Tenente: ";
				cin.ignore();
				getline(cin, novoTenente);
				
				portaAvioes->setNovoTenente(novoTenente);
				
				cout << "Novo Tenente Adicionado com Sucesso" << "\n\n";
				system("Pause");
				system("cls");
				break;
			}
			case 4:
			{
				string novoTipo;
				cout << "------- SISTEMA DE CONTROLE - PORTA AVIOES -------" << "\n";
				cout << "---------------- CONTROLE HANGAR -------------------" << "\n";
				cout << "-------------- CADASTRAR NOVO TIPO -----------------" << "\n\n";
				
				portaAvioes->getTiposDeAviao();
				
				cout << "\n" << "Insira o Nome do Novo Tipo De Aviao: ";
				cin.ignore();
				getline(cin, novoTipo);
				
				portaAvioes->cadastraTipoDeAviao(novoTipo);
				
				cout << "Novo Tipo De Aviao Adicionado com Sucesso" << "\n\n";
				system("Pause");
				system("cls");
				break;
			}
			case 5:
			{
				string nomeAviao;
				int velocidadeMaxima = 0;
				int capacidadeTanque = 0;
				cout << "------- SISTEMA DE CONTROLE - PORTA AVIOES -------" << "\n";
				cout << "---------------- CONTROLE HANGAR -------------------" << "\n";
				cout << "-------------- CADASTRAR NOVO TIPO -----------------" << "\n\n";
				
				portaAvioes->getListaAvioes();
				
				cout << "\n" << "Insira o Nome do Novo Aviao: ";
				cin.ignore();
				getline(cin, nomeAviao);
				
				cout << "\n" << "Insira a Velocidade Maxima do Aviao: ";
				cin >> velocidadeMaxima;
				cout << "\n" << "Insira a Capacidade do Tanque do Aviao: ";
				cin >> capacidadeTanque;
				
				Aviao *novoAviao = new Aviao(nomeAviao, velocidadeMaxima, capacidadeTanque);
				
				portaAvioes->adicionaNovoAviao(*novoAviao);
				
				delete novoAviao;
				
				cout << "Novo Aviao Adicionado com Sucesso" << "\n\n";
				system("Pause");
				system("cls");
				break;
			}
			case 6:
				break;
			
			default:
				cout << "\n ATENCAO : Opcao invalida selecionada. Por favor selecione uma das opcoes. \n" << "\n";
				system("PAUSE");
				break;
		}
}

int main()
{
	int escolha = 0;

	string nomeDoCapitao;
	int tripulacaoQuantidade;
	int pilotosDisponiveis;
	int capacidade;
	
// --------------- INICIANDO O PORTA AVIOES ---------------------------------------------------------------------------------------------------------------
	
	cout << "------- SISTEMA DE CONTROLE - PORTA AVIOES -------" << "\n";
	cout << "----------- CADASTRO DE PORTA AVIOES -------------\n" << "\n";
	
	cout << "Insira A Tripulacao Inicial do Novo Porta Avioes: " ;
	cin  >> tripulacaoQuantidade;
	
	cout << "Insira O Nome do Capitao do Novo Porta Avioes: ";
	cin.ignore();
	getline(cin, nomeDoCapitao);
	
	cout << "Insira A Quantidade de Pilotos Inicial do Novo Porta Avioes: ";
	cin  >> pilotosDisponiveis;
	
	cout << "Insira A Quantidade De Avioes Suportada Inicial do Novo Porta Avioes: ";
	cin  >>capacidade;
	
	PortaAvioes* ptrPortaAvioes = new PortaAvioes(tripulacaoQuantidade,nomeDoCapitao,pilotosDisponiveis,capacidade);
	
// --------------- PORTA AVIOES INICIADO E PONTEIRO CRIADO ---------------------------------------------------------------------------------------------------------------
	
	system("cls");
	
	
	do{
		
		menuPrincipal(escolha, ptrPortaAvioes );
		
	}while(escolha!=6);
	
	cout << "Programa Finalizado. " << "\n";
	
	delete ptrPortaAvioes;
	
	/*----------- Testa Desigualdade Porta Aviao-------------
	PortaAvioes portaAviao(10,"John",5,3);
	PortaAvioes portaAviao2;
	
	portaAviao2 = portaAviao;
	
	cout << "PAviao 1 != PAviao 2 ? = " << (portaAviao != portaAviao2) << endl;
	
	//-----------------------------------------------*/
	
	/*----------- Testa Igualdade Porta Aviao----------------
	PortaAvioes portaAviao(10,"John",5,3);
	PortaAvioes portaAviao2;
	
	portaAviao2 = portaAviao;
	
	cout << "PAviao 1 == PAviao 2 ? = " << (portaAviao == portaAviao2) << endl;
	
	//-----------------------------------------------*/
	
	/*----------- Testa Desigualdade Aviao-------------------
	Aviao aviao1("TomaHawk",18749,4742);
	Aviao aviao2("BlackBird",15589,6447);
	Aviao aviao3;
	aviao3 = aviao1;
	
	cout << "Aviao 1 != aviao 2 ? = " << (aviao1 != aviao2) << endl;
	cout << "Aviao 3 != aviao 1 ? = " << (aviao3 != aviao1) << endl;
	cout << "Aviao 3 != aviao 2 ? = " << (aviao3 != aviao2) << endl;
	//-----------------------------------------------*/
	
	/*----------- Testa Igualdade Aviao----------------------
	Aviao aviao1("TomaHawk",18749,4742);
	Aviao aviao2("BlackBird",15589,6447);
	Aviao aviao3;
	aviao3 = aviao1;
	
	cout << "Aviao 1 == aviao 2 ? = " << (aviao1 == aviao2) << endl;
	cout << "Aviao 3 == aviao 1 ? = " << (aviao3 == aviao1) << endl;
	cout << "Aviao 3 == aviao 2 ? = " << (aviao3 == aviao2) << endl;
	//-----------------------------------------------*/

	/*----------- Testa Desigualdade Hangar------------------
	Hangar hangar1;
	Hangar hangar2;
	
	hangar1.setTipoDeAviao("Ataque");
	
	hangar2 = hangar1;
	
	hangar1.setTipoDeAviao("Defesa");	
	hangar2.setTipoDeAviao("Chopper");
	
	cout << hangar1 << hangar2;
	
	cout << "Hangar 1 != HangarHangar 2 ? = " << (hangar1 != hangar2) << endl;	
	//-----------------------------------------------*/
	
	/*----------- Testa Igualdade Hangar-------------
	Hangar hangar1;
	Hangar hangar2;
	
	hangar1.setTipoDeAviao("Ataque");
	
	hangar2 = hangar1;
	
	hangar1.setTipoDeAviao("Defesa");	
	hangar2.setTipoDeAviao("Chopper");
	
	cout << hangar1 << hangar2;
	
	cout << "Hangar 1 == HangarHangar 2 ? = " << (hangar1 == hangar2) << endl;	
	//-----------------------------------------------*/
	
	/*----------- Testa [] Hangar-------------
	Hangar hangar1;
	Hangar hangar2;
	
	hangar1.setTipoDeAviao("Ataque");
	
	hangar2 = hangar1;
	
	hangar1.setTipoDeAviao("Defesa");	
	hangar2.setTipoDeAviao("Chopper");
	
	cout << hangar1 << hangar2;
	
	cout << "Hangar 1 == HangarHangar 2 ? = " << (hangar1 == hangar2) << endl;	
	
	cout << "\nHangar 1 \n" << "Classe - " << hangar1[10] << "\n";
	//-----------------------------------------------*/
	
	/*----------- Testa [] Porta Aviao----------------
	PortaAvioes portaAviao(10,"John",5,3);
	portaAviao.setNovoTenente("Joaquim");
	portaAviao.setNovoTenente("Joao");
	portaAviao.setNovoTenente("Jose");
	portaAviao.setNovoTenente("Yuri");
	
	cout << "Tenente 4 = " << portaAviao[3] << endl;
	cout << "Tenente 2 = " << portaAviao[1] << endl;
	cout << "Tenente 3 = " << portaAviao[2] << endl;
	cout << "Tenente 6 = " << portaAviao[6] << endl;
	
	//-----------------------------------------------*/
	
	/*----------- Testa < e > Aviao----------------------
	Aviao aviao1("TomaHawk",4300,4742);
	Aviao aviao2("BlackBird",6741,6447);
	Aviao aviao3;
	aviao3 = aviao1;
	
	cout << "Velocidade Maxima: " << aviao1.getVelocidadeMaxima() << " Km/h - Nome : " << aviao1.getNomeDoAviao() << " - Tanque:" << aviao1.getCapacidadeTanque();
	cout << "\n";
	cout << "Velocidade Maxima: " << aviao2.getVelocidadeMaxima() << " Km/h - Nome : " << aviao2.getNomeDoAviao() << " - Tanque:" << aviao2.getCapacidadeTanque();
	cout << "\n";
	cout << "Velocidade Maxima: " << aviao3.getVelocidadeMaxima() << " Km/h - Nome : " << aviao3.getNomeDoAviao() << " - Tanque:" << aviao3.getCapacidadeTanque();
	cout << "\n";
	
	cout << "Aviao 1 > aviao 2 ? = " << (aviao1 > aviao2) << endl;
	cout << "Aviao 3 < aviao 1 ? = " << (aviao3 < aviao1) << endl;
	cout << "Aviao 3 < aviao 2 ? = " << (aviao3 < aviao2) << endl;
	//-----------------------------------------------*/
	
	return 0;
	
}