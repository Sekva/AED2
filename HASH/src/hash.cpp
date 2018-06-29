#include <iostream>
#include "hash.hpp"
#include "no.hpp"


//Inicializa o hash com o tamanho definido e limpa todas as posições
Hash::Hash(int tamanho) {

	this->tamanho = tamanho;

	this->cabecas = new No*[tamanho];

	for(int i = 0; i < this->tamanho; i++) {
		this->cabecas[i] = nullptr;
	}

}

//Metodo de divisão simples para indexar a partir do resto
int Hash::calcularIndex(int chave) {
	return chave % this->tamanho;
}


//Inserção no array a partir do index definido pela função hash, e depois
//adiciona elemento na lista normalmente.
void Hash::inserirNo(No* n) {

	int chaveNo = n->getChave();
	int index = this->calcularIndex(chaveNo);

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
