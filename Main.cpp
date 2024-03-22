#include <iostream>
#include "Node.hpp"

int main()
{
	char name[50] = "A";
	auto a = gne::Node(name);
	name[0] = 'B';
	auto b = gne::Node(name);
	auto c = gne::Node(name);

	std::cout << a << "; hash = " << a.getHashCode() << std::endl;
	std::cout << b << "; hash = " << b.getHashCode() << std::endl;
	std::cout << c << "; hash = " << c.getHashCode() << std::endl;
	
	return 0;
}