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

    static void printAdjacencyList(const std::string name, const std::shared_ptr<Graph>& graph) {
        using std::cout;
        using std::endl;

        cout << name << endl;
        cout << "--------------------------" << endl;
        cout << " node: neighbours" << endl;
        cout << "--------------------------" << endl;

        const auto& nodes = *(graph->getNodes());

        for (const auto& [id, node]: nodes) {
            cout << "    " << id << ": ";
            for (const auto& neighbour : node->getNeighbours()) {
                cout << neighbour->getIdentity() << " ";
            } cout << endl;
        }
    }

    static void printSpanningTree(const std::shared_ptr<Tree>& tree) {
        using std::cout;
        using std::endl;

        cout << "--------------------------" << endl;
        cout << " (parent) node: children" << endl;
        cout << "--------------------------" << endl;

        std::stack<std::string> toVisit;
        std::unordered_set<std::string> visited;

        const auto& root = tree->getRoot();
        const auto rootId = root->getIdentity();

        toVisit.push(rootId);

        while(!toVisit.empty()) {
            const auto id = toVisit.top();
            const auto node = (*(tree->getNodes()))[id];
            toVisit.pop();

            const auto parent = node->getParent();
            if (parent) {
                cout << "(" << parent->getIdentity() << ") ";
            } else {
                cout << "    ";
            }
            cout << id << ": ";

            for (const auto& n : node->getNeighbours()) {
                const auto& nid = n->getIdentity();

                cout << nid << " ";

                if (visited.find(nid) != visited.end()) {
                    continue;
                }

                toVisit.push(nid);
                visited.insert(nid);
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
