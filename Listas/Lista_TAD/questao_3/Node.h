#ifndef _NODE_H_
	#define _NODE_H_
		class Node {
			public:
				int valor;
				Node * next;
				// contrutor padrão
					Node();
				// construtor com parâmetro
					Node(int v);
		};
#endif