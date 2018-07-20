class Vertice {

	private:
		int marcado;
		Vertice *vizinhos;
		int n_vizinhos;

		//atrubutos pra PRIM e KRUSKAL
		int custo;
		Vertice *pai;
		
	public:
		Vertice();
		void add_vizinho(Vertice *v);

};
