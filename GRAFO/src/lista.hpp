#ifndef LISTA_HPP
#define LISTA_HPP

class Lista {

	private:
		int tamanho;

		No** lista;

	public:
		Lista();

		void inserirNo(int vertice, No* n);

		No** getLista();

		No** getAdjacentes(int vertice);

		//só pra facilitar no main
		printarLista();


};

#endif
