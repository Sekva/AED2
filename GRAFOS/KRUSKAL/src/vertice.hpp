#ifndef VERTICE_HPP
#define VERTICE_HPP

class Vertice {

	private:
		int marcado;
		Vertice** vizinhos;
		int n_vizinhos;
		int quantidadeVizinhos;

		//atrubutos pra PRIM e DIJKSTRA
		int custo;
		Vertice *pai;
		int distancia;
		
	public:
		int chave;
		Vertice(int nVizinhos, int chave);
		void add_vizinho(Vertice *v);
		Vertice** getVizinhos();
		int getCusto();
		void setCusto(int custo);
		int getMarcado();
		int getNVizinhos();
		void marcar(int marca);
		void setPai(Vertice* v);
};

#endif
