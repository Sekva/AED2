#include <iostream>

#include "conjunto.hpp"

int main() {
	
	Vertice* v = new Vertice(2, 1);
	Vertice* v2 = new Vertice(1, 2);
	Vertice* v3 = new Vertice(1, 3);

	v->add_vizinho(v2);
	v->add_vizinho(v3);
	v2->add_vizinho(v);
	v3->add_vizinho(v);

	Aresta* a = new Aresta(1, v, v2);
	Aresta* a2 = new Aresta(1, v, v3);
	
	Conjunto* c = new Conjunto();

	c->addVertice(v2);
	c->addVertice(v3);

	Conjunto* c2 = new Conjunto();
	c2->addVertice(v);


	c->unirConjunto(c2);


	if(c->contemVertice(v)) {
		std::cout << c->getVertices()[c->getVertices().size() - 1]->chave <<"\n";
	}

	

	return 0;
}
