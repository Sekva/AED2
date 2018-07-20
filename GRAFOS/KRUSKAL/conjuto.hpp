#ifndef CONJUNTO_HPP
#define CONJUNTO_HPP

#include "vertice.hpp"

class Conjunto {

	private:
		Vertice** vertices;
		int nVertices;

	public:
		Conjunto();
		int compararConjutos(Conjunto* c);
		void addVertice(Vertice* v);
		void uniConjunto(Conjunto* c);

		int getNVertices();
		Vertice** getVertices();


};

#endif
