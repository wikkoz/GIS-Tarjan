#ifndef BRIDGES_FINDER_PRINTER_H
#define BRIDGES_FINDER_PRINTER_H

#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>
#include "Graph.hpp"
#include "Tree.hpp"

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

    static void printAdjacencyList(const std::string name, Graph& graph) {
        using std::cout;
        using std::endl;

        cout << name << endl;
        cout << "--------------------------" << endl;
        cout << " node: neighbours" << endl;
        cout << "--------------------------" << endl;

        const auto& nodes = graph.getNodes();

        for (const auto& [id, node]: nodes) {
            cout << "    " << id << ": ";
            for (const auto& neighbour : node->getNeighbours()) {
                cout << neighbour << " ";
            } cout << endl;
        }
    }

    static void printSpanningTree(Tree& tree) {
        using std::cout;
        using std::endl;

        cout << "--------------------------" << endl;
        cout << " (parent) node: children" << endl;
        cout << "--------------------------" << endl;

        std::stack<std::string> to_visit;
        std::unordered_set<std::string> visited;

        auto& nodes = tree.getNodes();
        const auto& root = tree.getRoot();
        const auto rootId = root.getIdentity();

        to_visit.push(rootId);

        while(!to_visit.empty()) {
            const auto id = to_visit.top();
            to_visit.pop();

            const auto& node = nodes[id];
            const auto parent = node->getParent();

            if (!parent.empty()) {
                cout << "(" << parent << ") ";
            } else {
                cout << "    ";
            }
            cout << id << ": ";

            for (const auto& neighbour : node->getNeighbours()) {
                cout << neighbour << " ";

                if (visited.find(neighbour) != visited.end()) {
                    continue;
                }

                to_visit.push(neighbour);
                visited.insert(neighbour);
            } cout << endl;
        }
    }

    static void printBridges(std::shared_ptr<std::unordered_set<std::shared_ptr<std::pair<std::string, std::string>>>> bridges) {
        using std::cout;
        using std::endl;

        cout << "--------------------------" << endl;
        cout << " bridges" << endl;
        cout << "--------------------------" << endl;

        if (!bridges->size()) {
            cout << " Not found" << endl << endl;
            return;
        }

        for (const auto& bridge: *bridges) {
            cout << " " << bridge->first << "-" << bridge->second << endl;
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
