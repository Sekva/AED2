#include <iostream>
#include "conjunto.hpp"

Conjunto::Conjunto() {

	this->nVertices = 0;
	this->vertices = nullptr;

}

int Conjunto::getNVertices() {
	return this->nVertices;
}

Vertice** Conjunto::getVertices() {
	return this->vertices;
}

int Conjunto::compararConjuntos(Conjunto* c) {

	for (int i = 0; i < this->nVertices; i++) {
		Vertice* v = this->vertices[i];

		for (int j = 0; j < c->getNVertices(); j++) {
			Vertice* u = c->getVertices()[j];
			if (u == v) {
				return 1;
			}
		}
	}

	return 0;

}

void addVertice(Vertice* v) {

	this->vertices[nVertices] = n;
	this->nVertices++;

}

void unirConjunto(Conjunto* c) {

	int j = 0;
	for (int i = this->nVertices; i < (this->nVertices + c->getNVertices()) ; i++) {
		this->vertices[i] = c->getVertices()[j];
		j++;
	}

	this->nVertices += c->getNVertices();

	delete c;

}
