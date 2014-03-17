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
