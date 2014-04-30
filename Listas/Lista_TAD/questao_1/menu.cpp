#include <iostream>
#include <cstdlib> // para uso da função system()

#include "Conta.h"
#include "Contas.h"

#include "menu.h"

// alguns metódos do namespace std
	using std::cout;
	using std::cin;

// menu do programa
	void menu(int op, Contas * banco){
		int conta;
		double valor, saldo;
		system("clear");
		while(op != 6){
			cout << "Menu de opções:\n";
			cout << "\tNovo Conta................................1\n";
			cout << "\tListar Contas.............................2\n";
			cout << "\tDeposito..................................3\n";
			cout << "\tSaque.....................................4\n";
			cout << "\tSaldo.....................................5\n";
			cout << "\tSair do programa..........................6\n";
			cout << "Digite a opção: ";
				cin >> op;
			system("clear");
			switch(op){
				case 1:
					cout << "Digite o Saldo Inicial do Cliente: ";
						cin >> saldo;
					banco->inserir(saldo);
					break;
				case 2:
					if(banco->getQtd() != 0) {
						banco->listarContas();
					} else {
						system("clear");
						cout << "Não existem clientes!\n";
					}
					break;
				case 3:
					if(banco->getQtd() != 0) {
						conta = banco->getQtd() + 1;
						while(conta > banco->getQtd() || conta < 1) {
							cout << "Digite a conta do cliente: ";
								cin >> conta;
							if(conta > banco->getQtd() || conta < 1) {
								system("clear");
								cout << "Conta inválida!\n";
							}
						}
						cout << "Digite o valor do deposito: ";
							cin >> valor;
						banco->deposito(valor, conta);
					} else{
						system("clear");
						cout << "Não existem clientes!\n";
					}
					break;
				case 4:
					if(banco->getQtd() != 0) {
						conta = banco->getQtd() + 1;
						while(conta > banco->getQtd() || conta < 1) {
							cout << "Digite a conta do cliente: ";
								cin >> conta;
							if(conta > banco->getQtd() || conta < 1) {
								system("clear");
								cout << "Conta inválida!\n";
							}
						}
						cout << "Digite o valor do saque: ";
							cin >> valor;
						banco->saque(valor, conta);
					} else{
						system("clear");
						cout << "Não existem clientes!\n";
					}
					break;
				case 5:
					if(banco->getQtd() != 0) {
						conta = banco->getQtd() + 1;
						while(conta > banco->getQtd() || conta < 1) {
							cout << "Digite a conta do cliente: ";
								cin >> conta;
							if(conta > banco->getQtd() || conta < 1) {
								system("clear");
								cout << "Conta inválida!\n";
							}
						}
						banco->saldoConta(conta);
					} else{
						system("clear");
						cout << "Não existem clientes!\n";
					}
					break;
				case 6:
					cout<< "\nAté a próxima!\n\n";
					break;
				default:
					cout << "\nOpção inválida!\n\n";
					break;
			}
		}
	}