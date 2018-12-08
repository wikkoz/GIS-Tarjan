#ifndef BRIDGES_FINDER_GRAPHCONFIG_HPP
#define BRIDGES_FINDER_GRAPHCONFIG_HPP

#include <list>
#include "GraphEdgeConfig.hpp"
#include "Vertex.h"

namespace bridges_finder {

class GraphConfig
{
public:
    const std::list<std::string>& getVertices() const {
        return vertices;
    }

    void setVertices(const std::list<std::string>& vertices) {
        this->vertices = vertices;
    }

    const std::list<GraphEdgeConfig>& getEdges() const {
        return edges;
    }

    void setEdges(const std::list<GraphEdgeConfig>& edges) {
        this->edges = edges;
    }

    static const std::string VERTICES_TAG;
    static const std::string EDGES_TAG;

private:
    std::list<std::string> vertices;
    std::list<GraphEdgeConfig> edges;
};

const std::string GraphConfig::VERTICES_TAG = "vertices";
const std::string GraphConfig::EDGES_TAG = "edges";

} // bridges_finder

#endif //BRIDGES_FINDER_GRAPHCONFIG_HPP
