#include "Printer.h"
#include "GraphReader.hpp"

using bridges_finder::Printer;
using bridges_finder::json;
using bridges_finder::GraphConfig;
using bridges_finder::GraphReader;

int main() {
    const std::string INPUT_NAMES[] = {
            "../../input/in1.json",
            "../../input/in2.json",
            "../../input/in3.json",
    };

    for (const auto& name: INPUT_NAMES) {
        GraphConfig config;
        bool res;

        res = GraphReader::readFile(name, config);

        if (!res) {
            Printer::printInvalidFile();
            return 1;
        }

        json j{config};

        const auto graph = j.dump(4);
        Printer::printRawGraph(name, graph);
    }

    return 0;
}
