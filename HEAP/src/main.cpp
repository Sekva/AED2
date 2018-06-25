#include "heap.hpp"
#include <iostream>

int main() {

  int eita[11] = {11, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

  Heap* h = new Heap(eita, 11);

  int * hea = h->getHeap();

  for (int i = 1; i < 11; i++) {
    std::cout << hea[i] << '\n';
  }



  return 0;
}
