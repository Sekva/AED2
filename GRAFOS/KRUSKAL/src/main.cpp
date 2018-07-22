#include <iostream>

#include "grafo.hpp"

int main() {
	
	Vertice* v1 = new Vertice(3, 1);
	Vertice* v2 = new Vertice(3, 2);
	Vertice* v3 = new Vertice(4, 3);
	Vertice* v4 = new Vertice(4, 4);
	Vertice* v5 = new Vertice(1, 5);
	Vertice* v6 = new Vertice(3, 6);

	Aresta* a1 = new Aresta(4, v1, v2);
	Aresta* a2 = new Aresta(1, v1, v3);
	Aresta* a3 = new Aresta(3, v1, v4);
	Aresta* a4 = new Aresta(4, v2, v3);
	Aresta* a5 = new Aresta(4, v2, v4);
	Aresta* a6 = new Aresta(2, v3, v4);
	Aresta* a7 = new Aresta(4, v3, v6);
	Aresta* a8 = new Aresta(6, v4, v6);
	Aresta* a9 = new Aresta(5, v5, v6);

	
	Grafo* g = new Grafo();

	g->addVertice(v2);
	g->addVertice(v1);
	g->addVertice(v3);
	g->addVertice(v4);
	g->addVertice(v5);
	g->addVertice(v6);

	g->addAresta(a1);
	g->addAresta(a2);
	g->addAresta(a3);
	g->addAresta(a4);
	g->addAresta(a5);
	g->addAresta(a6);
	g->addAresta(a7);
	g->addAresta(a8);
	g->addAresta(a9);

	std::vector<Aresta*> saida = g->kruskal();
	int soma = 0;

	for(Aresta* a : saida) {
		std::cout << a->getPeso() << " v1: " << a->getV1()->chave << " v2: " << a->getV2()->chave << "\n";
		soma += a->getPeso();
	}

	std::cout << "\n" << soma << "\n";


	return 0;
}
