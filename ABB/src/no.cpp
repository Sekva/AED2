
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

int No::checarAltura() {

	if (this->esq == nullptr && this->dir == nullptr) {
		return 0;
	}
		
	if (this->dir == nullptr && this->esq != nullptr) {
		return (this->esq->checarAltura() + 1);
	}

	if (this->esq == nullptr && this->dir != nullptr) {
		return (this->dir->checarAltura() +1);
	}

	int hEsq;
	int hDir;

	hEsq = this->esq->checarAltura() + 1;
	hDir = this->dir->checarAltura() + 1;

	if (hEsq < hDir) {
		return hDir;
	} else {
		return hEsq;
	}
}

bool No::isRaiz() {

	if(this->pai == nullptr) {
		return true;
	} else {
		return false;
	}

}







