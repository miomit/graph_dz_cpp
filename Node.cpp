#include "Node.hpp"
#include "MySTL.hpp"

#include <cstringt.h>

gne::Node::Node(char name[50], char label[50])
{
	strcpy_s(this->_name, sizeof(this->_name), name);
	strcpy_s(this->_label, sizeof(this->_label), label);

	this->_hashCode = my_stl::str_to_hash(name);
}