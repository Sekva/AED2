#include <iostream>
#include "no.hpp"


No::No(int chave) {
	this->chave = chave;
	this->prox = nullptr;
}
No* No::getProx() {
	return this->prox;
}

void No::inserirNo(No* n) {
	if(this->prox == nullptr) {
		this->prox = n;
		return;
	}
	this->prox->inserirNo(n);
}

int No::getChave() {
	return this->chave;
}
