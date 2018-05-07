
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
	return 13;
}

bool No::isRaiz() {

	if(this->pai == nullptr) {
		return true;
	} else {
		return false;
	}

}







