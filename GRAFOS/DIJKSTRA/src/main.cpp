#include <iostream>
#include <fstream>
#include <typeinfo>
#include <sstream>

#include "grafo.hpp"

void printHelp() {
	std::cout << "\n\nUso: ./executavel -f <entrada> [opções]\n" << '\n';
	std::cout << "\tOpções:\n" << '\n';
	std::cout << "\t-h : mostra o help" << '\n';
	std::cout << "\t-o <arquivo> : redireciona a saida para o ‘‘arquivo’’" << '\n';
	std::cout << "\t-f <arquivo> : indica o ‘‘arquivo’’ que contém o grafo de entrada" << '\n';
	std::cout << "\t-s : mostra a solução (em ordem crescente)" << '\n';

	exit(1);
}

int main(int argc, char* argv[]) {


	if (argc <= 4) {
		printHelp();
	}

	if (std::string(argv[1]) != std::string("-f")) {
		printHelp();
	}

	const char* arquivoEntrada = argv[2];
	std::ifstream entrada(arquivoEntrada);

	if (!entrada) {
		std::cout << "Erro ao ler o arquivo " << arquivoEntrada << "\n";
		exit (1);
	}

	Grafo* g = new Grafo();
	std::vector<Vertice*> vertices;
	std::vector<Aresta*> arestas;

	std::string linha;
	int NVTotal, NETotal;

	std::getline(entrada, linha);
	std::string nv = linha.substr(0, linha.find(" "));
	NVTotal = atoi(nv.c_str());
	std::string ne = linha.substr(2, linha.find(" "));
	NETotal = atoi(ne.c_str());



	for (int i = 1; i <= NVTotal; i++) {
		int eu = i;
		int nVizinhos = 0;

		while (std::getline(entrada, linha)) {
			std::stringstream ss(linha);

			std::vector<int> inteiros;
			int s;
			while (ss >> s) {
				inteiros.push_back(s);
			}

			int v = inteiros[0];
			int e = inteiros[1];

			if (v == eu || e == eu) {
				nVizinhos++;
			}

		}
		entrada.clear();
		entrada.seekg(0, std::ios::beg);
		std::getline(entrada, linha);
		Vertice* vertice = new Vertice(nVizinhos, eu);
		vertices.push_back(vertice);
	}



	for (int j = 1; j <= NVTotal; j++) {
		int eu = j;

		while (std::getline(entrada, linha)) {
			std::stringstream ss(linha);

			std::vector<int> inteiros;
			int s;
			while (ss >> s) {
				inteiros.push_back(s);
			}

			int v = inteiros[0];
			int e = inteiros[1];
			int peso = inteiros[2];

			if (peso == 0) {
				peso = 1;
			}

			if (v == eu) {
				vertices[eu-1]->add_vizinho(vertices[e-1]);
			}

			if (e == eu) {
				vertices[eu-1]->add_vizinho(vertices[v-1]);
				Aresta* a = new Aresta(peso, vertices[v-1], vertices[eu-1]);
				arestas.push_back(a);
			}

		}

		entrada.clear();
		entrada.seekg(0, std::ios::beg);
		std::getline(entrada, linha);

	}

	for (Vertice* v : vertices) {
		g->addVertice(v);
	}

	for (Aresta* a : arestas) {
		g->addAresta(a);
	}

	int inicial = 1;
	if (argc > 4 && std::string(argv[3]) == std::string("-i")) {
		inicial = atoi(std::string(argv[4]).c_str());
	} else {
		printHelp();
	}

	if (!inicial || inicial < 0 || inicial > g->getVertices().size()) {
		std::cout << "Ponto inicial (-i) invalido" << '\n';
		exit(1);
	}

	g->dijkstra(g->getVertices()[inicial-1]);

	std::vector<Vertice*> saida = g->getVertices();
	//
	// for(Vertice* a : saida) {
	// 	std::cout << a->chave << ":" <<  a->getCusto() << " ";
	// }


	if (argc > 6 && std::string(argv[5]) == std::string("-l")) {
		int destino = atoi(std::string(argv[6]).c_str());

		if (destino == 0) {
			printHelp();
		}


		if (argc > 8 && std::string(argv[7]) == std::string("-o")) {
			const char* nome = argv[8];

			try {
				std::ofstream out(nome);
				std::streambuf *coutbuf = std::cout.rdbuf();
				std::cout.rdbuf(out.rdbuf());
				for(Vertice* a : saida) {
					if(a->chave == destino) {
						if (a->getCusto() == 999999) {
							std::cout << "Não tem caminho" << '\n';
						} else {
							std::cout << inicial << ":" << a->getCusto() << '\n';
						}
					}
				}
				return 0;
			} catch(...) {
				std::cout << "Erro ao manusear a saida, verifique suas permissões parça" << '\n';
				exit(1);
			}

		}

		for(Vertice* a : saida) {
			if(a->chave == destino) {
				if (a->getCusto() == 999999) {
					std::cout << "Não tem caminho" << '\n';
				} else {
					std::cout << inicial << ":" << a->getCusto() << '\n';
				}
			}
		}

		std::cout << '\n';
	} else {
		if (argc > 6 && std::string(argv[5]) == std::string("-o")) {
			const char* nome = argv[6];

			try {
				std::ofstream out(nome);
				std::streambuf *coutbuf = std::cout.rdbuf();
				std::cout.rdbuf(out.rdbuf());
				for(Vertice* a : saida) {
					std::cout << a->chave << ":" <<  a->getCusto() << " ";
				}
			} catch(...) {
				std::cout << "Erro ao manusear a saida, verifique suas permissões parça" << '\n';
				exit(1);
			}
		}

		for(Vertice* a : saida) {
			std::cout << a->chave << ":" <<  a->getCusto() << " ";
		}
	}

	return 0;

	int** matriz = g->floyd_warshall();
	int tamanho = g->getNV();

	for(int i = 0; i < tamanho; i++) {
		for(int j = 0; j < tamanho; j++) {
			std::cout << matriz[i][j] << " ";
		}
		std::cout << "\n";
	}

	std::cout << "\n\n\n";
	int** roteiro = g->getRoteiro();

	for(int i = 0; i < tamanho; i++) {
		for(int j = 0; j < tamanho; j++) {
			std::cout << roteiro[i][j] << " ";
		}
		std::cout << "\n";
	}

}
