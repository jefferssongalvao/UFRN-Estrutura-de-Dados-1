/*
/*
 * O selection sort é um algoritmo de ordenação
 * baseado em se passar sempre o menor valor do vetor para a primeira posição
 * depois o de segundo menor valor para a segunda posição,
 * e assim é feito sucessivamente com os (n-1) elementos restantes, até os últimos dois elementos.
 */

#include <iostream>
#include <cstdlib> // para uso da função hand()
#include "funcoes.h" // biblioteca de funções auxiliares para essa aplicação

// Insertion Sort
	void insertionSort(int v[], int n){
		// alocação das váriaveis
			int *i   = new int;
			int *j   = new int;
			int *key = new int;

		//ordenação
            for (*i = 1; *i < n; (*i)++) {
                // considera o elemento i removido de A
                    *key = v[*i];
                    *j = *i - 1;
                while (*j >= 0 && *key < v[*j]){
                    // deslocando os elementos em B
                        v[*j+1] = v[*j];
                        (*j)--;
                }
                // insere o elemento na posição ordenada em B
                    v[*j+1] = *key;
            }

		// desalocação das váriaveis
			delete i;
			delete j;
			delete key;
	}

// programa principal
	int main(){
		// alocação das váriaveis
			int *v = new int[10];
			int *i = new int;

		geraArrayAleatorio(v, 10); // gerando array para o teste
		
		// teste de ordenação
			std::cout << "O vetor antes da ordenação: "; imprimir(v,10);
				insertionSort(v, 10);
			std::cout << "O vetor depois da ordenação: "; imprimir(v,10);

		// desalocação das váriaveis
			delete v;
			delete i;

		return 0;
	}