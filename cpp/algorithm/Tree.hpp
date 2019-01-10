#ifndef BRIDGES_FINDER_TREE_HPP
#define BRIDGES_FINDER_TREE_HPP

#include <stack>
#include "Graph.hpp"
#include "TreeNode.hpp"

namespace bridges_finder {

class Tree {
public:
    using nodes_map = std::unordered_map<std::string, std::shared_ptr<TreeNode>>;

    Tree(Graph& graph, const TreeNode &root)
            : root(root.getIdentity()) {
        std::stack<std::shared_ptr<Node>> to_visit;
        std::unordered_set<std::string> visited;

        to_visit.push(std::make_shared<Node>(root));

        while (!to_visit.empty()) {
            auto node = to_visit.top();
            to_visit.pop();

            const auto id = node->getIdentity();
            nodes.emplace(id, std::make_shared<TreeNode>(id));
            visited.insert(id);

            for (auto& nid : node->getNeighbours()) {
                if (visited.find(nid) != visited.end()) {
                    continue;
                }

                nodes.emplace(nid, std::make_shared<TreeNode>(nid));
                to_visit.push(graph.getNodes()[nid]);
                visited.insert(nid);
                nodes[id]->addNeighbour(nid);
                nodes[nid]->setParent(id);
            }
        }
    }

    const TreeNode& getRoot() {
        return *(nodes[root]);
    }

    nodes_map& getNodes() {
        return nodes;
    }

private:
    std::string root;
    nodes_map nodes;
};

} // bridges_finder

#endif //BRIDGES_FINDER_TREE_HPP
