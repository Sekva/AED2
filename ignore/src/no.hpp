#ifndef NO_HPP
#define NO_HPP

class No {

	private:
		//0 desmarcado, 1 marcado
		int marcado;
		int id;

		No* prox;

	public:
		No(int id);


		No* getProx();
		void inserirNo(No* n);

		int getId();


};


#endif
