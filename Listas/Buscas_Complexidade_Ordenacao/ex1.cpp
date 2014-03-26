/*
 * Para um vetor de 7 inteiros v={1, 2, 6, 8, 9, 13, 15}, qual será o número máximo de comparações:
 */
#include <iostream>
#include "../../AlgoritmosBusca/sequencial.cpp"
#include "../../AlgoritmosBusca/binaria.cpp"
 
#define tam 7

using std::cout;

// função para teste de busca
	void teste(int v[], int n, int num, int alg){
		bool res;
		int cont = 0;
		switch(alg){
			case 1: // sequencial
		 		res = buscaSequencial(v, n, num, &cont);
		 		break;
		 	case 2: // binária
		 		res = buscaBinaria(v, n, num, &cont);
		 		break;
		}
		if(res)
			cout << "O elemento " << num <<" foi encontrado";
		else
			cout << "O elemento " << num <<" não foi encontrado no vetor";
		if(cont == 1)
			cout << " e foi necessária " << cont << " comparação para a solução.\n";
		else
			cout << " e foram necessárias " << cont << " comparações para a solução.\n";
	}


// programa principal
	int main(){
		int v[] = {1, 2, 6, 8, 9, 13, 15 };
		int num;
		/*
		 * 		a) Busca sequencial
		 */
			cout << "Busca Sequencial:\n";
			/*
			 * Se o elemento procurado for 1;
			 */
			 	num = 1;
			 	teste(v, tam, num, 1);
			/*
			 * Se o elemento procurado for 12.
			 */
			 	num = 12;
			 	teste(v, tam, num, 1);
		/*
		 *		b) Busca binária
		 */
			cout << "Busca Binária:\n";
			/*
			 * Se o elemento procurado for 9;
			 */
			 	num = 9;
			 	teste(v, tam, num, 2);
			/*
			 *  Se o elemento procurado for 15.
			 */
			 	num = 15;
			 	teste(v, tam, num, 2);

		return 0;
	}