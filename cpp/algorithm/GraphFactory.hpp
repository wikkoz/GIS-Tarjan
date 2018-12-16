#ifndef BRIDGES_FINDER_GRAPHFACTORY_HPP
#define BRIDGES_FINDER_GRAPHFACTORY_HPP

#include <memory>
#include "Graph.hpp"
#include "GraphConfig.hpp"

namespace bridges_finder {

class GraphFactory
{
public:
    static std::shared_ptr<Graph> createGraph(const GraphConfig& config) {
        const auto& edges = config.getEdges();
        const auto& identities = config.getVertices();
        auto nodes{std::make_shared<Graph::nodes_map>()};

        for (const auto& id: identities) {
            (*nodes)[id] = std::make_shared<Node>(id);
        }

        for (const auto& edge : edges) {
            const auto& firstId = edge.getFirstVertex();
            const auto& secondId = edge.getSecondVertex();

            auto& firstNode = (*nodes)[firstId];
            auto& secondNode = (*nodes)[secondId];

            firstNode->addNeighbour(*secondNode);
            secondNode->addNeighbour(*firstNode);
        }

        return std::make_shared<Graph>(nodes);
    }

    GraphFactory() = delete;

    GraphFactory(const GraphFactory&) = delete;

    GraphFactory(GraphFactory&&) = delete;

    GraphFactory& operator=(const GraphFactory&) = delete;

    GraphFactory& operator=(GraphFactory&&) = delete;
};

} // bridges_finder

#endif //BRIDGES_FINDER_GRAPHFACTORY_HPP
