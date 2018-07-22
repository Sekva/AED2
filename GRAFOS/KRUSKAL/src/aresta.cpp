#include <iostream> 
#include "aresta.hpp"

Aresta::Aresta(int peso, Vertice* v1, Vertice* v2) {
	this->peso = peso;
	this->v1 = v1;
	this->v2 = v2;
}

void Aresta::alterarPeso(int peso) {
	this->peso = peso;
}

int Aresta::getPeso() {
	return this->peso;
}

Vertice* Aresta::getV1() {
	return this->v1;
}

Vertice* Aresta::getV2() {
	return this->v2;
}
