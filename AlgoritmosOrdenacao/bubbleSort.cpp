/*
 * O bubble sort é um algoritmo de ordenação dos mais simples.
 * A ideia é percorrer o vector diversas vezes,
 * a cada passagem fazendo flutuar para o topo o maior elemento da sequência.
 * Essa movimentação lembra a forma como as bolhas em um tanque de água procuram seu próprio nível,
 * e disso vem o nome do algoritmo.
 */

#include <iostream>
#include <cstdlib> // para uso da função hand()
#include "funcoes.h" // biblioteca de funções auxiliares para essa aplicação

// Bubble Sort
	void bubbleSort(int v[], int n){
		// alocação das váriaveis
			int *i   = new int;
			int *j   = new int;
			int *aux = new int; // aux para troca de posições

		//ordenação
			for(*i = 0; *i < n; (*i)++){
				for(*j = *i+1; *j < n; (*j)++){
					if(v[*i] > v[*j]) { // verifica quem é o maior e troca se for o primeiro
						*aux    = v[*i];
						v[*i]   = v[*j];
						v[*j] = *aux;
					}
				}
			}

		// desalocação das váriaveis
			delete i;
			delete j;
			delete aux;
	}

// programa principal
	int main(){
		// alocação das váriaveis
			int *v = new int[10];
			int *i = new int;

		geraArrayAleatorio(v, 10); // gerando array para o teste
		
		// teste de ordenação
			std::cout << "O vetor antes da ordenação: "; imprimir(v,10);
				bubbleSort(v, 10);
			std::cout << "O vetor depois da ordenação: "; imprimir(v,10);

		// desalocação das váriaveis
			delete v;
			delete i;

		return 0;
	}