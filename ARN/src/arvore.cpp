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
		n->setCor(1);
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
		std::cout << "X";
        return;
    }

	std::cout << " (";
	std::cout << n->getChave();


	if(n->getFilhoEsq() != nullptr && n->getFilhoDir() != nullptr) {
		this->listarArvore(n->getFilhoEsq());
		this->listarArvore(n->getFilhoDir());
	} else if(n->getFilhoEsq() != nullptr) {
		this->listarArvore(n->getFilhoEsq());
		std::cout << " (X)";
	} else if(n->getFilhoDir() != nullptr) {
		std::cout << " (X)";
		this->listarArvore(n->getFilhoDir());
	}

	std::cout << ")";

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

	No* pai = n->getPai();

	if(pai == nullptr) {
		std::cout << "raiz" << std::endl;
		n->setCor(1);
		return;
	}

	if(pai->getCor() == 1) {
		return;
	}

	No* avo = pai->getPai();

	if(avo == nullptr) {
		return;
	}

	No* tio = this->getTio(n);

	if(tio != nullptr) {
		if(tio->getCor() == 0) {
			// std::cout << tio->getCor() << std::endl;
			this->caso1(n);
			return;
		}
	}

	if(n == pai->getFilhoDir() && tio == avo ->getFilhoDir()){
		this->caso2Dir(n);
	} else if(n == pai->getFilhoEsq() && tio == avo ->getFilhoEsq()) {
		this->caso2Esq(n);
	} else if(n == pai->getFilhoDir() && tio == avo ->getFilhoEsq()){
		this->caso3Dir(n);
	} else if(n == pai->getFilhoEsq() && tio == avo ->getFilhoDir()) {
		this->caso3Esq(n);
	}

}

void Arvore::setRaiz(No* r) {
	this->raiz = r;
}

No* Arvore::getTio(No* n) {

	No* avo = this->getAvo(n);

	if(avo == nullptr) {
		return nullptr;
	}

	No* pai = n->getPai();
	No* p1 = avo->getFilhoDir();
	No* p2 = avo->getFilhoEsq();

	if(p1 == pai) {
		return p2;
	} else {
		return p1;
	}

}

No* Arvore::getAvo(No* n) {

	if(n == nullptr) {
		return nullptr;
	}

	No* pai = n->getPai();

	if(pai == nullptr) {
		return nullptr;
	}

	return pai->getPai();

}

void Arvore::rotSD(No* p) {
	// std::cout << "rotSD" << std::endl;

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
	// std::cout << "rotSE" << std::endl;

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

void Arvore::caso1(No* n) {

	std::cout << "caso 1" << std::endl;

	if(n == nullptr) {
		return;
	}

	No* tio = this->getTio(n);
	No* avo = this->getAvo(n);
	No* pai = n->getPai();

	if(pai != nullptr) {
		pai->setCor(1);
	}

	if(tio != nullptr) {
		tio->setCor(1);
	}

	if(avo != nullptr) {
		avo->setCor(0);
	}

	this->checarArvore(avo);


}

void Arvore::caso2Esq(No* n) {

	std::cout << "caso 2" << std::endl;


	No* novoCentro = n->getPai();

	this->rotSD(novoCentro);

	this->caso3Dir(novoCentro);

}

void Arvore::caso2Dir(No* n) {

	std::cout << "caso 2" << std::endl;


	No* novoCentro = n->getPai();

	this->rotSE(novoCentro);

	this->caso3Esq(novoCentro);

}

void Arvore::caso3Esq(No* n) {

	std::cout << "caso 3" << std::endl;

	No* pai = n->getPai();
	No* avo = this->getAvo(n);

	this->rotSD(avo);

	avo->setCor(0);
	pai->setCor(1);

}

void Arvore::caso3Dir(No* n) {

	std::cout << "caso 3" << std::endl;

	No* pai = n->getPai();
	No* avo = this->getAvo(n);

	this->rotSE(avo);

	avo->setCor(0);
	pai->setCor(1);


}
