#include <iostream>

#include "no.hpp"
#include "arvore.hpp"


int main() {

	No n(666);
	No n2(999);
	No n3(333);
	No n4(1);
	No n5(4);
	No n6(77);
	No n7(80);
	No n8(10);

	Arvore t;

	t.inserirNo(&n);
	t.inserirNo(&n2);
	t.inserirNo(&n3);
	t.inserirNo(&n4);
	t.inserirNo(&n5);
	t.inserirNo(&n6);
	t.inserirNo(&n7);
	t.inserirNo(&n8);


	std::cout << t.getRaiz()->getFilhoEsq()->getFilhoDir()->getFilhoDir()->getChave() << std::endl;

	return 0;

}
