#include "heap.hpp"

#include <iostream>

Heap::Heap(int* vetor, int quantidade) {
  this->tamanho = quantidade;
  this->build_max_heap(vetor, quantidade);
}

void Heap::build_max_heap(int* vetor, int quantidade) {

  this->quantidade = quantidade;

  this->heap = vetor;
  // for (int i = 0; i < 5; i++) {
  //   std::cout << this->heap[i] << '\n';
  // }


  for (int i = (this->quantidade / 2); i > 0; i--) {
    this->max_heapfy(i);
  }

}

int Heap::getPai(int n) {
  return n / 2;
}
int Heap::getEsq(int n) {
  return (2 * n);
}
int Heap::getDir(int n) {
  return (2 * n) + 1;
}

void Heap::troca(int a, int b) {
  int temp = this->heap[a];
  this->heap[a] = this->heap[b];
  this->heap[b] = temp;
}

void Heap::max_heapfy(int i) {
  int e = this->getEsq(i);
  int d = this->getDir(i);
  int maior = i;


  if (e < this->quantidade && this->heap[e] > this->heap[i]) {
    maior = e;
  }

  if (d <= this->quantidade && this->heap[d] > this->heap[maior]) {
    maior = d;
  }

  if (maior != i) {
    std::swap(this->heap[i], this->heap[maior]);
    this->max_heapfy(maior);
  }

}


int* Heap::getHeap() {
  return this->heap;
}
