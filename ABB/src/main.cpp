#include <iostream>

#include "no.hpp"
#include "arvore.hpp"


int main() {

	No n(11);
	No n2(1223);
	No n3(10);
	No n4(34);
	No n5(8);

	Arvore t;

	t.inserirNo(&n);
	t.inserirNo(&n2);
	t.inserirNo(&n3);
	t.inserirNo(&n4);
	t.inserirNo(&n5);
	
	std::cout << n.checarAltura() << std::endl;
	return 0;

}
