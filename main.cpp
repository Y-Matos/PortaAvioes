#include "PortaAvioes.h"
#include "Hangar.h"

#include <iostream>
using std::cout;
using std::cin;

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
				portaAvioes->info();
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
				
				portaAvioes->getTenentes();
				
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
	
	
	return 0;
	
}