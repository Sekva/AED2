#define TRUE 1
#define FALSE 0

#include "vertice.hpp"

Vertice::Vertice() {
	
	this->marcado = FALSE;
	this->n_vizinhos = 0;

	this-> vizinhos = nullptr;

	this->custo = 0;
	this->pai = nullptr;


}

void Vertice::add_vizinho(Vertice *v) {

	if (this->vizinhos == nullptr) {
		this->vizinhos = v;
		this->n_vizinhos++;
	}
	else {
		this->vizinhos->add_vizinho(v);
	}


}
