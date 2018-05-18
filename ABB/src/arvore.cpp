#include <iostream>


#include "no.hpp"
#include "arvore.hpp"

Arvore::Arvore() {
	this->raiz = nullptr;
	this->altura = 0;
}

void Arvore::inserirNo(No* n) {

	if(this->raiz == nullptr) {
		this->raiz = n;
		return;
	}

	No* y = nullptr;
	No* x = this->raiz;

	int chaveNovoNo = n->getChave();

	while(x != nullptr) {

		y = x;

		if(chaveNovoNo < x->getChave()) {
			x = x->getFilhoEsq();
		} else {
			x = x->getFilhoDir();
		}

	}

	if(chaveNovoNo < y->getChave()) {
		y->setFilhoEsq(n);
	} else {
		y->setFilhoDir(n);
	}


}

No* Arvore::pegarNo(int chave) {

	No* x = this->raiz;

	if(x == nullptr || x->getChave() == chave) {
		return x;
	}

	while(x != nullptr && chave != x->getChave()) {
		if(chave < x->getChave()) {
			x = x->getFilhoEsq();
		} else {
			x = x->getFilhoDir();
		}
	}
	return x;
}

void Arvore::listarArvore(No* n) {

	if(n == nullptr) {
        return;
    }

	this->listarArvore(n->getFilhoEsq());
	std::cout << n->getChave() << std::endl;
	this->listarArvore(n->getFilhoDir());

}

void Arvore::percorrerArvore() {

	this->listarArvore(this->raiz);

}

No* Arvore::getMin() {

	No* n = this->raiz;

	return this->getMin(n);
}

No* Arvore::getMin(No* n) {

	if(n == nullptr) {
		return n;
	}

	while(n->getFilhoEsq() != nullptr) {
		n = n->getFilhoEsq();
	}

	return n;
	
}

No* Arvore::getMax() {

	No* n = this->raiz;
	
	return this->getMax(n);

}

No* Arvore::getMax(No* n) {
	
	if(n == nullptr) {
		return n;
	}

	while(n->getFilhoDir() != nullptr) {
		n = n->getFilhoDir();
	}

	return n;


}


No* Arvore::getAntecessor(No* n) {
	
	if(n == nullptr) {
		return n;
	}

	if(n->getFilhoEsq() != nullptr) {
		return this->getMax(n->getFilhoEsq());
	}

	No* y = n->getPai();

	while(y != nullptr && n == y->getFilhoEsq()) {
		n = y;
		y = y->getPai();
	}

	return n;

}

No* Arvore::getSucessor(No* n) {
	
	if(n == nullptr) {
		return n;
	}

	if(n->getFilhoDir() != nullptr) {
		return this->getMin(n->getFilhoDir());
	}

	No* y = n->getPai();

	while(y != nullptr && n == y->getFilhoDir()) {
		n = y;
		y = y->getPai();
	}

	return n;

}
