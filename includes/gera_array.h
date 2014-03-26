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

