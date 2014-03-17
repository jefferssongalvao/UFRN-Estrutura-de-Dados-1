/*
 * Função para fazer os testes de cada um dos algoritmos
 */
    int testeAlgoritmo(int op, double *time1, double *time2, double *time3, double *time4, int size){
        struct timeval t0, t1; // estruturas usadas para cálculo do tempo de execução
        int *v = new int[size]; // alocação do vetor selection
        int *w = new int[size]; // alocação do vetor bubble
        int *k = new int[size]; // alocação do vetor insertion
        int *z = new int[size]; // alocação do vetor insertion

        // Escolha do cenário
            switch(op){
                // Primeiro cenário
                    case 1:
                        geraArrayAleatorio(v, size); // criação do array selection
                        geraArrayAleatorio(w, size); // criação do array bubble
                        geraArrayAleatorio(k, size); // criação do array insertion
                        geraArrayAleatorio(z, size); // criação do array insertion
                        break;
                // Segundo cenário
                    case 2:
                        geraArrayAleatorio_crescente(v, size);  // criação do array selection
                        geraArrayAleatorio_crescente(w, size);  // criação do array bubble
                        geraArrayAleatorio_crescente(k, size);  // criação do array insertion
                        geraArrayAleatorio_crescente(z, size);  // criação do array insertion
                        break;
                // terceiro cenário
                    case 3:
                        geraArrayAleatorio_decrescente(v, size);  // criação do array selection
                        geraArrayAleatorio_decrescente(w, size);  // criação do array bubble
                        geraArrayAleatorio_decrescente(k, size);  // criação do array insertion
                        geraArrayAleatorio_decrescente(z, size);  // criação do array insertion
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
                    bubbleSort(w, size);
                gettimeofday(&t1, NULL);
                (*time2) += ((t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec)/(double)1000;

            // insertionSort
                gettimeofday(&t0, NULL);
                    *time3  = 0.0;
                    insertionSort(k, size);
                gettimeofday(&t1, NULL);
                (*time3) += ((t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec)/(double)1000;

            // shellSort
                gettimeofday(&t0, NULL);
                    *time4  = 0.0;
                    shellSort(z, size);
                gettimeofday(&t1, NULL);
                (*time4) += ((t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec)/(double)1000;

        // desalocação do vetor
            delete v;
    }
