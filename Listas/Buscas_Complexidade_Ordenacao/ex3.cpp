/*
 * Escreva uma solução algorítmica capaz de ordenar um vetor
 * com n inteiros no intervalo [1,n2] em tempo linear O(n).
 */

#include <iostream>
#include <cstdlib>

using std::cout;

#include "inc_ex3.cpp"

// programa principal
	int main(){
		int *v = new int[4];
		preenche(v,4);
		imprime(v,4);
		delete v;
		return 0;
	}