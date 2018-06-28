#include "heap.hpp"
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>

void printHelp() {
  std::cout << "\n\nUso: ./executavel -f <entrada> [opções]\n" << '\n';
  std::cout << "\tOpções:\n" << '\n';
  std::cout << "\t-h : mostra o help" << '\n';
  std::cout << "\t-o <arquivo> : redireciona a saida para o ‘‘arquivo’’" << '\n';
  std::cout << "\t-f <arquivo> : indica o ‘‘arquivo’’ que contém os dados a serem adicionados na Heap" << '\n';
  std::cout << "\t-m : indica que a estrutura será uma heap mínima" << '\n';
}


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

  if(std::string(argv[1]) != "-f" && std::string(argv[1]) != "-m") {
    std::cout << "ERRO: parâmetros conflitantes" << '\n';
    printHelp();
    return 1;
  }

  ///////////////////////////////////////////////////////////////////////////////////////////////////

  int nLinhas = 1;
  int tipo = 0; // 0  heap de max 1 heap de min
  Heap* h;
  std::vector<int> array;

  if(std::string(argv[1]) == "-m" && std::string(argv[2]) == "-f") {
    const char* arquivoEntrada = argv[3];
  	// std::cout << "Cosntruindo heap a partir de: " << arquivoEntrada << '\n';
  	std::ifstream entrada(arquivoEntrada);

  	if(!entrada) {
      std::cout << "Arquivo nao lido" << "\n";
      return 1;
    }

  	std::string linha;

  	while (std::getline(entrada, linha)) {
    	nLinhas++;
  	}

    int indice = 0;

    std::string linha2;
  	std::ifstream entrada2(arquivoEntrada);

    while (std::getline(entrada2, linha)) {
      int chave = atoi(linha.c_str());
      array.push_back(chave);
      indice++;
    }
    tipo++;
	}

  if (argc > 3) {
    if(std::string(argv[1]) == "-f" && std::string(argv[3]) == "-m") {
      const char* arquivoEntrada = argv[2];
      // std::cout << "Cosntruindo heap a partir de: " << arquivoEntrada << '\n';
      std::ifstream entrada(arquivoEntrada);

      if(!entrada) {
        std::cout << "Arquivo nao lido" << "\n";
        return 1;
      }

      std::string linha;

      while (std::getline(entrada, linha)) {
        nLinhas++;
      }

      int indice = 0;

      std::string linha2;
      std::ifstream entrada2(arquivoEntrada);

      while (std::getline(entrada2, linha)) {
        int chave = atoi(linha.c_str());
        array.push_back(chave);
        indice++;
      }
      tipo++;
    }
  }


  if((argc == 5 || argc == 4) && std::string(argv[1]) == "-f") {
    const char* arquivoEntrada = argv[2];
    // std::cout << "Cosntruindo heap a partir de: " << arquivoEntrada << '\n';
    std::ifstream entrada(arquivoEntrada);

    if(!entrada) {
      std::cout << "Arquivo nao lido" << "\n";
      return 1;
    }

    std::string linha;

    while (std::getline(entrada, linha)) {
      nLinhas++;
    }

    int indice = 0;

    std::string linha2;
    std::ifstream entrada2(arquivoEntrada);

    while (std::getline(entrada2, linha)) {
      int chave = atoi(linha.c_str());
      array.push_back(chave);
      indice++;
    }
  }


  if(argc == 3 && std::string(argv[1]) == "-f") {
    const char* arquivoEntrada = argv[2];
    // std::cout << "Cosntruindo heap a partir de: " << arquivoEntrada << '\n';
    std::ifstream entrada(arquivoEntrada);

    if(!entrada) {
      std::cout << "Arquivo nao lido" << "\n";
      return 1;
    }

    std::string linha;

    while (std::getline(entrada, linha)) {
      nLinhas++;
    }

    int indice = 0;

    std::string linha2;
    std::ifstream entrada2(arquivoEntrada);

    while (std::getline(entrada2, linha)) {
      int chave = atoi(linha.c_str());
      array.push_back(chave);
      indice++;
    }
  }



  int arr2[nLinhas+1];
  arr2[0] = nLinhas;
  for (int i = 1; i < nLinhas; i++) {
    arr2[i] = array[i-1];
  }

  h = new Heap(arr2, nLinhas, tipo);

  //////////////////////////////////////////////////////////////////////////////////////////////////////

  if(argc == 5 && std::string(argv[3]) == "-o") {

		const char* nome = argv[4];
		try {
      std::ofstream out(nome);
			std::streambuf *coutbuf = std::cout.rdbuf();
			std::cout.rdbuf(out.rdbuf());

      if (tipo == 0) {
        h->heapsortMax();
      } else {
        h->heapsortMin();
      }

      int* saida = h->getHeap();

      for (int i = nLinhas-1; i > 1; i--) {
        std::cout << saida[i] << ' ';
      }
			return 0;
		} catch(...) {
			std::cout << "Erro ao manusear a saida, verifique suas permissões parça" << '\n';
			return 1;
		}
		return 0;
	} else if(argc == 6 && std::string(argv[4]) == "-o") {

		const char* nome = argv[5];
		try {
			std::ofstream out(nome);
			std::streambuf *coutbuf = std::cout.rdbuf();
			std::cout.rdbuf(out.rdbuf());

      if (tipo == 0) {
        h->heapsortMax();
      } else {
        h->heapsortMin();
      }

      int* saida = h->getHeap();

      for (int i = nLinhas-1; i > 1; i--) {
        std::cout << saida[i] << ' ';
      }
			return 0;
		} catch(...) {
			std::cout << "Erro ao manusear a saida, verifique suas permissões parça" << '\n';
			return 1;
		}
		return 0;
	}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

  // std::cout << tipo << '\n';
  if (tipo == 0) {
    h->heapsortMax();
  } else {
    h->heapsortMin();
  }

  int* saida = h->getHeap();

  for (int i = nLinhas-1; i > 1; i--) {
    std::cout << saida[i] << ' ';
  }

  return 0;
}
