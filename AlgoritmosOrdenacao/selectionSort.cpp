/*
 * O selection sort é um algoritmo de ordenação
 * baseado em se passar sempre o menor valor do vetor para a primeira posição
 * depois o de segundo menor valor para a segunda posição,
 * e assim é feito sucessivamente com os (n-1) elementos restantes, até os últimos dois elementos.
 */
// Selection Sort
	void selectionSort(int v[], int n){
		// alocação das váriaveis
			int *i   = new int;
			int *j   = new int;
			int *aux = new int; // aux para troca de posições
			int *min = new int; // posição do menor número na faixa do vetor

		//ordenação
			for(*i = 0; *i < n; (*i)++){
				*min = *i; // pega o inicio da faixa do vetor
				for(*j = *i; *j < n; (*j)++){
					// verifica qual a posição do menor número da faixa do vetor
						if(v[*j] < v[*min])
							*min = *j;
				}
				if(*i != *min) { // se a posição mudou da inicial fará a troca
					*aux    = v[*i];
					v[*i]   = v[*min];
					v[*min] = *aux;
				}
			}

		// desalocação das váriaveis
			delete i;
			delete j;
			delete aux;
			delete min;
	}