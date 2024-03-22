#include <iostream>

namespace gne
{
	class Node
	{
	public:
		Node(char name[50]);
		Node(char name[50], char label[50]);

		char* getName() { return _name; }
		char* getLabel() { return _label; }

		int getHashCode() { return _hashCode; }

		friend std::ostream& operator<<(std::ostream& os, const Node& node);
		friend bool operator==(const Node& node1, const Node& node2);
	private:
		int _hashCode;
		char _name[50], _label[50];
	};
}