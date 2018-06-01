#include <iostream>
#include <fstream>

#include "no.hpp"

void arvoreCompleta(Arvore* t) {
  t->percorrerArvore();
}

void imprimirMenor(Arvore* t) {
  std::cout << t->getMin()->getChave() << std::endl;
}

void imprimirMaior(Arvore* t) {
  std::cout << t->getMax()->getChave() << std::endl;
}

void imprimirAntecessor(Arvore* t, int chave) {

  No* n = t->pegarNo(chave);

  if(n ==  nullptr) {
    std::cout << "-1" << std::endl;
  } else  {
    No* a = t->getAntecessor(n);
    if(a != nullptr) {
      std::cout << a->getChave() << std::endl;
    } else {
      std::cout << "-1" << std::endl;
    }
  }

}

void imprimirSucessor(Arvore* t, int chave) {

  No* n = t->pegarNo(chave);

  if(n ==  nullptr) {
    std::cout << "-1" << std::endl;
  } else  {
    No* a = t->getSucessor(n);
    if(a != nullptr) {
      std::cout << a->getChave() << std::endl;
    } else {
      std::cout << "-1" << std::endl;
    }
  }

}

void redirecionarSaidaArvoreCompleta(Arvore* t, const char* arquivo) {/* por algum motivo, quando trazido do main pra cá, problema de segmentação */}

void printHelp() {

  std::cout << "\n\nUso: ./executavel -f <entrada> [opções]\n" << '\n';
  std::cout << "\tOpções:\n" << '\n';
  std::cout << "\t-h : mostra o help" << '\n';
  std::cout << "\t-o <arquivo> : redireciona a saida para o ‘‘arquivo’’" << '\n';
  std::cout << "\t-f <arquivo> : indica o ‘‘arquivo’’ que contém os dados a serem adicionados na Arvore" << '\n';
  std::cout << "\t-m : imprime o menor elemento da Arvore" << '\n';
  std::cout << "\t-M : imprime o maior elemento da Arvore" << '\n';
  std::cout << "\t-a <elemento> : imprime o antecessor na Arvore do ‘‘elemento’’ ou caso contrário imprime -1" << '\n';
  std::cout << "\t-s <elemento> : imprime o sucessor na Arvore do ‘‘elemento’’ ou caso contrário imprime -1\n\n" << '\n';
}
