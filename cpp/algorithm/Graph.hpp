#ifndef BRIDGES_FINDER_GRAPH_HPP
#define BRIDGES_FINDER_GRAPH_HPP

#include <memory>
#include <unordered_map>
#include "Node.hpp"

namespace bridges_finder {

class Graph
{
public:
    using nodes_map = std::unordered_map<std::string, std::shared_ptr<Node>>;
    using nodes_map_ptr = std::shared_ptr<nodes_map>;

    Graph(nodes_map_ptr& nodes)
            : nodes(nodes) {}

    std::size_t getSize() {
        return nodes->size();
    }

    const nodes_map_ptr& getNodes() {
        return nodes;
    }

private:
    nodes_map_ptr nodes;
};

} // bridges_finder

#endif //BRIDGES_FINDER_GRAPH_HPP
