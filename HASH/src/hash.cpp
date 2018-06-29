#include <iostream>
#include "hash.hpp"
#include "no.hpp"



Hash::Hash(int tamanho) {
	
	this->tamanho = tamanho;
	
	this->cabecas = new No*[tamanho];

	for(int i = 0; i < this->tamanho; i++) {
		this->cabecas[i] = nullptr;
	}

}

int Hash::calcularIndex(int chave) {
	return chave % this->tamanho;
	
}


void Hash::inserirNo(No* n) {
	

	
	int chaveNo = n->getChave();
	int index = this->calcularIndex(chaveNo);
	//std::cout << index << "\n";
	
	
	No* gaveta = this->cabecas[index];

	if(gaveta == nullptr) {
		this->cabecas[index] = n;
	} else {
		gaveta->inserirNo(n);
	}

	return;
}

No** Hash::getHash() {
	return this->cabecas;
}
