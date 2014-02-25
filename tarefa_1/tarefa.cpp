/*
 * Com o intúito de relembrar os conceitos sobre algoritmos de ordenação O(n2) 
 * (Selection, Bubble e Insertion) vistos em sala de aula
 * implemente três funções de ordenação, uma para cada tipo de algoritmo.
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
        int geraArrayAleatorio_crescente(int v[], int N, int min) {
            srand(time(NULL));  
            // alocação de variável
                int *i = new int;

            for (*i = 0; *i < N; ++(*i)) {
                v[*i] = (rand() % 100) + min;
                min = v[*i];
            }

            // desalocação de variável
                delete i;
        }

    /* 
     * Array do terceiro cenário.
     * Vetor em ordem decrescente com N elementos com valores entre min e max
     */
        int geraArrayAleatorio_decrescente(int v[], int N, int min) {
            srand(time(NULL));  
            // alocação de variável
                int *i = new int;

            for (*i = N-1; *i >= 0; --(*i)) {
                v[*i] = (rand() % 100) + min;
                min = v[*i];
            }

            // desalocação de variável
                delete i;
        }

/*
 * Funções dos algoritmos de ordenação
 */
    // selection Sort
        void selectionSort (int v[], int N) {
            // alocação de variável
                int *min = new int;
                int *aux = new int;
                int *i   = new int;
                int *j   = new int;

            for (*i = 0; *i < N-1; (*i)++) {
                // acha o mínimo
                    min = i;
                    for (*j = *i+1; *j < N; (*j)++)
                        if (v[*j] < v[*min])
                            *min = *j;
                // troca elemento
                    *aux = v[*i];
                    v[*i] = v[*min];
                    v[*min] = *aux;
            }

            // desalocação de variável
                delete min;
                delete aux;
                delete j;
        }

    // bubble Sort
        void bubbleSort(int v[], int N) {
            // alocação de variável
                int *i   = new int;
                int *j   = new int;
                int *aux = new int;

            for (*i = N-1; *i > 0; (*i)--) {
                for (*j = 0; *j < *i; (*j)++) {
                    // testa os elementos par a par
                        if (v[*j] > v[*j+1]) {
                            // troca elemento
                                *aux = v[*j];
                                v[*j] = v[*j+1];
                                v[*j+1] = *aux;
                        }
                }
            }

            // desalocação de variáveis
                delete i;
                delete j;
                delete aux;
        }

    // insertion Sort
        void insertionSort (int v[], int N) {
            // alocação de variáveis
                int *i   = new int;
                int *j   = new int;
                int *key = new int;

            for (*i = 1; *i < N; (*i)++) {
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

            // desalocação de variáveis
                delete i;
                delete j;
                delete key;
        }

/*
 * Função para fazer os testes de cada um dos algoritmos
 */
    int testeAlgoritmo(int op, double *time1, double *time2, double *time3, int size){
        struct timeval t0, t1; // estruturas usadas para cálculo do tempo de execução
        int *v = new int[size]; // alocação do vetor

        // Escolha do cenário
            switch(op){
                // Primeiro cenário
                    case 1:
                        geraArrayAleatorio(v, size); // criação do array
                        break;
                // Segundo cenário
                    case 2:
                        geraArrayAleatorio_crescente(v, size, 0);  // criação do array
                        break;
                // terceiro cenário
                    case 3:
                        geraArrayAleatorio_decrescente(v, size, 0);  // criação do array
                        break;
            }
        // Execução dos algoritmos de ordenação
            // selectionSort
                gettimeofday(&t0, NULL);
                    *time1  = 0.0;
                    selectionSort(v, size);
                gettimeofday(&t1, NULL);
                (*time1) += ((t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec)/(double)1000;

            // bubbleSort
                gettimeofday(&t0, NULL);
                    *time2  = 0.0;
                    bubbleSort(v, size);
                gettimeofday(&t1, NULL);
                (*time2) += ((t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec)/(double)1000;

            // insertionSort
                gettimeofday(&t0, NULL);
                    *time3  = 0.0;
                    insertionSort(v, size);
                gettimeofday(&t1, NULL);
                (*time3) += ((t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec)/(double)1000;

        // desalocação do vetor
            delete v;
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
            Escrita << "Tamanho do vetor:" << tamanhos[*j] << ".\n";
            Escrita << "Tempo decorrido selectionSort: " << *time1 << ".\n";
            Escrita << "Tempo decorrido bubbleSort: " << *time2 << ".\n";
            Escrita << "Tempo decorrido insertionSort: " << *time3 << ".\n\n";
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
