class Vertice {

	private:
		int marcado;
		Vertice** vizinhos;
		int n_vizinhos;
		int quantidadeVizinhos;

		//atrubutos pra PRIM e KRUSKAL
		int custo;
		Vertice *pai;
		
	public:
		int chave;
		Vertice(int nVizinhos, int chave);
		void add_vizinho(Vertice *v);
		Vertice** getVizinhos();
		int getCusto();
		int getMarcado();
		int getNVizinhos();

};
