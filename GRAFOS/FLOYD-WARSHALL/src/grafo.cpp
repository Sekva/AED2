#include <iostream>
#include <algorithm>
#include <limits>

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

void Grafo::clonarHeap() {

	std::vector<Vertice*> v;
	this->heapMinVertices = v;

	for (int i = 0; i < this->vertices.size() + 1; i++) {
		this->heapMinVertices.push_back(nullptr);
	}

	for(int i = 1; i< this->vertices.size() + 1; i++) {
		this->heapMinVertices[i] = this->vertices[i-1];
	}

}

void Grafo::buildMinHeap() {
	for(int i = (this->heapMinVertices.size()/2); i > 0; i--) {
		this->minHeapfy(i);
	}
}

void Grafo::minHeapfy(int i) {
	int e = 2*i;
	int d = (2*i) + 1;
	int menor = i;

	if(e < this->heapMinVertices.size()
		&& this->heapMinVertices[e]->getCusto() < this->heapMinVertices[i]->getCusto()) {

		menor = e;
	}

	if(d < this->heapMinVertices.size()
		&& this->heapMinVertices[d]->getCusto() < this->heapMinVertices[menor]->getCusto()) {

		menor = d;
	}

	if(menor != i) {
		std::swap(this->heapMinVertices[menor], this->heapMinVertices[i]);
		this->minHeapfy(menor);
	}
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

void Grafo::prim() {

	for (int i = 0; i < this->vertices.size(); i++) {
		this->vertices[i]->setPai(nullptr);
		this->vertices[i]->setCusto(std::numeric_limits<int>::max());
	}


	Vertice* v = this->vertices[0];
	v->setCusto(0);

	this->clonarHeap();
	this->buildMinHeap();


	while(this->heapMinVertices.size() > 1) {
		Vertice* u = this->heapMinVertices[1];
		this->heapMinVertices.erase(this->heapMinVertices.begin()+1);
		this->buildMinHeap();

		int nVizinhos = u->getNVizinhos();
		Vertice** vizinhos = u->getVizinhos();

		u->marcar(1);

		for(int i = 0; i < nVizinhos; i++) {
			if(!vizinhos[i]->getMarcado()) {

				Aresta* a  = nullptr;
				for (int j = 0; j < this->arestas.size(); j++) {
					if ((this->arestas[j]->getV1() == u && this->arestas[j]->getV2() == vizinhos[i])
					 || (this->arestas[j]->getV2() == u && this->arestas[j]->getV1() == vizinhos[i])) {
						a = this->arestas[j];
					}
				}

				if(a == nullptr) {
					return;
				}

				if (vizinhos[i]->getCusto() > a->getPeso()) {
					vizinhos[i]->setCusto(a->getPeso());
					vizinhos[i]->setPai(u);
					this->buildMinHeap();
				}
			}
		}
	}
}

void Grafo::dijkstra(Vertice* s) {

	for(int i = 0; i < this->vertices.size(); i ++) {
		this->vertices[i]->setPai(nullptr);
		this->vertices[i]->setCusto(999999);
	}

	s->setCusto(0);

	this->clonarHeap();
	this->buildMinHeap();

	std::sort(this->arestas.begin(), this->arestas.end(), this->compararArestas);

	while(this->heapMinVertices.size() > 1) {
		Vertice* u = this->heapMinVertices[1];
		this->heapMinVertices.erase(this->heapMinVertices.begin()+1);
		this->buildMinHeap();

		int nVizinhos = u->getNVizinhos();
		Vertice** vizinhos = u->getVizinhos();

		u->marcar(1);

		for(int i = 0; i < nVizinhos; i++) {
			if(!vizinhos[i]->getMarcado()) {

				Aresta* a = nullptr;

				for(int j = 0; j < this->arestas.size(); j++) {
					if (u == this->arestas[j]->getV1() && vizinhos[i] == this->arestas[j]->getV2()){
						a = this->arestas[j];
						break;
					}
				}

				if(!(a == nullptr)) {
					if (vizinhos[i]->getCusto() > u->getCusto() + a->getPeso()) {
						vizinhos[i]->setCusto(u->getCusto() + a->getPeso());
						vizinhos[i]->setPai(u);
						this->buildMinHeap();
					}
				}


			}
		}
	}
}

void Grafo::criarMatriz() {

	int tamanho = this->vertices.size();
	this->matriz = new int*[tamanho];
	this->roteiro = new int*[tamanho];

	for(int i = 0; i < tamanho; i++) {
		this->matriz[i] = new int[tamanho];
		this->roteiro[i] = new int[tamanho];
	}

	int maiorPesoAresta = 0;

	for (Aresta* a : this->arestas) {
		if (maiorPesoAresta < a->getPeso()) {
			maiorPesoAresta = a->getPeso();
		}
	}

	for (int i = 0; i < tamanho; i++) {
		for (int j = 0; j < tamanho; j++) {

			if(i == j) {
				this->matriz[i][j] = 0;
			} else {
				this->matriz[i][j] = 9999999;
			}

			this->roteiro[i][j] = -1;
		}
	}

	for (int i = 0; i < this->arestas.size(); i++) {
		Aresta* a = this->arestas[i];
		this->matriz[(a->getV1()->chave)-1][(a->getV2()->chave)-1] = a->getPeso();
		this->roteiro[(a->getV1()->chave)-1][(a->getV2()->chave)-1] = a->getV1()->chave;
	}
}

int** Grafo::matriz2D() {

	int tamanho = this->vertices.size();

	int** d = new int*[tamanho];
	for(int i = 0; i < tamanho; i++) {
		d[i] = new int[tamanho];
	}

	for(int i = 0; i < tamanho; i++) {
		for(int j = 0; j < tamanho; j++) {
			d[i][j] = std::numeric_limits<int>::max();
		}
	}

	for(int i = 0; i < tamanho; i++) {
		d[i][i] = 0;
	}

	return d;
}

int** Grafo::getRoteiro() {
	return this->roteiro;
}

int** Grafo::floyd_warshall() {

	this->criarMatriz();

	int tamanho = this->vertices.size();

	int** atual = this->matriz;
	for(int k = 0; k < tamanho; k++) {
		for(int i = 0; i < tamanho; i++) {
			for (int j = 0; j < tamanho; j++) {
				if (atual[i][j] > atual[i][k] + atual[k][j]) {
					atual[i][j] = atual[i][k] + atual[k][j];
					this->roteiro[i][j] = this->roteiro[k][j];
				}
			}
		}
	}
	return atual;
}
