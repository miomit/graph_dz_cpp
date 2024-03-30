#include "Node.hpp"
#include "MySTL.hpp"

#include <cstring>

gne::Node::Node(char name[50])
{
	strncpy(this->_name, name, sizeof(this->_name));
	strncpy(this->_label, name, sizeof(this->_label));

	this->_hashCode = my_stl::str_to_hash(name);
}

gne::Node::Node(char name[50], char label[50])
{
	strncpy(this->_name, name, sizeof(this->_name));
	strncpy(this->_label, label, sizeof(this->_label));

	this->_hashCode = my_stl::str_to_hash(name);
}

std::ostream& gne::operator<<(std::ostream& os, const Node& node)
{
	os << node._name << " [label=\"" << node._label << "\"]";
	return os;
}

bool gne::operator==(const Node& node1, const Node& node2)
{
	return node1._hashCode == node2._hashCode;
}
