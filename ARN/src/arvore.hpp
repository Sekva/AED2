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

		void setRaiz(No* r);

	private:
		void checarArvore(No* n);
		void listarArvore(No* n);
		No* getTio(No* n);
		No* getAvo(No* n);
		void caso1(No* n);
		void rotSD(No* p);
		void rotSE(No* p);
		void caso2Dir(No* n);
		void caso2Esq(No* n);
		void caso3Dir(No* n);
		void caso3Esq(No* n);
};

#endif
