#include "Graph.hpp"

#include <fstream>
#include <cstringt.h>

int main()
{
	setlocale(LC_ALL, 0);
	std::ofstream file("C:\\Users\\user_\\out.dot");

	if (!file.is_open()) {
		std::cerr << "Не удалось открыть файл для записи." << std::endl;
		return 1;
	}

	char buff[50];

	auto graph = gne::Graph(gne::ORIENTED);

	strcpy_s(buff, sizeof(buff), "A");
	auto a = new gne::Node(buff);

	strcpy_s(buff, sizeof(buff), "B");
	auto b = new gne::Node(buff);

	strcpy_s(buff, sizeof(buff), "C");
	auto c = new gne::Node(buff);

	strcpy_s(buff, sizeof(buff), "to");
	auto k1 = new gne::Edge(a, b, gne::ORIENTED, buff);

	strcpy_s(buff, sizeof(buff), "");
	auto k2 = new gne::Edge(b, c, gne::ORIENTED, buff);

	graph.add(a);
	graph.add(b);
	graph.add(c);

	graph.add(k1);
	graph.add(k2);

	std::cout << graph << std::endl;

	file << graph;

	file.close();

	system("dot -Tpng -Gdpi=300й C:\\Users\\user_\\out.dot -o C:\\Users\\user_\\out.png");
	return 0;
}