#include <iostream>
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

}

void Grafo::buildMinHeap() {
	this->heapMinArestas = this->arestas;
	this->heapMinArestas.push_back(nullptr);
	for(int i = this->heapMinArestas.size() - 1; i > 0; i++) {
		this->heapMinArestas[i] = this->heapMinArestas[i-1];
	}
	this->heapMinArestas[0] = this->heapMinArestas.size() - 1;



	for () {

	}
}

void Grafo::minHeapfy() {

}
