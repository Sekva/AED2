# Algoritimos e Estruturas de Dados II

## Estruturas de dados

- [x] Arvore de busca binaria (sem remoção)
- [x] AVl (sem remoção)
- [x] Arvore Rubro-Negra (sem remoção)
- [ ] Arvore-B (sem remoção)
- [x] Heap
- [x] Hash

## Grafos

### Arvore Geradora Minima

- [x] Kruskal
- [x] Prim
### Menor caminho

- [x] Dijkstra
- [x] Floyd-Warshall
### Fluxo

- [ ] Fulkerson-Ford?

#### Detalhe sobre as entradas
As entradas se dão como no exemplo

Lista de adjacencia de um grafo G com 6 vértice e 8 arestas (3a coluna é o peso da aresta)

6 8 <br>
1 2 5 <br>
1 3 4 <br>
1 4 2 <br>
1 6 6 <br>
2 4 1 <br>
2 5 7 <br>
3 5 6 <br>
4 6 1 <br>

Se a 3a coluna for omitida vale 1. Neste caso todos os pesos das arestas valem 1

6 8 <br>
1 2 <br>
1 3 <br>
1 4 <br>
1 6 <br>
2 4 <br>
2 5 <br>
3 5 <br>
4 6 <br>

Note que as arestas estão ordenadas da seguinte forma:

(i, m) <br>
(j, n) <br>
(k, o) <br>

com i < j < k

(l, a) <br>
(l, b) <br>
(l, c) <br>

com a < b < c

<hr>

Estruturas desenvolvidas confirme orientação do Prof. Rian Gabriel Pinheiro, UAG-UFRPE.

[Instruções de implementação](http://bcc.uag.ufrpe.br/~rian/disc/ListaAEDII.pdf)
