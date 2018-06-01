#include <iostream>
#include <fstream>
#include <typeinfo>


#include "no.hpp"
#include "arvore.hpp"

#include "funcoes.h"


int main(int argc, char *argv[]) {

	if(argc == 1) {
		std::cout << "ERRO: parâmetros conflitantes" << '\n';
    printHelp();
    return 1;
	}

	if(std::string(argv[1]) == "-h" && argc == 2) {
		printHelp();
		return 0;
	}

	if(argc > 5) {
    std::cout << "ERRO: parâmetros conflitantes" << '\n';
    printHelp();
    return 1;
  }

  if(std::string(argv[1]) != "-f") {
    std::cout << "ERRO: parâmetros conflitantes" << '\n';
    printHelp();
    return 1;
  }

	const char* arquivoEntrada = argv[2];
	std::cout << "Cosntruindo arvore a partir de: " << arquivoEntrada << '\n';
	std::ifstream entrada(arquivoEntrada);

	if(!entrada) {
	std::cout << "Arquivo nao lido" << "\n";
	return 1;
}

	std::string linha;
	Arvore t;
	No* n = nullptr;

	while (std::getline(entrada, linha)) {

		int chave = atoi(linha.c_str());
		n = new No(chave);
		t.inserirNo(n);

	}

	if(argc == 3) {
		arvoreCompleta(&t);
		return 0;
	}

	if(std::string(argv[3]) == "-o") {
		const char* nome = argv[4];

		try {
			std::ofstream out(nome);
			std::streambuf *coutbuf = std::cout.rdbuf();
			std::cout.rdbuf(out.rdbuf());
			t.percorrerArvore();
			return 0;
		} catch(...) {
			std::cout << "Erro ao manusear a saida, verifique suas permissões parça" << '\n';
			return 1;
		}
		return 0;
	}

	if(std::string(argv[3]) == "-h") {
		printHelp();
		return 0;
	}

	if(std::string(argv[3]) == "-m") {
		imprimirMenor(&t);
		return 0;
	}

	if(std::string(argv[3]) == "-M") {
		imprimirMaior(&t);
		return 0;
	}

	if(std::string(argv[3]) == "-a") {
		if(!argv[4]) {
			std::cout << "ERRO: parâmetros conflitantes" << '\n';
	    printHelp();
	    return 1;
		}

		std::string str = argv[4];
		std::string::size_type sz;

		int chave;
		try {
			chave = std::stoi(str,&sz);
		} catch(std::invalid_argument) {
			std::cout << "ERRO: parâmetros conflitantes" << '\n';
			printHelp();
			return 1;
		}

		imprimirAntecessor(&t, chave);

		return 0;
	}

	if(std::string(argv[3]) == "-s") {
		if(!argv[4]) {
			std::cout << "ERRO: parâmetros conflitantes" << '\n';
			printHelp();
			return 1;
		}

		std::string str = argv[4];
		std::string::size_type sz;

		int chave;
		try {
			chave = std::stoi(str,&sz);
		} catch(std::invalid_argument) {
			std::cout << "ERRO: parâmetros conflitantes" << '\n';
			printHelp();
			return 1;
		}

		imprimirSucessor(&t, chave);

		return 0;
	}
	return 0;
}
