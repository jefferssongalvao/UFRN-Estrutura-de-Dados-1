/*
 * Criado por Donald Shell em 1959,1 publicado pela Universidade de Cincinnati, Shell sort é o mais 
 * eficiente algoritmo de classificação dentre os de complexidade quadrática. 
 * É um refinamento do método de inserção direta.2 O algoritmo difere do método de inserção direta pelo 
 * fato de no lugar de considerar o array a ser ordenado como um único segmento, ele considera vários 
 * segmentos sendo aplicado o método de inserção direta em cada um deles.3 Basicamente o algoritmo passa 
 * várias vezes pela lista dividindo o grupo maior em menores. Nos grupos menores é aplicado o método da 
 * ordenação por inserção.
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