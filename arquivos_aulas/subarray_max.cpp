/*
 * Escrever uma função para achar a soma máxima de uma subsequência e expressar seu melhor e pior caso.
 * 
 * Dada uma sequência de n valores inteiros (possivelmente negativos) 
 * A={a1,a2,...,an}, encontrar a maior soma de valores contínuos. Ou seja, encontrar o somatório de ak
 * onde K vai de i até j.
 *
 * Por exemplo, para A={−2,11,−4,13,−5,−2} a resposta é 20 (i.e. a soma de a2 até a4).
 *
 */

#include <iostream>

/* 
 * Função com complexidade O(N²)
 */
	int maior_soma_subArray1 (int v[], int n) {
		// alocação dinâmica das variáveis
			int *i         = new int;
			int *j         = new int;
			int *soma      = new int;
			int *maiorSoma = new int;

		*maiorSoma = 0; // inicialização da maior soma

		for(*i = 0; *i < n; (*i)++){
			*soma = v[*i]; 
			for(*j = *i+1; *j < n; (*j)++){
				*soma += v[*j];
				 /*
				  * Compara a soma atual com a maior soma até o momento, 
				  * se verdade a maior soma assume o valor da soma atual.
				  */
					if(*soma > *maiorSoma) *maiorSoma = *soma;
			} 
		}
		// desalocação das variáveis
			delete(i);
			delete(j);
			delete(soma);

		return *maiorSoma;
	}

/* 
 * Função com complexidade O(N) :: http://en.wikipedia.org/wiki/Maximum_subarray_problem :: com adapatações
 */
	int maior_soma_subArray2(int v[], int n){
		// alocação dinâmica das variáveis
			int *i         = new int;
			int *soma      = new int;
			int *maiorSoma = new int;

		*maiorSoma = v[0], *soma = v[0];  // inicialização das somas

		for(*i = 1; *i < n; (*i)++){
			if(*soma < 0) // se a soma for negativa ele reinicia a soma
				*soma = v[*i];
			else
				*soma += v[*i];			
			/*
			* Compara a soma atual com a maior soma até o momento, 
			* se verdade a maior soma assume o valor da soma atual.
			*/
				if(*soma >= *maiorSoma ) *maiorSoma  = *soma;
		}
		// desalocação das variáveis
			delete(i);
			delete(soma);

		return *maiorSoma;
	}

int main() {
	// Vetores para os testes
		int v[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
		int w[] = { -2, 11, -4, 13, -5, -2 };

	std::cout << "Testes usando o vetor v = { -2, 1, -3, 4, -1, 2, 1, -5, 4 }\n";
	std::cout << "O(N^2): " << maior_soma_subArray1(v,9) << std::endl;
	std::cout << "O(N): " << maior_soma_subArray2(v,9) << std::endl;

	std::cout << "Testes usando o vetor w = { -2, 11, -4, 13, -5, -2 }\n";
	std::cout << "O(N^2): " << maior_soma_subArray1(w,6) << std::endl;
	std::cout << "O(N): " << maior_soma_subArray2(w,6) << std::endl;

	return 0;
}