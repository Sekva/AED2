#ifndef HEAP_HPP
#define HEAP_HPP

class Heap {
  private:
    int tamanho;
    int quantidade;
    int* heap;

  public:
    Heap(int* vetor, int quantidade, int tipo);

    int getPai(int n);
    int getEsq(int n);
    int getDir(int n);

    int* getHeap();

    void heapsortMax();
    void heapsortMin();


  private:
    void troca(int a, int b);
    void max_heapfy(int i);
    void build_max_heap(int* vetor, int quantidade);
    void min_heapfy(int i);
    void build_min_heap(int* vetor, int quantidade);
};

#endif
