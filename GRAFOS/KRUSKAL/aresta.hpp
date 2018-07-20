#ifndef ARESTA_HPP
#define ARESTA_HPP

#include "vertice.hpp"

class Aresta {
	
	private:
		int peso;
		Vertice* v1;
		Vertice* v2;
	public:	
		Aresta(int peso, Vertice* p1, Vertice* p2);
		void alterarPeso(int peso);
};








#endif
