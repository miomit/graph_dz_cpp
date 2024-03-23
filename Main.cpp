#include "Graph.hpp"
#include "MySTL.hpp"

#include <fstream>
#include <cstringt.h>
#include <iostream>

void graph_to_png(gne::Graph* graph)
{
	std::ofstream file("C:\\Users\\user_\\out.dot");
	if (!file.is_open()) {
		std::cerr << "Не удалось открыть файл для записи." << std::endl;
		return;
	}

	file << *graph;

	file.close();

	system("dot -Tpng -Gdpi=300й C:\\Users\\user_\\out.dot -o C:\\Users\\user_\\out.png");
}

int main()
{
	char buff[50];
	int num_tokens;
	int n;
	gne::Graph* graph;
	
	std::cout << "1) digraph\n" << "2) graph\n> ";
	std::cin >> n;

	if (n % 2 == 0)
		graph = new gne::Graph(gne::ORIENTED);
	else
		graph = new gne::Graph(gne::UNORIENTED);

	while (true)
	{
		graph_to_png(graph);

		std::cout << "> ";
		std::cin >> buff;

		char** tokens = my_stl::split(buff, '_', &num_tokens);
		
		if (num_tokens == 2) 
		{
			if (tokens[0][0] == '+')
			{
				strcpy_s(buff, sizeof(buff), tokens[1]);
				auto node = new gne::Node(buff);
				if (!graph->add(node)) 
				{
					std::cout << "such a node exists" << std::endl;
					delete node;
				}
			} else if (tokens[0][0] == '-')
			{
				strcpy_s(buff, sizeof(buff), tokens[1]);
				auto node = new gne::Node(buff);
				graph->remove(node);
				delete node;
			}
		}

		delete[] tokens;
	}

	return 0;
}