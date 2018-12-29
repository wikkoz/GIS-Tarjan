#ifndef BRIDGES_FINDER_BRIDGESFINDER_H
#define BRIDGES_FINDER_BRIDGESFINDER_H

#include <unordered_set>
#include <memory>
#include <functional>
#include <utility>
#include "TreeBuilder.hpp"

namespace bridges_finder {

class BridgesFinder
{
public:
    using tree_ptr = std::shared_ptr<Tree>;
    using solution = std::unordered_set<std::shared_ptr<std::pair<std::string, std::string>>>;
    using solution_ptr = std::shared_ptr<solution>;
    using return_type = std::pair<tree_ptr, solution_ptr>;

    static return_type find(const std::shared_ptr<Graph>& graph) {
        // Build spanning tree
        const auto root = graph->getNodes()->begin()->second;
        const auto tree = TreeBuilder::buildTree(*root);

        // Number nodes (set order and number of children)
        BridgesFinder::goPostorder(tree, [&tree](const std::string& id, const int order) {
            auto& node = (*(tree->getNodes()))[id];
            const auto& children = node->getNeighbours();

            std::vector<int> nocs;
            std::transform(children.begin(), children.end(), std::back_inserter(nocs),
                    [&tree](const auto& child) {
                const auto cid = child->getIdentity();
                return (*(tree->getNodes()))[cid]->getNumberOfChildren();
            });
            const int noc = std::accumulate(nocs.begin(), nocs.end(), 1);

            node->setOrder(order);
            node->setNumberOfChildren(noc);
        });

        return std::pair<tree_ptr, solution_ptr>(tree, NULL);
    }

private:
    static void goPostorder(const std::shared_ptr<Tree>& tree, std::function<void(const std::string&, int)> function) {
        std::stack<std::string> toVisit;
        std::unordered_set<std::string> visited;
        int order = 0;

        toVisit.push(tree->getRoot()->getIdentity());

        while (!toVisit.empty()) {
            auto id = toVisit.top();
            auto node = (*tree->getNodes())[id];

            bool childrenProcessed = true;

            // children not processed if at least one is not processed
            for (const auto &n: node->getNeighbours()) {
                if (visited.find(n->getIdentity()) == visited.end()) {
                    childrenProcessed = false;
                    break;
                }
            }

            if (childrenProcessed) {
                visited.insert(id);
                function(id, ++order);
                toVisit.pop();
            } else {
                for (const auto &n: node->getNeighbours()) {
                    toVisit.push(n->getIdentity());
                }
            }
        }
    }

    BridgesFinder() = delete;

    BridgesFinder(const BridgesFinder &) = delete;

    BridgesFinder(BridgesFinder &&) = delete;

    BridgesFinder &operator=(const BridgesFinder &) = delete;

    BridgesFinder &operator=(BridgesFinder &&) = delete;
};

} // bridges_finder

#endif //BRIDGES_FINDER_BRIDGESFINDER_H
