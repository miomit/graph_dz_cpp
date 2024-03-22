#include <iostream>
#include "Edge.hpp"

int main()
{
	char name[50] = "A";
	auto a = new gne::Node(name);
	name[0] = 'B';
	auto b = new gne::Node(name);
	auto c = new gne::Node(name);
	name[0] = 'D';
	auto d = new gne::Node(name);

	std::cout << *a << "; hash = " << a->getHashCode() << std::endl;
	std::cout << *b << "; hash = " << b->getHashCode() << std::endl;
	std::cout << *c << "; hash = " << c->getHashCode() << std::endl;
	std::cout << *d << "; hash = " << d->getHashCode() << std::endl;

	name[0] = 'E';

	auto k = gne::Edge(a, b, gne::ORIENTED, name);
	auto k2 = gne::Edge(b, a, gne::ORIENTED, name);


	std::cout << k << "; hash = " << k.getHashCode() << std::endl;
	std::cout << k2 << "; hash = " << k2.getHashCode() << std::endl;

	std::cout << k.isNodeExist(*c) << std::endl;
	std::cout << k.isNodeExist(*d) << std::endl;
	
	return 0;
}