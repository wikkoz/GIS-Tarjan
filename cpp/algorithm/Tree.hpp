#ifndef BRIDGES_FINDER_TREE_HPP
#define BRIDGES_FINDER_TREE_HPP

#include "TreeNode.hpp"

namespace bridges_finder {

class Tree {
public:
    using nodes_map = std::unordered_map<std::string, std::shared_ptr<TreeNode>>;
    using nodes_map_ptr = std::shared_ptr<nodes_map>;

    Tree(nodes_map_ptr &nodes, const TreeNode &root)
            : nodes(nodes), root(std::make_shared<TreeNode>(root)) {}

    const std::shared_ptr<TreeNode> &getRoot() {
        return root;
    }

    const nodes_map_ptr &getNodes() const {
        return nodes;
    }

private:
    std::shared_ptr<TreeNode> root;
    nodes_map_ptr nodes;
};

} // bridges_finder

#endif //BRIDGES_FINDER_TREE_HPP
