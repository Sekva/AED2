#ifndef NO_HPP
#define NO_HPP

class No {

	private:
		No* esq;
		No* dir;
		No* pai;
		int chave;
		int cor;
	public:

		No(int chave);

		void setFilhoEsq(No* filho);
		void setFilhoDir(No* filho);
		void setPai(No* pai);
		void setCor(int c);

		No* getFilhoEsq();
		No* getFilhoDir();
		No* getPai();
		int getCor();

		int getChave();
		int checarAltura();
		bool isRaiz();

	private:
		int altura(No* n);

};
#endif
