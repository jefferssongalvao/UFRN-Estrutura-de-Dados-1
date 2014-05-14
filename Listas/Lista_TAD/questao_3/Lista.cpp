#include <iostream>

#include "Node.h"
#include "Lista.h"

using std::cout;

// construtor padrão
	Lista::Lista() { 
		head = NULL;
		qtd = 0;
	}
// metodo inserir
	void Lista::inserir(int v, int pos) {
		Node * novo = new Node(v);
		if(pos == 0) {
			if(head == NULL)
				head = novo;
			else{
				novo->next = head;
				head = novo;
			}
		} else {
            Node * onde = head;
            for(int i = 0; i < pos-1; i++)
                onde = onde->next;
            novo->next = onde->next;
            onde->next = novo;
		}
		qtd++;
	}
// metodo remover
	void Lista::remover(int p) {
        Node * aux = head;
		if(p == 0) {
			head = aux->next;
		} else {
			Node * onde = head;
            for(int i = 0; i < p-1; i++)
                onde = onde->next;
            aux = onde->next;
            onde->next = aux->next;
		}
		delete aux;
		qtd--;
	}
// metodo mostrar posição (busca sequencial)
	void Lista::mostrarPos(int v) const {
		Node * lista = head;
		int pos = -1;
		for(int i = 0; i < qtd; i++) {
			if(lista->valor == v) {
				pos = i;
				break;
			}
			lista = lista->next;
		}
		if(pos >= 0)
			cout << "\nO valor " << v << " foi achado na posição " << pos << " da lista.\n\n";
		else
			cout << "\nO valor " << v << " não foi achado na lista.\n\n";
	}
// metodo mostrar elemento
	void Lista::mostrarEle(int p) const {
		Node * onde = head;
        for(int i = 0; i < p; i++)
            onde = onde->next;
        cout << "\nO valor que está na posião " << p << " é " << onde->valor << ".\n\n";
	}
// metódo esvaziar a lista (destrutor)
	void Lista::esvaziar() {
		Node * aux = head;
		Node * del;
		head = NULL;
		while(aux) {
			del = aux;
			aux = aux->next;
			delete del;
			qtd--;
		}
		delete aux;
		cout << "\nA lista foi esvaziada!\n\n";
	}
// metodo exibir elementos
	void Lista::exibir() const {
        Node * temp = head;
        cout << "A lista tem tamanho " << qtd << ".\n\t[ ";
        int i = 0;
        while (temp) {
            cout << temp->valor;
            if(i++ < qtd-1)
            	cout << ", ";
            temp = temp->next;
        }
        cout << " ].\n";
	}
// metodos get
	int Lista::getQtd() const { return qtd; }