#include <iostream>
#include <cstdlib> // para uso da função system()

using std::cout;
using std::cin;

#include "menu.h"

int main() {
	
	int tam;
	
	system("clear");
	cout << "Digite o tamanho da sua lista: ";
	cin >> tam;
	
	menu(0, tam);

}