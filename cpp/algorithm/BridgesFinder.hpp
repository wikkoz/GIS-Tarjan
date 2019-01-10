#ifndef BRIDGES_FINDER_BRIDGESFINDER_H
#define BRIDGES_FINDER_BRIDGESFINDER_H

#include <unordered_set>
#include <memory>
#include <functional>
#include <utility>
#include "Tree.hpp"

namespace bridges_finder {

class BridgesFinder
{
public:
    using tree_ptr = std::shared_ptr<Tree>;
    using solution = std::unordered_set<std::shared_ptr<std::pair<std::string, std::string>>>;
    using solution_ptr = std::shared_ptr<solution>;
    using return_type = std::pair<tree_ptr, solution_ptr>;

    static solution_ptr find(Graph& graph) {
        // Build spanning tree
        const auto root = graph.getNodes().begin()->second;
        Tree tree{graph, *root};

        // Number nodes (set order and number of children)
        BridgesFinder::goPostorder(tree, [&tree](const std::string& id, const int order) {
            auto& node = tree.getNodes()[id];
            const auto& children = node->getNeighbours();

            std::vector<int> nocs;
            std::transform(children.begin(), children.end(), std::back_inserter(nocs),
                    [&tree](const auto& cid) {
                return tree.getNodes()[cid]->getNumberOfChildren();
            });
            const int noc = std::accumulate(nocs.begin(), nocs.end(), 1);

            node->setOrder(order);
            node->setNumberOfChildren(noc);
        });

        // Galculate H(v) and L(v)
        BridgesFinder::goPostorder(tree, [&graph, &tree](const std::string& id, int) {
            auto& node = tree.getNodes()[id];
            const auto& graphNode = graph.getNodes()[id];

            int order = node->getOrder();
            const auto& children = node->getNeighbours();

            std::list<std::string> treeNeighbours;

            for (const auto& neighbour: graphNode->getNeighbours()) {
                const auto parent = node->getParent();
                if (parent.empty()) {
                    continue;
                }
                if ((neighbour == parent)) {
                    continue;
                }
                treeNeighbours.push_back(neighbour);
            }

            std::vector<int> extremeNeighbours;

            std::transform(treeNeighbours.begin(), treeNeighbours.end(), std::back_inserter(extremeNeighbours),
                    [&tree](const auto& id) {
                const auto n = tree.getNodes()[id];
                return std::min(n->getLowestNeighbour(), n->getOrder());
            });

            int smallestNeighbour = std::accumulate(extremeNeighbours.begin(), extremeNeighbours.end(), order,
                    [](int first, int second) {
                return std::min(first, second);
            });

            extremeNeighbours.clear();

            std::transform(treeNeighbours.begin(), treeNeighbours.end(), std::back_inserter(extremeNeighbours),
                    [&tree](const auto& id) {
                const auto n = tree.getNodes()[id];
                return std::max(n->getHighestNeighbour(), n->getOrder());
            });

            int highestNeighbour = std::accumulate(extremeNeighbours.begin(), extremeNeighbours.end(), order,
                    [](int first, int second) {
                return std::max(first, second);
            });

            node->setLowestNeighbour(smallestNeighbour);
            node->setHighestNeighbour(highestNeighbour);
        });

        // Find bridge edges
        return findBridgeEdges(tree);
    }

private:
    static void goPostorder(Tree& tree, std::function<void(const std::string&, int)> function) {
        std::stack<std::string> to_visit;
        std::unordered_set<std::string> visited;
        int order = 0;

        to_visit.push(tree.getRoot().getIdentity());

        while (!to_visit.empty()) {
            auto id = to_visit.top();
            auto node = tree.getNodes()[id];

            bool childrenProcessed = true;

            // children not processed if at least one is not processed
            for (const auto neighbour: node->getNeighbours()) {
                if (visited.find(neighbour) == visited.end()) {
                    childrenProcessed = false;
                    break;
                }
            }

            if (childrenProcessed) {
                visited.insert(id);
                function(id, ++order);
                to_visit.pop();
            } else {
                for (const auto neighbour: node->getNeighbours()) {
                    to_visit.push(neighbour);
                }
            }
        }
    }

    static solution_ptr findBridgeEdges(Tree& tree) {
        solution_ptr ret = std::make_shared<solution>();

        for (const auto& [_, node]: tree.getNodes()) {
            const auto& neighbours = node->getNeighbours();

            for (auto& nid : node->getNeighbours()) {
                auto& n = tree.getNodes()[nid];

                if (n->getHighestNeighbour() <= n->getOrder() &&
                        n->getLowestNeighbour() > n->getOrder() - n->getNumberOfChildren()) {
                    ret->emplace(std::make_shared<std::pair<std::string, std::string>>(node->getIdentity(), n->getIdentity()));
                }
            }
        }

        return ret;
    }

    BridgesFinder() = delete;

    BridgesFinder(const BridgesFinder &) = delete;

    BridgesFinder(BridgesFinder &&) = delete;

    BridgesFinder &operator=(const BridgesFinder &) = delete;

    BridgesFinder &operator=(BridgesFinder &&) = delete;
};

} // bridges_finder

#endif //BRIDGES_FINDER_BRIDGESFINDER_H
