#include "heap.hpp"

#include <iostream>

Heap::Heap(int* vetor, int quantidade, int tipo) {
  this->tamanho = quantidade;
  if (tipo == 0) {
    this->build_max_heap(vetor, quantidade);
  } else {
    this->build_min_heap(vetor, quantidade);
  }
}

void Heap::build_max_heap(int* vetor, int quantidade) {

  this->quantidade = quantidade;

  this->heap = vetor;
  this->heap[0] = this->quantidade;

  for (int i = (this->quantidade / 2); i > 0; i--) {
    this->max_heapfy(i);
  }

}

void Heap::build_min_heap(int* vetor, int quantidade) {

  this->quantidade = quantidade;

  this->heap = vetor;
  this->heap[0] = this->quantidade;

  for (int i = (this->quantidade / 2); i > 0; i--) {
    this->min_heapfy(i);
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

void Heap::min_heapfy(int i) {
  int e = this->getEsq(i);
  int d = this->getDir(i);
  int menor = i;


  if (e < this->quantidade && this->heap[e] < this->heap[i]) {
    menor = e;
  }

  if (d < this->quantidade && this->heap[d] < this->heap[menor]) {
    menor = d;
  }

  if (menor != i) {
    std::swap(this->heap[i], this->heap[menor]);
    this->min_heapfy(menor);
  }

}

int* Heap::getHeap() {
  return this->heap;
}

void Heap::heapsortMax() {

  for (int i = this->quantidade; i > 1; i--) {
    std::swap(this->heap[1], this->heap[i]);
    this->quantidade -= 1;
    this->max_heapfy(1);
  }

  this->quantidade = this->heap[0];

  for (int i = 1; i < this->quantidade; i++) {
    this->heap[i] = this->heap[i+1];
  }

}

void Heap::heapsortMin() {

  for (int i = this->quantidade; i > 1; i--) {
    std::swap(this->heap[1], this->heap[i]);
    this->quantidade -= 1;
    this->min_heapfy(1);
  }

  this->quantidade = this->heap[0];

  for (int i = 1; i < this->quantidade; i++) {
    this->heap[i] = this->heap[i+1];
  }

}
