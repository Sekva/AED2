#ifndef HASH_HPP
#define HASH_HPP
#include "no.hpp"

class Hash {

	private:
		int tamanho;
		No** cabecas;

		int calcularIndex(int chave);

	public:
		Hash(int tamanho);
		void inserirNo(No* n);
		No** getHash();



};



#endif
