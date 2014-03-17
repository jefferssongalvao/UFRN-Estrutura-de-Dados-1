/*
 * O Radix sort é um algoritmo de ordenação rápido e estável
 * que pode ser usado para ordenar itens que estão identificados por chaves únicas.
 * Cada chave pode ser uma cadeia de caracteres (ordem lexicografia) ou número.
 */
	// Radix Sort
		void ordena(int v[], int n){
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
					preenche(bucket, 10);

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
				}

			// desalocação
				delete i;
				delete maior;
				delete exp;
				delete b;
				delete bucket;
		}