/* 
 * Lista encadeada de Contas Bancárias
 */
 	#include <iostream>
 	#include <iomanip>
 	// Classe de conta bancária
		#include "Conta.h"

	#include "Contas.h"

 	using std::cout;
	using std::fixed;
	using std::setprecision;

	// Construtor Padrão
		Contas::Contas() { head = NULL; qtd = 0; }
	// Metódo para inserir uma nova conta bancária
		void Contas::inserir(double s) {
			ContaBancaria * novo = new ContaBancaria(s, ++qtd);
	        if (head == NULL)
	            head = novo;
	        else {
	            ContaBancaria * onde = head;
	            while (onde->next)
	                onde = onde->next;
	            onde->next = novo;
	        }
		}
	// Metódo para imprimir, na saída padrão, todas as contas bancárias
		void Contas::listarContas() const {
	        ContaBancaria * temp = head;
	        cout << "As contas são:\n";
	        while (temp) {
	            cout << "\tConta: " << temp->conta << "\n";
	            cout << "\t\tSaldo Atual: R$ " << temp->saldo << ".\n";
	            temp = temp->next;
	        }
	        cout << "\n";
		}
	// Metódo para buscar uma conta
		ContaBancaria * Contas::buscarConta(int c) const {
	        ContaBancaria * temp = head;
	        while (temp->conta != c) {
	            temp = temp->next;
	        }
	        return temp;
	    }
	// Função de Deposito em uma conta
		void Contas::deposito(double valor, int c) {
			ContaBancaria * aux = buscarConta(c);
			aux->setSaldo(aux->getSaldo()+valor);
			cout << "Deposito realizado com sucesso!\n";
		}
	// Função de Saque em uma conta
		void Contas::saque(double valor, int c) {
			ContaBancaria * aux = buscarConta(c);
			if(aux->getSaldo() >= valor){
				aux->setSaldo(aux->getSaldo()-valor);
				cout << "Saque realizado com sucesso!\n";
			} else
				cout << "O valor de saque é maior que o saldo disponível!\n";
		}
	// Imprimir Saldo de uma conta
		void Contas::saldoConta(int c) const {
			ContaBancaria * aux = buscarConta(c);
			cout << fixed << setprecision(2);
			cout << "O saldo em conta é R$ " << aux->getSaldo() << ".\n";
		}
	// Metódos Get
		int Contas::getQtd() const { return qtd; }
