/*
 * O selection sort é um algoritmo de ordenação
 * baseado em se passar sempre o menor valor do vetor para a primeira posição
 * depois o de segundo menor valor para a segunda posição,
 * e assim é feito sucessivamente com os (n-1) elementos restantes, até os últimos dois elementos.
 */
// Shell Sort
	void shellSort(int v[], int N) {
		// alocação das variáveis
			int *h     = new int;
			int *i     = new int;
			int *j     = new int;
			int *value = new int;
		
		// inicializando h
			*h = 1;
			while(*h < N)
				*h = 3 * *h + 1;
		// ordenação
			do {
			    *h /= 3;
			    for(*i = *h; *i < N; (*i)++) {
			        *value = v[*i];
			        *j = *i - *h;
			        while (*j >= 0 && *value < v[*j]) {
			            v [*j + *h] = v[*j];
			            *j -= *h;
			        }
			        v[*j + *h] = *value;
			    }
			} while ( *h > 1);
		
		// desalocando as variáveis
			delete h;
			delete i;
			delete j;
			delete value;
	}