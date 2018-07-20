#include <stdio.h>
#include <stdlib.h>

int* p = NULL;
int* ordem = NULL;

void MAKE_SET(int x) {
	p[x] = x;
	ordem[x] = 0;
}

void LINK(int x, int y) {

	if(ordem[x] > ordem[y]) {
		p[y] = x;
	} else {
		p[x] = y;
	}

	if(ordem[x] == ordem[y]) {
		ordem[y]++;
	}

}

int FIND_SET(int x) {
	if (x != p[x]) {
		p[x] = FIND_SET(p[x]);
	}

	return p[x];

}

void UNION(int x, int y) {
	LINK(FIND_SET(x), FIND_SET(y));
}


typedef struct aresta {

	int u;
	int v;
	int peso;

} Aresta;


typedef struct grafo {

	int* V;
	Aresta* E;

	int nV;
	int nE;



} Grafo;


Aresta* MST_KRUSKAL(Grafo* g) {

	Aresta A[9];
	int nA = 0;




	for (int i = 0; i < g->nV; i++) {
		MAKE_SET(g->V[i]);
	}


	Aresta arestas[g->nE];




	for (int j = 0; j < g->nE; j++) {
		arestas[j] = g->E[j];
		printf("%d\n", g->E[j].peso);
	}



	for (int k  = 0; k < g->nE; k++) {
		for (int l = 0; l < g->nE; l++) {

			if (arestas[l].peso > arestas[k].peso) {
				Aresta a = arestas[k];
				arestas[k] = arestas[l];
				arestas[l] = a;
			}

		}
	}



	for (int m = 0; m < g->nE; m++) {
		if (FIND_SET(arestas[m].u) != arestas[m].v) {
			A[nA] = arestas[m];
			nA++;
			UNION(arestas[m].u, arestas[m].v);
		}
	}

	return A;

}


int main() {

	int init[] = {};
	int init2[] = {};

	p = init;
	ordem = init2;



	Grafo g;


	g.nV = 6;
	int asd[] = {1, 2, 3, 4, 5, 6};
	g.V = asd;

	g.nE = 9;

	Aresta e1, e2, e3, e4, e5, e6, e7, e8, e9;

	e1.u = 1;
	e1.v = 2;
	e1.peso = 4;

	e2.u = 1;
	e2.v = 3;
	e2.peso = 1;

	e3.u = 1;
	e3.v = 4;
	e3.peso = 3;



	e4.u = 2;
	e4.v = 3;
	e4.peso = 4;


	e5.u = 2;
	e5.v = 4;
	e5.peso = 4;


	e6.u = 3;
	e6.v = 4;
	e6.peso = 2;


	e7.u = 3;
	e7.v = 6;
	e7.peso = 4;


	e8.u = 4;
	e8.v = 6;
	e8.peso = 6;


	e9.u = 5;
	e9.v = 6;
	e9.peso = 5;

	printf("%d\n", e8.peso);

	MST_KRUSKAL(&g);




	return 0;
}
