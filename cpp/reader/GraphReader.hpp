#ifndef BRIDGES_FINDER_GRAPHREADER_HPP
#define BRIDGES_FINDER_GRAPHREADER_HPP

#include <fstream>
#include "json.hpp"
#include "GraphConfig.hpp"

namespace bridges_finder {
    using json = nlohmann::json;

    void to_json(json& j, const GraphConfig& config);

    void from_json(const json& j, GraphConfig& config);

class GraphReader
{
private:
    using input_stream = std::ifstream;

public:
    static const bool readFile(const std::string& fileName, GraphConfig& config) {
        try {
            input_stream input {fileName};
            json j;
            input >> j;
            from_json(j, config);
            return true;
        } catch (...) {
            return false;
        }
    }

private:
    GraphReader() {}
};

    void to_json(json& j, const std::list<GraphEdgeConfig>& edges) {
        j.clear();

        for (const auto& edge: edges) {
            j.push_back(json{{GraphEdgeConfig::FIRST_VERTEX_TAG, edge.getFirstVertex()},
                             {GraphEdgeConfig::SECOND_VERTEX_TAG, edge.getSecondVertex()}});
        }
    }

    void to_json(json& j, const GraphConfig& config) {
        const auto& edges = config.getEdges();
        const auto& vertices = config.getVertices();

        j = json{{GraphConfig::EDGES_TAG, edges}, {GraphConfig::VERTICES_TAG, vertices}};
    }

    void from_json(const json& j, std::list<GraphEdgeConfig>& edges) {
        edges.clear();

        for (auto& elem: j) {
            using Edge = GraphEdgeConfig;
            using Vertex = std::string;

            const auto& firstVertex = elem.at(GraphEdgeConfig::FIRST_VERTEX_TAG).get<Vertex>();
            const auto& secondVertex = elem.at(GraphEdgeConfig::SECOND_VERTEX_TAG).get<Vertex>();
            Edge edge{firstVertex, secondVertex};

            edges.push_back(edge);
        }
    }

    void from_json(const json& j, GraphConfig& config) {
        using Edges = std::list<GraphEdgeConfig>;
        using Vertices = std::list<std::string>;

        const auto& vertices = j.at(GraphConfig::VERTICES_TAG).get<Vertices>();
        const auto& edges = j.at(GraphConfig::EDGES_TAG).get<Edges>();

        config.setVertices(vertices);
        config.setEdges(edges);
    }

} // bridges_finder

#endif //BRIDGES_FINDER_GRAPHREADER_HPP
