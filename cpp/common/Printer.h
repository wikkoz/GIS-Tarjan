#ifndef BRIDGES_FINDER_PRINTER_H
#define BRIDGES_FINDER_PRINTER_H

#include <iostream>
#include <string>
#include "Graph.hpp"

namespace bridges_finder {

class Printer
{
public:
    static void printInvalidFile() {
        std::cout << "Invalid parsing graph from file!" << std::endl;
    }

    static void printRawGraph(const std::string& name, const std::string& raw) {
        std::cout << "************* Graph " << name << " *************" << std::endl;
        std::cout << raw << std::endl;
    }

    static void printAdjacencyList(const std::string name, const std::shared_ptr<Graph>& graph) {
        using std::cout;
        using std::endl;

        cout << "--------------------------" << endl;
        cout << name << endl;
        cout << " size: " << graph->getSize() << endl;
        cout << "--------------------------" << endl;
        cout << " node: neighbours" << endl;
        cout << "--------------------------" << endl;

        const auto& nodes = *(graph->getNodes());

        for (const auto& [id, node]: nodes) {
            cout << "    " << id << ": ";
            for (const auto& neighbour : node->getNeighbours()) {
                cout << neighbour->getIdentity() << " ";
            } cout << endl;
        } cout << endl;
    }

    Printer() = delete;

    Printer(const Printer &) = delete;

    Printer(Printer &&) = delete;

    Printer &operator=(const Printer &) = delete;

    Printer &operator=(Printer &&) = delete;
};

} // bridges_finder

#endif //BRIDGES_FINDER_PRINTER_H
