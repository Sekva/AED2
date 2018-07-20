#include <iostream> 
#include "aresta.hpp"
#include "vertice.hpp"

Aresta::Aresta(int peso, Vertice* p1, Vertice* p2) {
	this->peso = peso;
	this->p1 = p1;
	this->p2 = p2;
}

void Aresta::alterarPeso(int peso) {
	this->peso = peso;
}

