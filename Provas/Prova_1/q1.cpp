#include <iostream>

using std::cout;

int mistura(int L1[], int N1, int L2[], int N2, int L3[], int target){
	// indices dos 3 vetores (L1[i], L2[j], L3[k])
		int i = 0, j = 0, k = 0;
	// menor número e tamanho do vetor resultado (#L3 = N3 = N1 + N2)
		int min, N3 = N1 + N2;
	// variável de teste se os números são iguais
		bool teste = 0;

	// enquanto houver elementos em um dos vetores
		while(i < N1 || j < N2) {
			teste = 0; // inicializa com FALSE a variável de teste de igualdade
			min = 0; // re-inicializa a váriavel que receberá o menor número (o que vai ser guardado no vetor L3)
			if(i < N1 && j < N2) { // verifica se os dois vetores tem elementos para serem comparados
				if(L1[i] < L2[j]) // o elemento do L1 é o menor
					min = L1[i++];
				else if(L2[j] < L1[i]) // o elemento do L2 é o menor
					min = L2[j++];
				else {  // os elementos são iguais, logo a variável teste de igualdade deverá ser setada como TRUE
					min = L1[i++];
					j++;
					teste++; // TRUE
				}
			} else { // senão, verificará qual dos vetores tem elemento
				if(i < N1) // o vetor L1 ainda tem elemento
					min = L1[i++];
				else if(j < N2) // o vetor L2 ainda tem elemento
					min = L2[j++];
			}
			/*
			 * Verifica se a o elemento a ser inserido no L3 é igual ao target
			 * Se sim, então ele não deverá ser incluído no vetor L3, 
			 * 		logo o tamanho do L3 deverá diminuir do inicial (N1+N2)
			 * senão, ele deverá ser incluído
			 */
				if(min != target) {
					if(teste) // verifica se houve igualdade de elementos e incluí mais uma vez
						L3[k++] = min;
					L3[k++] = min;
				} else {
					if(teste) // verifica se houve igualdade de elementos e diminuí outra vez o tamanho de N3
						N3--;
					N3--;
				}
		}
	return N3;
}

int main(){

	// declaração dos vetores
		int v1[] = { 1, 2, 3, 5 }; // vetor 1
		int v2[] = { 4, 5, 6, 7, 8, 9 }; // vetor 2
	// tamanho dos vetores 1 e 2
		int N1 = 4, N2 = 6;
	// declaração do vetor 3 com o tamanho da soma dos tamanho dos vetores 1 e 2
		int v3[N1+N2];
	// Numero que não poderá aparecer no vetor 3		
		int target = 5;

	// mostra o vetor 1 (v1)
		cout << "Vetor 1 = { ";
		for (int i = 0; i < N1; ++i)
			cout << v1[i] << " ";
		cout << "}.\n";

	// mostra o vetor 2 (v2)
		cout << "Vetor 2 = { ";
		for (int i = 0; i < N2; ++i)
			cout << v2[i] << " ";
		cout << "}.\n\n";

	// elemento que não pode aparecer no vetor 3
		cout << "Este elemento não poderá aparecer no vetor 3: " << target << ".\n\n";

	int N3 = mistura(v1, N1, v2, N2, v3, target); // recebe o tamanho do vetor 3 (v3) e preenche o mesmo

	// mostra o vetor 3 (v2) e a sua quantidade de elementos
		cout << "A quantidade de numeros no vetor 3: "<< N3 << "\n";
		cout << "Vetor 3 = { ";
		for (int i = 0; i < N3; ++i)
			cout << v3[i] << " ";
		cout << "}.\n";

	return 0;
}