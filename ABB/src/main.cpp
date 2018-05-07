#include <iostream>

#include "no.hpp"
#include "arvore.hpp"


int main() {

	No n(11);
	No n2(1223);

	Arvore t;

	t.inserirNo(&n);
	t.inserirNo(&n2);
	
	std::cout << t.getMin()->getChave() << std::endl;
	return 0;

}
