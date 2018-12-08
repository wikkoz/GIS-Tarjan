#ifndef BRIDGES_FINDER_NODE_HPP
#define BRIDGES_FINDER_NODE_HPP

#include <memory>
#include <list>
#include "Vertex.h"

namespace bridges_finder {

class Node : public Vertex
{
public:
    Node(const std::string& identity) : Vertex(identity) {}

    Node(const Vertex& vertex) : Vertex(vertex) {}

    Node(const Node& node) : Vertex(node), neighbours(node.getNeighbours()) {}

    virtual void addNeighbour(const Node& node) {
        neighbours.push_back(std::make_shared<Node>(node));
    }

    const std::list<std::shared_ptr<Node>>& getNeighbours() const {
        return neighbours;
    }

    Node& operator=(const Node& node) {
        identity = node.identity;
        neighbours = node.neighbours;
        return *this;
    }

    bool operator==(const Node& node) {
        return identity.compare(node.identity) == 0;
    }

protected:
    std::list<std::shared_ptr<Node>> neighbours;
};

} // bridges_finder

#endif //BRIDGES_FINDER_NODE_HPP
