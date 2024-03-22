#include <iostream>
#include "MySTL.hpp"

int main()
{

	std::cout << my_stl::min(1, 1) << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << my_stl::str_to_hash("A") << std::endl;
	std::cout << my_stl::str_to_hash("B") << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << my_stl::two_str_to_hash("A", "B") << std::endl;
	std::cout << my_stl::two_str_to_hash("B", "A") << std::endl;
	
	return 0;
}