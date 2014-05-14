#include <iostream>
#include <cstdlib> // para uso da função system()

#include "menu.h"

// alguns metódos do namespace std
	using std::cout;
	using std::cin;

// função para copiar vetor
	int * copiar(int v[], int tam) {
	    int * aux = new int[tam];
	    for (int i = 0; i < tam; ++i)
	    	aux[i] = v[i];
	    return aux;
	}

// menu do programa
	void menu(int op){
		system("clear");
		int tam = 10, valor, *aux, topo = -1;
		int *pilha = new int[tam];
		while(op != 6) {
			cout << "EDITOR DE LISTAS\n";
			cout << "\t1 - EMPILHAR\n";
			cout << "\t2 - DESEMPILHAR\n";
			cout << "\t3 - EXIBIR ELEMENTO DO TOPO\n";
			cout << "\t4 - EXIBIR A PILHA\n";
			cout << "\t5 - ESVAZIAR A PILHA\n";
			cout << "\t6 - SAIR\n\n";
			cout << "DIGITE SUA OPÇÃO: ";
				cin >> op;
			system("clear");
			switch(op){
				case 1:
					if(topo == tam) {
						int *aux = new int[tam];int *pilha = new int[tam];
						aux = copiar(pilha, tam);
						delete [] pilha;
						int tamAux = tam;
						tam += 10;
						pilha = new int[tam];
						pilha = copiar(aux, tamAux);
						delete [] aux;
					}
					cout << "Digite um valor: ";
						cin >> valor;
					pilha[++topo] = valor;
					break;
				case 2:
					if(topo >= 0) {
						cout << "\nO elemento " << pilha[topo] << " foi desempilhado.\n\n";
						pilha[topo--] = 0;
					} else 
						cout << "\nA pilha está vazia!\n\n";	
					break;
				case 3:
					if(topo >= 0)
						cout << "\nO topo da pilha é " << pilha[topo] << "\n\n";
					else
						cout << "\nA pilha está vazia!\n\n";	
					break;
				case 4:
					if(topo >= 0) {
						cout << "A pilha é a seguinte:";
						for (int i = topo; i >= 0; --i) {
							if(i == topo)
								cout << "   |";
							else
								cout << "\t\t\t|";
							cout << pilha[i] << "|\n";
						}
						cout << "\n";
					} else 
						cout << "\nA pilha está vazia!\n\n";
					break;
				case 5:
					delete [] pilha;
					pilha = new int[tam];
					topo = -1;
					cout << "\nA pilha foi esvaziada!\n\n";
					break;
				case 6:
					cout << "\nAté a próxima!\n\n";
					break;
				default:
					cout << "\nOpção inválida!\n\n";
					break;
			}
		}
	}