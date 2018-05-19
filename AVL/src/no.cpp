
#include "no.hpp"

No::No(int chave) {
	this->chave = chave;
	this->esq = nullptr;
	this->dir = nullptr;
	this->pai = nullptr;
}

void No::setFilhoEsq(No* filho) {
	this->esq = filho;
}

void No::setFilhoDir(No* filho) {
	this->dir = filho;
}

void No::setBalanco(int b) {
	this->balanco = b;
}

void No::setPai(No* pai) {
	this->pai = pai;
}

No* No::getFilhoEsq() {
	return this->esq;
}

No* No::getFilhoDir() {
	return this->dir;
}

No* No::getPai() {
	return this->pai;
}

int No::getChave() {
	return this->chave;
}

int No::getBalanco() {
	return this->balanco;
}

int No::checarAltura() {

	return this->altura(this);

}

bool No::isRaiz() {

	if(this->pai == nullptr) {
		return true;
	} else {
		return false;
	}

}

int No::altura(No* n) {
	if(n == nullptr) {
		return 0;
	}

	if(this->altura(n->getFilhoEsq()) > this->altura(n->getFilhoDir())) {
		return this->altura(n->getFilhoEsq()) + 1;
	} else {
		return this->altura(n->getFilhoDir()) + 1;
	}

}
