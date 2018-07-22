#ifndef CONJUNTO_HPP
#define CONJUNTO_HPP
#include "aresta.hpp"
#include <vector>
class Conjunto {
	private:
		std::vector<Vertice*> vertices;
		int nVertices;
	public:
		Conjunto();
		int compararConjuntos(Conjunto* c);
		void addVertice(Vertice* v);
		void unirConjunto(Conjunto* c);
		int contemVertice(Vertice* v);
		int getNVertices();
		std::vector<Vertice*> getVertices();
};

#endif
