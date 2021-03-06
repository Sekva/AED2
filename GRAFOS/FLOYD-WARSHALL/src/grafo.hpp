#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "conjunto.hpp"
#include <vector>

class Grafo {
	private:
		int NV;
		int NE;
		std::vector<Vertice*> vertices;
		std::vector<Aresta*> arestas;
		std::vector<Aresta*> heapMinArestas;
		std::vector<Vertice*> heapMinVertices;

		int** matriz;
		int** roteiro;
		void criarMatriz();


		void buildMinHeap();
		void minHeapfy(int i);
		void clonarHeap();

		int** matriz2D();

	public:
		Grafo();
		int getNE();
		int getNV();
		std::vector<Vertice*> getVertices();
		std::vector<Aresta*> getArestas();
		void addVertice(Vertice* v);
		void addAresta(Aresta* a);
		std::vector<Aresta*> getHeapMinArestas();
		
		static bool compararArestas(Aresta* a, Aresta* b);
		
		std::vector<Aresta*> kruskal();
		void prim();
		void dijkstra(Vertice* s);
		int** floyd_warshall();
		int** getRoteiro();
};
#endif
