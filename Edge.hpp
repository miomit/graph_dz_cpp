#include "Node.hpp";

namespace gne
{
	enum TypeEdge
	{
		ORIENTED,
		UNORIENTED
	};

	class Edge
	{
	public:
		Edge(Node* node1, Node* node2, TypeEdge typeEdge, char label[50]);

		bool isNodeExist(Node node);

		int getHashCode() { return _hashCode; }

		TypeEdge getTypeEdge() { return _typeEdge; }

		Node* getNode1() { return _node1; }
		Node* getNode2() { return _node2; }

		char* getLabel() { return _label; }

		friend std::ostream& operator<<(std::ostream& os, const Edge& edge);
		friend bool operator==(const Edge& edge1, const Edge& edge2);
	private:
		int _hashCode;
		TypeEdge _typeEdge;
		Node *_node1, *_node2;

		char _label[50];
	};
}