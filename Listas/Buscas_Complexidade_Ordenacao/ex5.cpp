/*
 * Escreva uma solução algorítmica capaz de ordenar um vetor
 * com n inteiros no intervalo [1,n2] em tempo linear O(n).
 */

#include <iostream>

using std::cout;

// programa principal
	int main(){
		int pos = 0; // posição percorrida
		int razao = 1; // razão usada numa progressão de movimentação dos passos
		int passos = 0; // quantidade de passos dados
		int teste = 0; // váriavel teste de esquerda e direita
		bool v[] = { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		// posição inicial
			pos = 3;
		while(v[pos] != 1) {
			for (int i = 1; i <= razao; ++i) {
				passos++;
				if(v[pos] == 1)
					break;
				else {
					if(teste % 2 == 0) {
						pos++;
					} else {
						pos--;
					}
				}
			}
			razao *= 2;
			teste++;
		}
		
		cout << "A quantidade de passos dados foi: " << passos << ".\n";
		return 0;
	}