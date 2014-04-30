#include <iostream>

// inclui a classe da conta bancária
	#include "Conta.h"
// inclui a classe para bancos (listas encadeada de várias contas)
	#include "Contas.h"
// inclui a função menu
	#include "menu.h"

int main() {
	
	Contas * banco = new Contas();

	menu(0,banco);

	delete banco;
}