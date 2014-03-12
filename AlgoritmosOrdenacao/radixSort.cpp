/*
 * O Radix sort é um algoritmo de ordenação rápido e estável
 * que pode ser usado para ordenar itens que estão identificados por chaves únicas.
 * Cada chave pode ser uma cadeia de caracteres (ordem lexicografia) ou número.
 */

#include <iostream>
#include <cstdlib> // para uso da função hand()

void geraArrayAleatorio(int v[], int N) {
    srand(time(NULL));
    // alocação de variável
        int *i = new int;

    for(*i = 0; *i < N; (*i)++)
    	v[*i] = (rand() % 100);

    // desalocação de variável
        delete i;
}

void radixSort(int v[], int n){
	// alocação das váriaveis
		int *i = new int;
		int *maior = new int;
		int *exp = new int;
		int *b = new int[n]; // vetor auxiliar
		*exp = 1;
	*maior = v[0]; // inicia a váriavel com o primeiro número do vetor
	for(*i = 1; *i < n; (*i)++){
		if(v[*i] > *maior)
			*maior = v[*i];
	}
	while( (*maior / *exp) > 0 ){
		int *bucket = new int[10];
		*bucket = { 0 };
		for(*i = 0; *i < n; (*i)++)
			bucket[( v[*i]/ *exp) %10]++;

		for(*i = 1; *i < 10; (*i)++)
			bucket[*i] += bucket[*i - 1];

		for(*i = n; *i >= 0; (*i)--)
			b[--bucket[(v[*i] / *exp) % 10]] = v[*i];

		for(*i = 0; *i < n; (*i)++)
			v[*i] = b[*i];

		*exp *= 10;
	}
}
int main(){
	int *v = new int[10];
	int *i = new int;

	geraArrayAleatorio(v, 10);
	
	for(*i = 0; *i < 10; (*i)++)
		std::cout << v[*i] << " ";
	std::cout << "\n";

	radixSort(v, 10);

	for(*i = 0; *i < 10; (*i)++)
		std::cout << v[*i] << " ";
	std::cout << "\n";

	return 0;
}