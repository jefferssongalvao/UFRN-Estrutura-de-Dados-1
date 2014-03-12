/*
 * O selection sort é um algoritmo de ordenação
 * baseado em se passar sempre o menor valor do vetor para a primeira posição
 * depois o de segundo menor valor para a segunda posição,
 * e assim é feito sucessivamente com os (n-1) elementos restantes, até os últimos dois elementos.
 */

#include <iostream>
#include <cstdlib> // para uso da função hand()
#include "funcoes.h" // biblioteca de funções auxiliares para essa aplicação

// Selection Sort
	void selectionSort(int v[], int n){
		// alocação das váriaveis
			int *i   = new int;
			int *j   = new int;
			int *aux = new int; // aux para troca de posições
			int *min = new int; // posição do menor número na faixa do vetor

		//ordenação
			for(*i = 0; *i < n; (*i)++){
				*min = *i; // pega o inicio da faixa do vetor
				for(*j = *i; *j < n; (*j)++){
					// verifica qual a posição do menor número da faixa do vetor
						if(v[*j] < v[*min])
							*min = *j;
				}
				if(*i != *min) { // se a posição mudou da inicial fará a troca
					*aux    = v[*i];
					v[*i]   = v[*min];
					v[*min] = *aux;
				}
			}

		// desalocação das váriaveis
			delete i;
			delete j;
			delete aux;
			delete min;
	}

// programa principal
	int main(){
		// alocação das váriaveis
			int *v = new int[10];
			int *i = new int;

		geraArrayAleatorio(v, 10); // gerando array para o teste
		
		// teste de ordenação
			std::cout << "O vetor antes da ordenação: "; imprimir(v,10);
				selectionSort(v, 10);
			std::cout << "O vetor depois da ordenação: "; imprimir(v,10);

		// desalocação das váriaveis
			delete v;
			delete i;

		return 0;
	}