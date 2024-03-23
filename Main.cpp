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
	char buff2[50];
	char buff3[50];

	char cmd[50];
	int n;
	gne::Graph* graph;
	gne::TypeEdge typeGraph{};
	
	std::cout << "1) digraph\n" << "2) graph\n> ";
	std::cin >> n;

	if (n % 2 != 0) typeGraph = gne::ORIENTED;
	else typeGraph = gne::UNORIENTED;

	graph = new gne::Graph(typeGraph);

	while (true)
	{
		graph_to_png(graph);

		std::cout << "0) [Opr]\n1) [Opr] [Node]\n2) [Opr] [Node] [Node]\n3) [Opr] [Node] [Node] [Text]\n4) Print graph\n> ";
		std::cin >> n;
		
		if (n == 4)
		{
			std::cout << *graph << std::endl;
			continue;
		}

		std::cout << "$ ";
		
		if (n == 0) {
			std::cin >> cmd;
		} else if (n == 1)
		{
			std::cin >> cmd >> buff;
		}else
		if (n == 2)
		{
			std::cin >> cmd >> buff >> buff2;
		}
		else if (n == 3)
		{
			std::cin >> cmd >> buff >> buff2 >> buff3;
		}
		else
		{
			continue;
		}

		if (n == 0)
		{
			if (cmd[0] == 'm')
			{
				unsigned int count;
				auto res = graph->getMaxNodeEdges(&count);
				std::cout << "{\n";

				for (int i = 0; i < count; i++)
					std::cout << "\t" << *res[i] << std::endl;

				std::cout << "}\n";

				delete[] res;
			}
		}
		else if (n == 1) 
		{
			if (cmd[0] == '+')
			{
				auto node = new gne::Node(buff);
				if (!graph->add(node)) 
				{
					std::cout << "such a node exists" << std::endl;
					delete node;
				}
			} else if (cmd[0] == '-')
			{
				auto node = new gne::Node(buff);
				graph->remove(node);
				delete node;
			} else if (cmd[0] == '?')
			{
				auto node = new gne::Node(buff);
				unsigned int count;
				auto res = graph->findEdgesByNode(node, &count);

				std::cout << "{\n";

				for (int i = 0; i < count; i++)
					std::cout << "\t" << *res[i] << std::endl;

				std::cout << "}\n";
				
				delete[] res;
				delete node;
			} 
		}
		else if (n == 2)
		{
			if (cmd[0] == '>')
			{
				auto node1 = new gne::Node(buff);

				auto node2 = new gne::Node(buff2);

				strcpy_s(buff, sizeof(buff), "");
				auto edge = new gne::Edge(node1, node2, typeGraph, buff);

				if (!graph->add(edge))
				{
					std::cout << "such a edge exists" << std::endl;
					delete edge;
				}

				delete node1;
				delete node2;
			}
			else if (cmd[0] == '-')
			{
				auto node1 = new gne::Node(buff);
				auto node2 = new gne::Node(buff2);

				strcpy_s(buff, sizeof(buff), "");
				auto edge = new gne::Edge(node1, node2, typeGraph, buff);

				graph->remove(edge);

				delete edge;
				delete node1;
				delete node2;
			}
		} 
		else if (n == 3)
		{
			if (cmd[0] == '>')
			{
				auto node1 = new gne::Node(buff);

				auto node2 = new gne::Node(buff2);

				auto edge = new gne::Edge(node1, node2, typeGraph, buff3);

				if (!graph->add(edge))
				{
					std::cout << "such a edge exists" << std::endl;
					delete edge;
				}

				delete node1;
				delete node2;
			}
		}
	}

	return 0;
}