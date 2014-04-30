/* 
 * Lista encadeada de Contas Bancárias
 */
	#ifndef _CONTAS_H_
		#define _CONTAS_H_
	 		#include "Conta.h"
			class Contas : public ContaBancaria {
				ContaBancaria * head;
				int qtd;
				public:
					// Construtor Padrão
						Contas();
					// Metódo para inserir uma nova conta bancária
						void inserir(double s = 0);
					// Metódo para imprimir, na saída padrão, todos os clientes
						void listarContas() const;
					// Metódo para buscar um cliente
						ContaBancaria * buscarConta(int c) const;
					// Função de Deposito em uma conta
						void deposito(double valor, int c);
					// Função de Saque em uma conta
						void saque(double valor, int c);
					// Imprimir Saldo de uma conta
						void saldoConta(int c) const;
					// Metódos Get
						int getQtd() const;
			};
	#endif