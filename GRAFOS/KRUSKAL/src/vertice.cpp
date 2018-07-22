#define TRUE 1
#define FALSE 0

#include "vertice.hpp"

Vertice::Vertice(int nVizinhos, int chave) {
	this->chave = chave;
	this->marcado = FALSE;
	this->n_vizinhos = nVizinhos;
	this->quantidadeVizinhos = 0;
	this-> vizinhos = new Vertice*[n_vizinhos];

	this->custo = 0;
	this->pai = nullptr;
}

void Vertice::add_vizinho(Vertice *v) {
	this->vizinhos[this->quantidadeVizinhos] = v;
	this->quantidadeVizinhos++;
}

Vertice** Vertice::getVizinhos() {
	return this->vizinhos;
}

int Vertice::getCusto() {
	return this->custo;
}

int Vertice::getNVizinhos() {
	return this->n_vizinhos;
}

int Vertice::getMarcado() {
	return this->marcado;
}
