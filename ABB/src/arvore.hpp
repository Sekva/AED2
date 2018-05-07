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
		No* getMin();
		No* getMax();
		No* getAntecessor();

	private:
		void listarArvore(No* n);


};

#endif
