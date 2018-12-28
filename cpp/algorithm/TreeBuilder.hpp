#ifndef BRIDGES_FINDER_TREEBUILDER_HPP
#define BRIDGES_FINDER_TREEBUILDER_HPP

#include <stack>
#include <unordered_set>
#include "Tree.hpp"

namespace bridges_finder {

class TreeBuilder
{
public:
    static std::shared_ptr<Tree> buildTree(const Node& root) {
        std::stack<std::shared_ptr<Node>> toVisit;
        std::unordered_set<std::string> visited;
        auto treeNodes{std::make_shared<std::unordered_map<std::string, std::shared_ptr<TreeNode>>>()};

        const auto& rootId = root.getIdentity();

        toVisit.push(std::make_shared<Node>(root));

        while (!toVisit.empty()) {
            auto node = toVisit.top();
            toVisit.pop();

            const auto& id = node->getIdentity();
            treeNodes->emplace(id, std::make_shared<TreeNode>(id));
            visited.insert(id);

            for (auto& n : node->getNeighbours()) {
                const auto& nid = n->getIdentity();

                if (visited.find(nid) != visited.end()) {
                    continue;
                }

                treeNodes->emplace(nid, std::make_shared<TreeNode>(nid));
                toVisit.push(n);
                visited.insert(nid);
                (*treeNodes)[id]->addNeighbour(*((*treeNodes)[nid]));
                (*treeNodes)[nid]->setParent((*treeNodes)[id]);
            }
        }

        return std::make_shared<Tree>(treeNodes, *((*treeNodes)[rootId]));
    }

    TreeBuilder() = delete;

    TreeBuilder(const TreeBuilder &) = delete;

    TreeBuilder(TreeBuilder &&) = delete;

    TreeBuilder &operator=(const TreeBuilder &) = delete;

    TreeBuilder &operator=(TreeBuilder &&) = delete;
};

} // bridges_finder

#endif //BRIDGES_FINDER_TREEBUILDER_HPP
