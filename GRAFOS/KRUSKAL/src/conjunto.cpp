#include <iostream>
#include "conjunto.hpp"

Conjunto::Conjunto() {
	this->nVertices = 0;
	std::vector<Vertice*> v;
	this->vertices = v;
}

int Conjunto::getNVertices() {
	return this->nVertices;
}

std::vector<Vertice*> Conjunto::getVertices() {
	return this->vertices;
}

int Conjunto::compararConjuntos(Conjunto* c) {
	for (int i = 0; i < this->vertices.size(); i++) {
		Vertice* v = this->vertices[i];
		for (int j = 0; j < c->getVertices().size(); j++) {
			Vertice* u = c->getVertices()[j];
			if (u == v) {
				return 1;
			}
		}
	}
	return 0;
}

void Conjunto::addVertice(Vertice* v) {
	this->vertices.push_back(v);
}

void Conjunto::unirConjunto(Conjunto* c) {
	for (int i = 0; i < c->getVertices().size(); i++) {
		Vertice* v = c->getVertices()[i];
		this->vertices.push_back(v);
	}
	delete c;
}

int Conjunto::contemVertice(Vertice* v) {
	for (int i = 0; i < this->vertices.size(); i++) {
		if(this->vertices[i] == v) {
			return 1;
		}
	}
	return 0;
}
