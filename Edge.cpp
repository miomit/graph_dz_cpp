#include "Edge.hpp"

bool gne::Edge::isNodeExist(Node node)
{
    if (node.getHashCode() == this->_node1->getHashCode()) return true;
    if (node.getHashCode() == this->_node2->getHashCode()) return true;

    return false;
}
