#include <iostream>
#include "Node.h"

// contrutor padrão
	Node::Node() {
		valor = 0;
		next = NULL;
	}
// construtor com parâmetro
	Node::Node(int v) {
		valor = v;
		next = NULL;
	}