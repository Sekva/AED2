#ifndef NO_HPP
#define NO_HPP

class No {

	private:
		No* esq;
		No* dir;
		No* pai;
		int chave;
	public:

		No(int chave);

		void setFilhoEsq(No* filho);
		void setFilhoDir(No* filho);
		void setPai(No* pai);

		No* getFilhoEsq();
		No* getFilhoDir();
		No* getPai();

		int getChave();
		int checarAltura();
		bool isRaiz();

};
#endif
