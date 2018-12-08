#ifndef BRIDGES_FINDER_GRAPHEDGECONFIG_HPP
#define BRIDGES_FINDER_GRAPHEDGECONFIG_HPP

#include "Vertex.h"

namespace bridges_finder {

class GraphEdgeConfig
{
public:
    GraphEdgeConfig() {}

    GraphEdgeConfig(const std::string& firstVertex, const std::string& secondVertex) {
        this->firstVertex = firstVertex;
        this->secondVertex = secondVertex;
    }

    const std::string getFirstVertex() const {
        return firstVertex;
    }

    void setFirstVertex(const std::string& firstVertex) {
        this->firstVertex = firstVertex;
    }

    const std::string getSecondVertex() const {
        return secondVertex;
    }

    void setSecondVertex(const std::string& secondVertex) {
        this->secondVertex = secondVertex;
    }

    GraphEdgeConfig &operator=(const GraphEdgeConfig& graphEdgeConfig) {
        firstVertex = graphEdgeConfig.firstVertex;
        secondVertex = graphEdgeConfig.secondVertex;
        return *this;
    }

    static const std::string FIRST_VERTEX_TAG;
    static const std::string SECOND_VERTEX_TAG;

private:
    std::string firstVertex;
    std::string secondVertex;
};

const std::string GraphEdgeConfig::FIRST_VERTEX_TAG = "firstVertex";
const std::string GraphEdgeConfig::SECOND_VERTEX_TAG = "secondVertex";

} // bridges_finder

#endif //BRIDGES_FINDER_GRAPHEDGECONFIG_HPP
