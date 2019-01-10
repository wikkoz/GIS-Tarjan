#ifndef BRIDGES_FINDER_GRAPH_HPP
#define BRIDGES_FINDER_GRAPH_HPP

#include <memory>
#include <unordered_map>
#include "Node.hpp"

#include "GraphConfig.hpp"

namespace bridges_finder {

class Graph
{
public:
    using nodes_map = std::unordered_map<std::string, std::shared_ptr<Node>>;

    Graph(const GraphConfig& config) {
        const auto& edges = config.getEdges();
        const auto& identities = config.getVertices();

        for (const auto& id: identities) {
            nodes[id] = std::make_shared<Node>(id);
        }

        for (const auto& edge : edges) {
            const auto& firstId = edge.getFirstVertex();
            const auto& secondId = edge.getSecondVertex();

            auto& firstNode = nodes[firstId];
            auto& secondNode = nodes[secondId];

            firstNode->addNeighbour(secondNode->getIdentity());
            secondNode->addNeighbour(firstNode->getIdentity());
        }
    }

    std::size_t getSize() {
        return nodes.size();
    }

    nodes_map& getNodes() {
        return nodes;
    }

private:
    nodes_map nodes;
};

} // bridges_finder

#endif //BRIDGES_FINDER_GRAPH_HPP
