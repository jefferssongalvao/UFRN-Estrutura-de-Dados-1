/*
 * Escreva o algoritmo mais eficiente que você conseguir para encontrar
 * a mediana de um arranjo de n elementos.
 * Em seguida, análise a complexidade do seu algoritmo.
 *
 * Para esse caso a complexidade do algoritmo é constante!!!
 */

#include <iostream>

// inclusão de alguns metodos do namespace std
	using std::cout;

// função para calcular a mediana do arranjo
	void mediana(int v[], int n){
		int m; // receberá o valor da mediana
		int pos = n / 2; // variável responsável para determinar a metade inteira do tamanho do vetor

		if(n % 2 != 0) { // se for impar
			m = v[pos]; // exatamente a posição do número referente a metade inteira do tamanho do vetor
		} else { // se for par
			// a média dos valores m1 e m2 referentes a posição da metade inteira do tamanho do vetor e a possição seguinte
				m = (v[pos] + v[++pos]) / 2; 
		}
		cout << "A mediana é: " << m << "\n";
	}

// programa principal
	int main(){

		// vetor com tamanho impar
			int v[] = { 1, 2, 6, 8, 9, 13, 15 };
			mediana(v, 7);

		// vetor com tamanho par
			int w[] = { 1, 2, 6, 8, 9, 13, 15 };
			mediana(w, 8);

		return 0;
	}