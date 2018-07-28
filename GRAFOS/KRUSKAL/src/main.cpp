#include <iostream>

#include "grafo.hpp"

int main() {
	
	Vertice* v1 = new Vertice(2, 1);
	Vertice* v2 = new Vertice(4, 2);
	Vertice* v3 = new Vertice(4, 3);
	Vertice* v4 = new Vertice(2, 4);
	Vertice* v5 = new Vertice(2, 5);
	
	v1->add_vizinho(v2);
	v1->add_vizinho(v3);
	
	v2->add_vizinho(v1);
	v2->add_vizinho(v3);
	v2->add_vizinho(v4);
	v2->add_vizinho(v5);

	v3->add_vizinho(v1);
	v3->add_vizinho(v2);
	v3->add_vizinho(v4);
	v3->add_vizinho(v5);

	v4->add_vizinho(v2);
	v4->add_vizinho(v3);
	
	v5->add_vizinho(v2);
	v5->add_vizinho(v3);

	Aresta* a1 = new Aresta(4, v1, v2);
	Aresta* a2 = new Aresta(2, v1, v3);
	Aresta* a3 = new Aresta(1, v3, v2);
	Aresta* a4 = new Aresta(3, v2, v3);
	Aresta* a5 = new Aresta(2, v2, v4);
	Aresta* a6 = new Aresta(3, v2, v5);
	Aresta* a7 = new Aresta(4, v3, v4);
	Aresta* a8 = new Aresta(5, v3, v5);

	
	Grafo* g = new Grafo();

	g->addVertice(v2);
	g->addVertice(v1);
	g->addVertice(v3);
	g->addVertice(v4);
	g->addVertice(v5);

	g->addAresta(a1);
	g->addAresta(a2);
	g->addAresta(a3);
	g->addAresta(a4);
	g->addAresta(a5);
	g->addAresta(a6);
	g->addAresta(a7);
	g->addAresta(a8);

	std::vector<Aresta*> saida;// = g->kruskal();
	int soma = 0;
	
	g->dijkstra(v1);

	std::vector<Vertice*> vertices = g->getVertices();
	//std::cout << vertices.size() << "  asd\n";
	

	for (int i = 0; i < vertices.size(); i++) {
		Vertice* v  = vertices[i];
		std::cout << "V1 PARA " << v->chave << " DIST: " << v->getCusto() << "\n";	
		

	}

	return 0;

	for(Aresta* a : saida) {
		std::cout << a->getPeso() << " v1: " << a->getV1()->chave << " v2: " << a->getV2()->chave << "\n";
		soma += a->getPeso();
	}

	std::cout << "\n" << soma << "\n";


	return 0;
}
