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
			int *exp = new int; // variável usada para calcular o digito da vez
			int *b = new int[n]; // vetor auxiliar
		
		*exp = 1; // inicializando a variavel
		*maior = v[0]; // inicia o maior número com o primeiro elemento do vetor desordenado

		// busca pelo maior elemento do vetor
			for(*i = 1; *i < n; (*i)++){
				if(v[*i] > *maior) // testa se o elemento atual é maior que o maior atual
					*maior = v[*i];
			}
		// vetor auxiliar que guarda a quantidade referente ao digito
			int *bucket = new int[10];

		// Ordenação
			while( (*maior / *exp) > 0 ){

				// laço para incrementar a posição do digito do elemento do vetor v
					for(*i = 0; *i < n; (*i)++)
						bucket[( v[*i]/ *exp) %10]++;

				// laço para guardar na posição do digito quantos números tem dessa posição para trás
					for(*i = 1; *i < 10; (*i)++)
						bucket[*i] += bucket[*i - 1];

				/*
				 * Faz a ordenação pelo digito do vetor v na posição i,
				 * colocando cada elemento na posição do vetor auxiliar b,
				 * sendo a posição determinada de acordo com a quantidade de elementos
				 * que foi determinada na laço anterior
				 */
					for(*i = n-1; *i >= 0; (*i)--)
						b[--bucket[(v[*i] / *exp) % 10]] = v[*i];

				// Coloca os elementos ordenados de b em v
					for(*i = 0; *i < n; (*i)++)
						v[*i] = b[*i];

				*exp *= 10;
				// desalocação
			}

		// desalocação
			delete i;
			delete maior;
			delete exp;
			delete b;
			delete bucket;
	}

// programa principal
	int main(){
		// alocação das váriaveis
			int *v = new int[10];
			int *i = new int;

		geraArrayAleatorio(v, 10); // gerando array para o teste
		
		// teste de ordenação
			std::cout << "O vetor antes da ordenação: "; imprimir(v,10);
				radixSort(v, 10);
			std::cout << "O vetor depois da ordenação: "; imprimir(v,10);

		// desalocação das váriaveis
			delete v;
			delete i;

		return 0;
	}