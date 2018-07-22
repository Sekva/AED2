#include <iostream>
#include <algorithm>
#include "grafo.hpp"

Grafo::Grafo() {
	this->NE = 0;
	this->NV = 0;
	std::vector<Vertice*> v;
	std::vector<Aresta*> a;
	this->vertices = v;
	this->arestas = a;
}

int Grafo::getNE() {
	return this->NE;
}

int Grafo::getNV() {
	return this->NV;
}

std::vector<Vertice*> Grafo::getVertices() {
	return this->vertices;
}

std::vector<Aresta*> Grafo::getArestas() {
	return this->arestas;
}

void Grafo::addVertice(Vertice* v) {
	this->vertices.push_back(v);
	this->NV = this->vertices.size();
}

void Grafo::addAresta(Aresta* a) {
	this->arestas.push_back(a);
	this->NE = this->arestas.size();
}

std::vector<Aresta*> Grafo::getHeapMinArestas() {
	return this->arestas;
}

void Grafo::buildMinHeap() {
}

void Grafo::minHeapfy() {
}

bool Grafo::compararArestas(Aresta* a, Aresta*b) {
	return a->getPeso() < b->getPeso();
}

std::vector<Aresta*> Grafo::kruskal() {
	
	std::vector<Conjunto*> conjuntos;
	Conjunto* c;
	for(int i = 0; i < this->vertices.size(); i++) {
		c = new Conjunto();
		c->addVertice(this->vertices[i]);
		conjuntos.push_back(c);
	}

	std::vector<Aresta*> x;

	std::sort(this->arestas.begin(), this->arestas.end(), this->compararArestas);

	for(int i = 0; i < this->arestas.size(); i++) {
		Vertice* v1 = this->arestas[i]->getV1();
		Vertice* v2 = this->arestas[i]->getV2();

		Conjunto* cV1;
		Conjunto* cV2;

		int indexCV1;
		int indexCV2;

		for(int j = 0; j < conjuntos.size(); j++) {
			if(conjuntos[j]->contemVertice(v1)) {
				cV1 = conjuntos[j];
				indexCV1 = j;
			}
			if(conjuntos[j]->contemVertice(v2)) {
				cV2 = conjuntos[j];
				indexCV2 = j;
			}
		}

		if (cV1 != cV2) {
			x.push_back(this->arestas[i]);
			cV1->unirConjunto(cV2);
			conjuntos.erase(conjuntos.begin() + indexCV2);
		}
	}
	return x;

}
