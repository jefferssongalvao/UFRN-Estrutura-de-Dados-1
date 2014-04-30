#include <iostream>
#include "Conta.h"

using std::cout;

// Construtor Padrão
	ContaBancaria::ContaBancaria() {
		saldo = 0;
		next = NULL;
	}
// Construtor com Parâmetros
	ContaBancaria::ContaBancaria(double s, int c) {
		conta = c;
		saldo = s; 
		next = NULL;
	}
// metodos Set
	void ContaBancaria::setSaldo (double s) { saldo = s; }
// Metodos
	double ContaBancaria::getSaldo() const { return saldo; }