#include <iostream>

#include "no.hpp"
#include "arvore.hpp"


int main() {

	No n(33);
	No n2(15);
	No n3(47);
	No n4(10);
	No n5(20);
	No n6(38);
	No n7(5);
	No n8(12);
	No n9(18);

	Arvore t;

	t.inserirNo(&n);
	t.inserirNo(&n2);
	t.inserirNo(&n3);
	t.inserirNo(&n4);
	t.inserirNo(&n5);
	t.inserirNo(&n6);
	t.inserirNo(&n7);
	t.inserirNo(&n8);
	t.inserirNo(&n9);

	t.percorrerArvore();

	return 0;

}
