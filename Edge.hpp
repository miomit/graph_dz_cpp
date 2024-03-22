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

		void setTypeEdge(TypeEdge typeEdge);

		int getHashCode() { return _hashCode; }

		TypeEdge getTypeEdge() { return _typeEdge; }

		Node* getNode1() { return _node1; }
		Node* getNode2() { return _node2; }

		char* getLabel() { return _label; }
	private:
		int _hashCode;
		TypeEdge _typeEdge;
		Node *_node1, *_node2;

		char _label[50];
	};
}