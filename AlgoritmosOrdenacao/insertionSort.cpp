/*
 * Insertion sort, ou ordenação por inserção, é um simples algoritmo de ordenação, 
 * eficiente quando aplicado a um pequeno número de elementos. 
 * Em termos gerais, ele percorre um vetor de elementos da esquerda para a direita e à medida 
 * que avança vai deixando os elementos mais à esquerda ordenados. O algoritmo de inserção funciona 
 * da mesma maneira com que muitas pessoas ordenam cartas em um jogo de baralho como o pôquer.
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