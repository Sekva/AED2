#ifndef ARVORE_HPP
#define ARVORE_HPP

#include "no.hpp"

class Arvore {

	private:
		No* raiz;
		int altura;

	public:
		Arvore();
		void inserirNo(No* n);
		No* pegarNo(int chave);
		void percorrerArvore();
		No* getRaiz();
		No* getMin();
		No* getMin(No* n);
		No* getMax();
		No* getMax(No* n);
		No* getAntecessor(No* n);
		No* getSucessor(No* n);

	private:
		void listarArvore(No* n);
};

#endif
