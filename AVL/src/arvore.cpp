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

	n->setPai(y);

	if(chaveNovoNo < y->getChave()) {
		y->setFilhoEsq(n);
	} else {
		y->setFilhoDir(n);
	}

	this->checarArvore(n);


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

No* Arvore::getRaiz() {
	return this->raiz;
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

void Arvore::checarArvore(No* n) {

	while(n != nullptr) {

		No* fEsq = n->getFilhoEsq();
		No* fDir = n->getFilhoDir();

		int hEsq = 0;
		int hDir = 0;

		if(fEsq != nullptr) {
			hEsq = fEsq->checarAltura();
		} else {
			// std::cout << "fEsq null" << std::endl;
		}

		if(fDir != nullptr) {
			hDir = fDir->checarAltura();
		} else {
			// std::cout << "fDir null" << std::endl;
		}

		int caso = hDir - hEsq;

		n->setBalanco(caso);

		if(n->getBalanco() == -2) {
			if(fEsq->getBalanco() == 1) {
				this->rotSE(n->getFilhoEsq());
			}
			this->rotSD(n);
		}

		if(n->getBalanco() == 2) {
			if(fDir->getBalanco() == -1) {
				this->rotSD(n->getFilhoDir());
			}
			this->rotSE(n);
		}
		n = n->getPai();
	}

}

void Arvore::rotSD(No* p) {
	std::cout << "rotSD" << std::endl;

	No* u = p->getFilhoEsq();
	No* t2 = u->getFilhoDir();

	p->setFilhoEsq(t2);

	if(t2 != nullptr) {
		t2->setPai(p);
	}

	u->setFilhoDir(p);

	No* ancestral = p->getPai();

	if(ancestral == nullptr) {
		this->setRaiz(u);
	} else if(p == ancestral->getFilhoDir()) {
		ancestral->setFilhoDir(u);
	} else if(p == ancestral->getFilhoEsq()) {
		ancestral->setFilhoEsq(u);
	}

	u->setPai(ancestral);
	p->setPai(u);

}

void Arvore::rotSE(No* p) {
	std::cout << "rotSE" << std::endl;

	No* z = p->getFilhoDir();
	No* t2 = z->getFilhoEsq();

	p->setFilhoDir(t2);

	if(t2 != nullptr) {
		t2->setPai(p);
	}

	z->setFilhoEsq(p);

	No* ancestral = p->getPai();

	if(ancestral == nullptr) {
		this->setRaiz(z);
	} else if(p == ancestral->getFilhoDir()) {
		ancestral->setFilhoDir(z);
	} else if(p == ancestral->getFilhoEsq()) {
		ancestral->setFilhoEsq(z);
	}

	z->setPai(ancestral);
	p->setPai(z);



}

void Arvore::rotDD(No* p) {
	std::cout << "rotDD" << std::endl;
	this->rotSE(p->getFilhoEsq());
	this->rotSD(p);
}

void Arvore::rotDE(No* p) {
	std::cout << "rotDE" << std::endl;
	this->rotSD(p->getFilhoDir());
	this->rotSE(p);
}

void Arvore::setRaiz(No* r) {
	this->raiz = r;
}
