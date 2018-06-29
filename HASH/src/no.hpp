#ifndef NO_HPP
#define NO_HPP

class No {

	private:
		int chave;
		No* prox;
	public:
		No(int chave);
		No* getProx();
		int getChave();
		void inserirNo(No* n);
};





#endif
