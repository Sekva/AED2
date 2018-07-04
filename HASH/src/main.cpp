#include <iostream>
#include <fstream>
#include <typeinfo>
#include "no.hpp"
#include "hash.hpp"


void printHelp() {
  std::cout << "\n\nUso: ./executavel -f <entrada> [opções]\n" << '\n';
  std::cout << "\tOpções:\n" << '\n';
  std::cout << "\t-h : mostra o help" << '\n';
  std::cout << "\t-o <arquivo> : redireciona a saida para o ‘‘arquivo’’" << '\n';
  std::cout << "\t-f <arquivo> : indica o ‘‘arquivo’’ que contém os dados a serem adicionados na Hash" << '\n';
  std::cout << "\t-m : indica que a estrutura será uma heap mínima" << '\n';
}

int main(int argc, char* argv[]) {

  ////////////////////////////////////////////////////////////////////////////
  //Checagem dos parametros

  ////////////////////////////////////////////////////////////////////////////

  //Tamanho padrao do HASH
  int tamanhoHash = 11;


  Hash* hash = nullptr;

  //Falta argumentos
  if (argc == 1) {
    std::cout << "ERRO: parâmetros conflitantes" << '\n';
    printHelp();
    return 1;
  }

  //Help chamado como primeiro argumento
  if (argc == 2 && std::string(argv[1]) == "-h") {
    std::cout << "ERRO: parâmetros conflitantes" << '\n';
    printHelp();
    return 0;
  }

  ////////////////////////////////////////////////////////////////////////////
  //Pegando tamanho do hash se informado
  if(argc > 2 && std::string(argv[1]) == "-m") {
    try {
      tamanhoHash = atoi(argv[2]);
    } catch (...) {
      std::cout << "ERRO: parâmetros conflitantes" << '\n';
      printHelp();
      return 1;
    }
  }

  if (argc > 4 && std::string(argv[3]) == "-m") {
    try {
      tamanhoHash = atoi(argv[4]);
    } catch (...) {
      std::cout << "ERRO: parâmetros conflitantes" << '\n';
      printHelp();
      return 1;
    }
  }

  hash = new Hash(tamanhoHash);

  ////////////////////////////////////////////////////////////////////////////
  //Buscando entradas dos arquivos

  if(argc > 2 && std::string(argv[1]) == "-f") {
    try {

      const char* arquivoEntrada = argv[2];
    	std::ifstream entrada(arquivoEntrada);

    	if(!entrada) {
    	   std::cout << "Arquivo nao lido" << "\n";
    	    return 1;
      }

    	std::string linha;
    	No* n = nullptr;

    	while (std::getline(entrada, linha)) {
    		int chave = atoi(linha.c_str());
    		n = new No(chave);
    		hash->inserirNo(n);
    	}

    } catch (...) {
      std::cout << "Problema ao ler o arquivo." << '\n';
      printHelp();
      return 1;
    }
  }

  if(argc > 4 && std::string(argv[3]) == "-f") {
    try {

      const char* arquivoEntrada = argv[4];
    	std::ifstream entrada(arquivoEntrada);

    	if(!entrada) {
    	   std::cout << "Arquivo nao lido" << "\n";
    	    return 1;
      }

    	std::string linha;
    	No* n = nullptr;

    	while (std::getline(entrada, linha)) {
    		int chave = atoi(linha.c_str());
    		n = new No(chave);
    		hash->inserirNo(n);
    	}

    } catch (...) {
      std::cout << "Problema ao ler o arquivo." << '\n';
      printHelp();
      return 1;
    }
  }

  ////////////////////////////////////////////////////////////////////////////
  //Saida para arquivo

  if (argc > 4 && std::string(argv[3]) == "-o") {
    try {

      const char* nome = argv[4];

      std::ofstream out(nome);
			std::streambuf *coutbuf = std::cout.rdbuf();
			std::cout.rdbuf(out.rdbuf());

      No** tabela = hash->getHash();

      for (int i = 0; i < tamanhoHash; i++) {
        std::cout << i << ": ";

        No* print = tabela[i];

        while (print != nullptr) {
          std::cout << print->getChave() << ' ';
          print = print->getProx();
        }

        std::cout << '\n';

      }

			return 0;

    } catch (...) {
			std::cout << "Erro ao manusear a saida, verifique suas permissões parça" << '\n';
			return 1;
    }
  }

  if (argc > 6 && std::string(argv[5]) == "-o") {
    try {

    	const char* nome = argv[6];

      std::ofstream out(nome);
			std::streambuf *coutbuf = std::cout.rdbuf();
			std::cout.rdbuf(out.rdbuf());

      No** tabela = hash->getHash();

      for (int i = 0; i < tamanhoHash; i++) {
        std::cout << i << ": ";

        No* print = tabela[i];

        while (print != nullptr) {
          std::cout << print->getChave() << ' ';
          print = print->getProx();
        }

        std::cout << '\n';

      }

			return 0;

    } catch (...) {
			std::cout << "Erro ao manusear a saida, verifique suas permissões parça" << '\n';
			return 1;
    }
  }
//////////////////////////////////////////////////////////////////////////////


  No** tabela = hash->getHash();

  for (int i = 0; i < tamanhoHash; i++) {
    std::cout << i << ": ";

    No* print = tabela[i];

    while (print != nullptr) {
      std::cout << print->getChave() << ' ';
      print = print->getProx();
    }

    std::cout << '\n';

  }

  return 0;


}
