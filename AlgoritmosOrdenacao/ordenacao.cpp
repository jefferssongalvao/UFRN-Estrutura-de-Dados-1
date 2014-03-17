#include <iostream>
#include "../includes/funcoes_ordenacao.h" // biblioteca de funções auxiliares para essa aplicação
#include "radixSort_recursivo.cpp"

// programa principal
	int main(){
		// alocação das váriaveis
			int *v = new int[10];
			int *i = new int;

		geraArrayAleatorio(v, 10); // gerando array para o teste
		
		// teste de ordenação
			std::cout << "O vetor antes da ordenação: "; imprimir(v,10);
				ordena(v, 10);
			std::cout << "O vetor depois da ordenação: "; imprimir(v,10);

		// desalocação das váriaveis
			delete v;
			delete i;

		return 0;
	}