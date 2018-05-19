#include <iostream>

#include "no.hpp"
#include "arvore.hpp"


int main() {

	No n(4);
	No n2(27);
	No n3(666);
	No n4(7);
	No n5(11);
	No n6(3);
	No n7(23);
	No n8(42);

	Arvore t;

	t.inserirNo(&n);
	t.inserirNo(&n2);
	t.inserirNo(&n3);
	t.inserirNo(&n4);
	t.inserirNo(&n5);
	t.inserirNo(&n6);
	t.inserirNo(&n7);
	t.inserirNo(&n8);

	std::cout << t.getRaiz()->getFilhoDir()->getFilhoEsq()->getChave() << std::endl;

	return 0;

}
