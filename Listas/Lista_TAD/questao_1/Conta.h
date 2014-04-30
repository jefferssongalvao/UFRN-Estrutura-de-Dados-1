#ifndef _CONTA_H_
	#define _CONTA_H_
		class ContaBancaria {
			public:
				int conta;
				double saldo;
				ContaBancaria * next;
				// Construtor Padrão
					ContaBancaria();
				// Construtor com Parâmetros
					ContaBancaria(double s, int c);
				// metodos Set
					void setSaldo (double s);
				// Metodos
					double getSaldo() const;
		};
#endif