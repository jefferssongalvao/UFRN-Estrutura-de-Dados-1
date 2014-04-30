#include <iostream>
#include <cstdlib> // para uso da função system()

#include "menu.h"

// alguns metódos do namespace std
	using std::cout;
	using std::cin;

// menu do programa
	void menu(int op, int tam){
		system("clear");
		int *L = new int[tam];
		int pos, valor, *aux, busca;
		while(op != 7) {
			pos = tam;
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
					cout << "\nA lista tem tamanho " << tam << "\n\t[ ";
					for (int i = 0; i < tam; ++i){
						cout << L[i];
						if(i < tam-1)
							cout << ", ";
					}
					cout << " ]\n\n";
					break;
				case 2:
					while(pos < 0 || pos >= tam) {
						cout << "Digite uma posição: ";
							cin >> pos;
						if(pos < 0 || pos == tam) {
							system("clear");
							cout << "\nPosição inválida!\n\n";
						}
					}
					cout << "Digite um valor: ";
						cin >> valor;
					L[pos] = valor;
					break;
				case 3:
					while(pos < 0 || pos >= tam) {
						cout << "Digite uma posição: ";
							cin >> pos;
						if(pos < 0 || pos == tam) {
							system("clear");
							cout << "\nPosição inválida!\n\n";
						}
					}
					for (int i = pos; i < tam-1; ++i)
						L[i] = L[i+1];
					aux = new int[--tam];
					delete L;
					L = new int[tam];
					for (int i = 0; i < tam; ++i)
						L[i] = aux[i];
					delete aux;
					break;
				case 4:
					while(pos < 0 || pos >= tam) {
						cout << "Digite uma posição: ";
							cin >> pos;
						if(pos < 0 || pos == tam) {
							system("clear");
							cout << "\nPosição inválida!\n\n";
						}
					}
					cout << "\nO Elemento na posição " << pos << " é: " << L[pos] << ".\n\n";
					break;
				case 5:
					cout << "Digite um valor: ";
						cin >> valor;
						pos = -1;
						for(int i = 0; i < tam; i++){
							if(L[i] == valor) {
								pos = i;
								break;								
							}
						}
						if(pos >= 0)
							cout << "\nO valor " << valor << " foi achado na posição " << pos << " da lista.\n\n";
						else
							cout << "\nO valor " << valor << " não foi achado na lista.\n\n";
					break;
				case 6:
					delete [] L;
					L = new int[tam];
					cout << "\nA lista foi esvaziada!\n\n";
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