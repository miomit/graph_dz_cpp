#include <iostream>
#include "Graph.hpp"

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

	auto k = new gne::Edge(a, b, gne::UNORIENTED, name);
	auto k2 = new gne::Edge(b, a, gne::ORIENTED, name);


	std::cout << *k << "; hash = " << k->getHashCode() << std::endl;
	std::cout << *k2 << "; hash = " << k2->getHashCode() << std::endl;

	std::cout << (*k2 == *k) << std::endl;

	auto graph = gne::Graph(name);

	graph.add(k);
	graph.add(k);
	graph.add(k);
	graph.add(k);

	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < graph.getEdgesSize(); i++)
		std::cout << *graph.getEdges()[i] << "; hash = " << graph.getEdges()[i]->getHashCode() << std::endl;

	return 0;
}