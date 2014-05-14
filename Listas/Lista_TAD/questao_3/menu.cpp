#include <iostream>
#include <cstdlib> // para uso da função system()

#include "menu.h"
#include "Lista.h"

// alguns metódos do namespace std
	using std::cout;
	using std::cin;

// menu do programa
	void menu(int op){
		system("clear");
		Lista *L = new Lista();
		int pos, valor, *aux, busca, tam;
		while(op != 7) {
			tam = L->getQtd();
			pos = tam + 1;
			cout << "EDITOR DE LISTAS\n";
			cout << "\t1 - EXIBIR LISTA\n";
			cout << "\t2 - INSERIR\n";
			cout << "\t3 - REMOVER\n";
			cout << "\t4 - EXIBIR ELEMENTO\n";
			cout << "\t5 - EXIBIR POSIÇÃO\n";
			cout << "\t6 - ESVAZIAR\n";
			cout << "\t7 - SAIR\n\n";
			cout << "DIGITE SUA OPÇÃO: ";
				cin >> op;
			system("clear");
			switch(op){
				case 1:
					if(tam > 0)
						L->exibir();
					else
						cout << "\nA lista está vázia!\n\n";
					break;
				case 2:
					while(pos < 0 || pos > tam) {
						cout << "Digite uma posição: ";
							cin >> pos;
						if(pos < 0 || pos > tam) {
							system("clear");
							cout << "\nPosição inválida!\n\n";
						}
					}
					cout << "Digite um valor: ";
						cin >> valor;
					L->inserir(valor, pos);
					break;
				case 3:
					while(pos < 0 || pos > tam) {
						cout << "Digite uma posição: ";
							cin >> pos;
						if(pos < 0 || pos > tam) {
							system("clear");
							cout << "\nPosição inválida!\n\n";
						}
					}
					L->remover(pos);
					break;
				case 4:
					if(tam > 0) {
						while(pos < 0 || pos >= tam) {
							cout << "Digite uma posição: ";
								cin >> pos;
							if(pos < 0 || pos >= tam) {
								system("clear");
								cout << "\nPosição inválida!\n\n";
							}
						}
						L->mostrarEle(pos);
					} else {
						cout << "\nA lista está vázia!\n\n";
					}
					break;
				case 5:
					if(tam > 0) {
						cout << "Digite um valor: ";
							cin >> valor;
							L->mostrarPos(valor);
					} else {
						cout << "\nA lista está vázia!\n\n";
					}
					break;
				case 6:
					if(tam > 0)
						L->esvaziar();
					else
						cout << "\nA lista já está vazia!\n\n";
					break;
				case 7:
					cout << "\nAté a próxima!\n\n";
					break;
				default:
					cout << "\nOpção inválida!\n\n";
					break;
			}
		}
	}