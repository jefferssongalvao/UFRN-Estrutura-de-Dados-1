// Busca Binária (recursiva)
	bool buscaBinaria(int v[], int n, int num, int *cont) {
	    // índice do elemento mais pŕoximo do meio e o valor dele
	    	int i = n/2;
	    	int y = v[i];
	    	(*cont)++; // quantidade de comparações
	    // se o arranjo estiver vazio ou não tiver achado
		    if (n == 0)
		        return 0;
		// se achou o número retorna a posição
		    else if (num == y)
		        return 1;
		// senão vê se está na primeira metade do vetor ou na segunda
		    else if (num < y) // primeira metade
		        return buscaBinaria(v, i, num, cont);
		    else // segunda metade num > y
		        return buscaBinaria(&v[i+1], n-(i+1), num, cont);
	}