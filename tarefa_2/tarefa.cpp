/*
 * Com o intúito de relembrar os conceitos sobre algoritmos de ordenação O(n log n)
 * (Quicksort e Mergesort) e O(dn) (Radixsort) vistos em sala de aula
 * implemente três funções recursivas de ordenação, uma para cada tipo de algoritmo.
 *
 * Execute testes utilizando as três funções implementadas.
 * Os testes deverão ser divididos em três cenários.
 * No primeiro, as funções deverão ordenar arranjos de números aleatórios com 100, 300, 500, 800 e 1000 elementos.
 * No segundo, elas deverão lidar com arranjos de números ordenados de forma crescente
 * (usar as mesmas quantidades de números).
 * No último, as funções deverão lidar com  arranjos de números ordenados de forma decrescente
 * (usar as mesmas quantidades de números). 
 * 
 */

#include <iostream>
#include <fstream> // para a manipulação de arquivos
#include <cstdlib> // para uso da função hand()
#include <sys/time.h> // para cálculo do tempo de execução

/*
 * Geração de amostras aleatórias dos vetores
 */

    /*
     * Array do primeiro cenário.
     * Aleatório, mas não ordenado
     */
        void geraArrayAleatorio(int v[], int N) {
            srand(time(NULL));
            // alocação de variável
                int *i = new int;

            for(*i = 0; *i < N; (*i)++) v[*i] = (rand() % 100);

            // desalocação de variável
                delete i;
        }

    /* 
     * Array do segundo cenário.
     * Vetor em ordem crescente com N elementos com valores entre min e max
     */
        int geraArrayAleatorio_crescente(int v[], int N) {
            srand(time(NULL));  
            // alocação de variável
                int *i = new int;
                int *min = new int;
                *min = 0;

            for (*i = 0; *i < N; ++(*i)) {
                v[*i] = (rand() % 100) + *min;
                *min = v[*i];
            }

            // desalocação de variável
                delete i;
                delete min;
        }

    /* 
     * Array do terceiro cenário.
     * Vetor em ordem decrescente com N elementos com valores entre min e max
     */
        int geraArrayAleatorio_decrescente(int v[], int N) {
            srand(time(NULL));  
            // alocação de variável
                int *i = new int;
                int *min = new int;
                *min = 0;

            for (*i = N-1; *i >= 0; --(*i)) {
                v[*i] = (rand() % 100) + *min;
                *min = v[*i];
            }

            // desalocação de variável
                delete i;
                delete min;
        }

/*
 * Funções dos algoritmos de ordenação
 */
    /*
     * Quick Sort
     */
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

    /*
     * Merge Sort
     */

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

    /*
     * Radix Sort
     */
        void radixSort(int v[],int start, int end, unsigned int mask) {
          if (start>=end+1) return;
          if (!mask) return;

          int left, right,tmp;

          for(left=start, right=end;;) {
                while ( left<=right && !( v[left]  & mask) ) left++ ;
                while ( left<=right &&  ( v[right] & mask) ) right--;

                if (left>=right) {
                  radixSort(v, start, left-1, mask>>1);
                  radixSort(v, left, end, mask>>1);
                  return;
                } else {
                  v[left]^=v[right];;
                  v[right]^=v[left];
                  v[left]^=v[right];
                }
            }
        }

/*
 * Função para fazer os testes de cada um dos algoritmos
 */
    int testeAlgoritmo(int op, double *time1, double *time2, double *time3, int size){
        struct timeval t0, t1; // estruturas usadas para cálculo do tempo de execução
        int *v = new int[size]; // alocação do vetor selection
        int *w = new int[size]; // alocação do vetor bubble
        int *k = new int[size]; // alocação do vetor insertion

        // Escolha do cenário
            switch(op){
                // Primeiro cenário
                    case 1:
                        geraArrayAleatorio(v, size); // criação do array selection
                        geraArrayAleatorio(w, size); // criação do array bubble
                        geraArrayAleatorio(k, size); // criação do array insertion
                        break;
                // Segundo cenário
                    case 2:
                        geraArrayAleatorio_crescente(v, size);  // criação do array selection
                        geraArrayAleatorio_crescente(w, size);  // criação do array bubble
                        geraArrayAleatorio_crescente(k, size);  // criação do array insertion
                        break;
                // terceiro cenário
                    case 3:
                        geraArrayAleatorio_decrescente(v, size);  // criação do array selection
                        geraArrayAleatorio_decrescente(w, size);  // criação do array bubble
                        geraArrayAleatorio_decrescente(k, size);  // criação do array insertion
                        break;
            }
        // Execução dos algoritmos de ordenação
            // quickSort
                gettimeofday(&t0, NULL);
                    *time1  = 0.0;
                    quickSort(v, 0, size-1);
                gettimeofday(&t1, NULL);
                (*time1) += ((t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec)/(double)1000;

            // mergeSort
                gettimeofday(&t0, NULL);
                    *time2  = 0.0;
                    mergeSort(w, size);
                gettimeofday(&t1, NULL);
                (*time2) += ((t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec)/(double)1000;

            // radixsort
                for(int i; i < size; i++)
                    std::cout << k[i] << " ";
                std::cout << "\n";
                gettimeofday(&t0, NULL);
                    *time3  = 0.0;
                    radixSort(k, 0, size-1, 1<<31);
                gettimeofday(&t1, NULL);
                (*time3) += ((t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec)/(double)1000;
                for(int i; i < size; i++)
                    std::cout << k[i] << " ";
                std::cout << "\n\n";


        // desalocação do vetor
            delete v;
            delete w;
            delete k;
    }

int main() {
    // alocação das variáveis
        int *i = new int;
        int *j = new int;

        // variáveis de tempo
            double *time1 = new double; // variável de tempo para o algoritmo selectionSort
            double *time2 = new double; // variável de tempo para o algoritmo bubbleSort
            double *time3 = new double; // variável de tempo para o algoritmo insertionSort

        // Criação do vetor com os tamanho
            int *tamanhos = new int[5];
                tamanhos[0] = 100; tamanhos[1] = 300; tamanhos[2] = 500; tamanhos[3] = 800; tamanhos[4] = 1000;

    std::ofstream Escrita; // instância o objeto para manipulaão de arquivos
    Escrita.open("output.csv"); // Inicialização do arquivo que será gravada a saída dos dados

    for(*i = 1; *i <= 3; (*i)++){
        Escrita << "Cenário " << *i << ".\n";
        for(*j = 0; *j < 5; (*j)++){
            testeAlgoritmo(*i, time1, time2, time3, tamanhos[*j]);
            Escrita << "Tamanho do vetor:" << tamanhos[*j] << "\n";
            Escrita << "Tempo decorrido quickSort: " << *time1 << "\n";
            Escrita << "Tempo decorrido mergeSort: " << *time2 << "\n";
            Escrita << "Tempo decorrido radixSort: " << *time3 << "\n\n";
        }
    }

    Escrita.close();

    // desalocação das variáveis
        delete i;
        delete j;
        delete time1;
        delete time2;
        delete time3;
        delete tamanhos;

    return 0;
}
