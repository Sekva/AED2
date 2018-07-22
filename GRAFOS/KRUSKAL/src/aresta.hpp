#ifndef ARESTA_HPP
#define ARESTA_HPP

#include "vertice.hpp"
class Aresta {
	private:
		int peso;
		Vertice* v1;
		Vertice* v2;
	public:	
		Aresta(int peso, Vertice* v1, Vertice* v2);
		void alterarPeso(int peso);
		int getPeso();
		Vertice* getV1();
		Vertice* getV2();
};

#endif
