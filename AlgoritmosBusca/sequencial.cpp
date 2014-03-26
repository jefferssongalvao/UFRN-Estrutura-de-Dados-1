// Busca Sequencial
	bool buscaSequencial(int v[], int n, int num, int *cont){
		for(int i = 0; i < n; i++) {
			// variável para contar quantidade de comparações necessárias para achar a solução da busca
				(*cont)++;
			if(v[i] == num)
				return 1;
		}
		return 0;
	}