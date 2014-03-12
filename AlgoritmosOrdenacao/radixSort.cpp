/*
 * O Radix sort é um algoritmo de ordenação rápido e estável
 * que pode ser usado para ordenar itens que estão identificados por chaves únicas.
 * Cada chave pode ser uma cadeia de caracteres (ordem lexicografia) ou número.
 */

#include <iostream>
#include <cstdlib> // para uso da função hand()

/* 
 * Funções auxiliares
 */
	// função para gerar um vetor de forma aleatória
		 void geraArrayAleatorio(int v[], int N) {
		    srand(time(NULL));
		    // alocação de variável
		        int *i = new int;

		    for(*i = 0; *i < N; (*i)++)
		    	v[*i] = (rand() % 100);

		    // desalocação de variável
		        delete i;
		}
	// Função para imprimir vetores
		void imprimir(int v[], int n){
		    // alocação de variável
		        int *i = new int;

			for(*i = 0; *i < n; (*i)++)
				std::cout << v[*i] << " ";
			std::cout << "\n";

		    // desalocação de variável
		        delete i;
		}
	// Função preenche um vetor com 0 em todas as posições do vetor
		void preenche(int v[], int n){
			// alocação de variável
		        int *i = new int;

			for(*i = 0; *i < n; (*i)++)
				v[*i] = 0;

		    // desalocação de variável
		        delete i;
		}
// Radix Sort
	void radixSort(int v[], int n){
		// alocação das váriaveis
			int *i = new int; // para intereção nos laços
			int *maior = new int; // identifica qual é o maior número do vetor
			int *exp = new int; // usado para 
			int *b = new int[n]; // vetor auxiliar
		
		*exp = 1; // inicializando a variavel
		*maior = v[0]; // inicia o maior número com o primeiro elemento do vetor desordenado

		// busca pelo maior elemento do vetor
			for(*i = 1; *i < n; (*i)++){
				if(v[*i] > *maior) // testa se o elemento atual é maior que o maior atual
					*maior = v[*i];
			}
		// Ordenação
			while( (*maior / *exp) > 0 ){
				int *bucket = new int[10];
				for(*i = 0; *i < n; (*i)++)
					bucket[( v[*i]/ *exp) %10]++;

				for(*i = 1; *i < 10; (*i)++)
					bucket[*i] += bucket[*i - 1];

				for(*i = n-1; *i >= 0; (*i)--) {
					b[--bucket[(v[*i] / *exp) % 10]] = v[*i];
				}

				for(*i = 0; *i < n; (*i)++)
					v[*i] = b[*i];
				*exp *= 10;
			}
	}
int main(){
	int *v = new int[10];
	int *i = new int;

	geraArrayAleatorio(v, 10);
	
	imprimir(v,10);
	radixSort(v, 10);
	imprimir(v,10);

	return 0;
}