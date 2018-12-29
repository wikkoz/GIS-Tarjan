#include "Printer.h"
#include "GraphReader.hpp"
#include "GraphFactory.hpp"
#include "TreeBuilder.hpp"
#include "BridgesFinder.hpp"

using bridges_finder::Printer;
using bridges_finder::json;
using bridges_finder::GraphConfig;
using bridges_finder::GraphReader;
using bridges_finder::GraphFactory;
using bridges_finder::TreeBuilder;
using bridges_finder::BridgesFinder;

int main() {
    const std::string INPUT_NAMES[] = {
            "../../input/in1.json",
            "../../input/in2.json",
            "../../input/in3.json",
    };

    for (const auto& name: INPUT_NAMES) {
        GraphConfig config;

        bool res = GraphReader::readFile(name, config);

        if (!res) {
            Printer::printInvalidFile();
            return 1;
        }

        json j{config};

        const auto graph = GraphFactory::createGraph(config);
        Printer::printAdjacencyList(name, graph);

        const auto& [tree, solution] = BridgesFinder::find(graph);

        Printer::printSpanningTree(tree);
    }

    return 0;
}
