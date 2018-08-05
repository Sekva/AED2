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


	if (argc < 3) {
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
				Aresta* a = new Aresta(peso, vertices[eu-1], vertices[e-1]);
				arestas.push_back(a);
			}

			if (e == eu) {
				vertices[eu-1]->add_vizinho(vertices[v-1]);
				Aresta* a = new Aresta(peso, vertices[eu-1], vertices[e-1]);
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

	// std::vector<Aresta*> asd = g->getArestas();
	// std::vector<Vertice*> vasd = g->getVertices();
	//
	// for (auto a : vasd) {
	// 	for (int i = 0; i < a->getNVizinhos(); i++) {
	// 		std::cout << a->chave << " de " << a->getVizinhos()[i]->chave << '\n';
	// 	}
	// }
	//
	// for (auto a : asd) {
	// 	std::cout << a->getV1()->chave << a->getV2()->chave << a->getPeso() << '\n';
	// }

	g->prim();


	if (argc > 3 && std::string(argv[3]) == std::string("-s")) {


		if (argc >= 5 && std::string(argv[4]) == std::string("-o")) {
			const char* nome = argv[5];

			try {
				std::ofstream out(nome);
				std::streambuf *coutbuf = std::cout.rdbuf();
				std::cout.rdbuf(out.rdbuf());
				for (int i = 1; i <= g->getVertices().size(); i++) {
					for (int j = 1; j <= g->getVertices().size(); j++) {
						for (Vertice* a : g->getVertices()) {
							if (!(a->getPai() == nullptr)) {
								if (a->getPai()->chave == i && a->chave == j) {
									std::cout << "(" << a->getPai()->chave << "," << a->chave << ") ";
								}
							}
						}

					}
				}
				return 0;
			} catch(...) {
				std::cout << "Erro ao manusear a saida, verifique suas permissões parça" << '\n';
				exit(1);
			}

		}

		for (int i = 1; i <= g->getVertices().size(); i++) {
			for (int j = 1; j <= g->getVertices().size(); j++) {
				for (Vertice* a : g->getVertices()) {
					if (!(a->getPai() == nullptr)) {
						if (a->getPai()->chave == i && a->chave == j) {
							std::cout << "(" << a->getPai()->chave << "," << a->chave << ") ";
						}
					}
				}

			}
		}

		std::cout << '\n';
		return 0;
	} else {
		if (argc > 4 && std::string(argv[3]) == std::string("-o")) {
			const char* nome = argv[4];

			try {
				std::ofstream out(nome);
				std::streambuf *coutbuf = std::cout.rdbuf();
				std::cout.rdbuf(out.rdbuf());
				int soma = 0;
				for (Vertice* a : g->getVertices()) {
					soma += a->getCusto();
				}
				std::cout << soma << '\n';
				return 0;
			} catch(...) {
				std::cout << "Erro ao manusear a saida, verifique suas permissões parça" << '\n';
				exit(1);
			}
		}

		int soma = 0;
		for (Vertice* a : g->getVertices()) {
			soma += a->getCusto();
		}
		std::cout << soma << '\n';
		return 0;
	}

	return 0;

}
