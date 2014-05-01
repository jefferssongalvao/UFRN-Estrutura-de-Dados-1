#ifndef _LISTA_H_
	#define _LISTA_H_
		#include "Node.h"
		class Lista {
			Node * head;
			int qtd; // quantidade de nós na lista
			public:
				// construtor padrão
					Lista();
				// metodo inserir
					void inserir(int v, int pos);
				// metodo remover
					void remover(int p);
				// metodo mostrar posição (busca sequencial)
					void mostrarPos(int v) const;
				// metodo mostrar elemento
					void mostrarEle(int p) const;
				// metódo esvaziar a lista (destrutor)
					void esvaziar();
				// metodo exibir elementos
					void exibir() const;
				// metodos get
					int getQtd() const;
		};
#endif