/*
 * O Radix sort é um algoritmo de ordenação rápido e estável
 * que pode ser usado para ordenar itens que estão identificados por chaves únicas.
 * Cada chave pode ser uma cadeia de caracteres (ordem lexicografia) ou número.
 */
	// Quick Sort
        void quickSort(int vetor[], int inicio, int fim){
            int pivo, aux, i, j, meio;

            i = inicio;
            j = fim;

            meio = (int) ((i + j) / 2);
            pivo = vetor[meio];

            do{
                while (vetor[i] < pivo) i = i + 1;
                while (vetor[j] > pivo) j = j - 1;

                if(i <= j){
                    aux = vetor[i];
                    vetor[i] = vetor[j];
                    vetor[j] = aux;
                    i = i + 1;
                    j = j - 1;
                }
            }while(j > i);

            if(inicio < j) quickSort(vetor, inicio, j);
            if(i < fim) quickSort(vetor, i, fim);

        }