/*
 * Escreva uma solução algorítmica capaz de ordenar um vetor
 * com n inteiros no intervalo [1,n2] em tempo linear O(n).
 */

#include <iostream>

using std::cout;

// programa principal
	int main(){
		int pos = 0; // posição percorrida
		int razao = 0; // razão usada numa progressão de movimentação dos passos
		int passos = 0; // quantidade de passos dados
		bool v[] = { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		// posição inicial
			pos = 3;
		while(v[pos] != 1) {
			if(razao % 2 == 0) {
				pos += razao;
			} else {
				pos -= razao;
			}
			razao++;
			passos += razao;
		}
		
		cout << "A quantidade de passos dados foi: " << passos << " e foi executados " << razao << ".\n";
		return 0;
	}