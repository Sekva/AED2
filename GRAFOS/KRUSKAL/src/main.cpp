#include <iostream>

#include "grafo.hpp"

int main() {
	
	Vertice* v1 = new Vertice(4, 1);
	Vertice* v2 = new Vertice(4, 2);
	Vertice* v3 = new Vertice(3, 3);
	Vertice* v4 = new Vertice(4, 4);
	Vertice* v5 = new Vertice(3, 5);
		
	v1->add_vizinho(v2);
	v1->add_vizinho(v3);
	v1->add_vizinho(v5);
	v1->add_vizinho(v4);
	
	v2->add_vizinho(v4);
	v2->add_vizinho(v5);
	v2->add_vizinho(v1);
	v2->add_vizinho(v3);

	v3->add_vizinho(v2);
	v3->add_vizinho(v1);
	v3->add_vizinho(v4);
	
	v4->add_vizinho(v1);
	v4->add_vizinho(v3);
	v4->add_vizinho(v2);
	v4->add_vizinho(v5);

	v5->add_vizinho(v4);
	v5->add_vizinho(v1);
	v5->add_vizinho(v2);
	
	Aresta* a1 = new Aresta(3, v1, v2);
	Aresta* a2 = new Aresta(8, v1, v3);
	Aresta* a3 = new Aresta(-4, v1, v5);
	Aresta* a4 = new Aresta(1, v2, v4);
	Aresta* a5 = new Aresta(7, v2, v5);
	Aresta* a6 = new Aresta(4, v3, v2);
	Aresta* a7 = new Aresta(2, v4, v1);
	Aresta* a8 = new Aresta(-5, v4, v3);
	Aresta* a9 = new Aresta(6, v5, v4);
		
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
	g->addAresta(a9);

	std::vector<Aresta*> saida;// = g->kruskal();
	int soma = 0;
	
	int** matriz = g->floyd_warshall();
	int tamanho = g->getNV();

	for(int i = 0; i < tamanho; i++) {
		for(int j = 0; j < tamanho; j++) {
			std::cout << matriz[i][j] << " ";
		}
		std::cout << "\n";
	}
	
	std::cout << "\n\n\n";
	int** roteiro = g->getRoteiro();

	for(int i = 0; i < tamanho; i++) {
		for(int j = 0; j < tamanho; j++) {
			std::cout << roteiro[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}
