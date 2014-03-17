/*
 * O merge sort, ou ordenação por mistura, é um exemplo de algoritmo de ordenação
 * do tipo dividir-para-conquistar.
 *
 * Sua ideia básica consiste em Dividir(o problema em vários sub-problemas e resolver esses 
 * sub-problemas através da recursividade) e Conquistar(após todos os sub-problemas
 * terem sido resolvidos ocorre a conquista que é a união das resoluções dos sub-problemas).
 * Como o algoritmo do Merge Sort usa a recursividade em alguns problemas esta técnica não é muito 
 * eficiente devido ao alto consumo de memória e tempo de execução.
 */
	// Merge Sort
        void merge(int vec[], int vecSize) {
            int mid;
            int i, j, k;
            int* tmp;

            tmp = (int*) malloc(vecSize * sizeof(int));
            if (tmp == NULL) {
                exit(1);
            }

            mid = vecSize / 2;

            i = 0;
            j = mid;
            k = 0;
            while (i < mid && j < vecSize) {
                if (vec[i] < vec[j]) {
                    tmp[k] = vec[i++];
                } else {
                    tmp[k] = vec[j++];
                }
                ++k;
            }

            if (i == mid) {
                while (j < vecSize) {
                    tmp[k++] = vec[j++];
                }
            } else {
                while (i < mid) {
                    tmp[k++] = vec[i++];
                }
            }

            for (i = 0; i < vecSize; ++i) {
                vec[i] = tmp[i];
            }

            free(tmp);
        }
        void mergeSort(int vec[], int vecSize) {
            int mid;

            if (vecSize > 1) {
                mid = vecSize / 2;
                mergeSort(vec, mid);
                mergeSort(vec + mid, vecSize - mid);
                merge(vec, vecSize);
            }
        }
