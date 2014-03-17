/*
 * O selection sort é um algoritmo de ordenação
 * baseado em se passar sempre o menor valor do vetor para a primeira posição
 * depois o de segundo menor valor para a segunda posição,
 * e assim é feito sucessivamente com os (n-1) elementos restantes, até os últimos dois elementos.
 */
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