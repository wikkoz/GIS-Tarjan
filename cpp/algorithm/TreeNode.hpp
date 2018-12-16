#ifndef BRIDGES_FINDER_TREENODE_HPP
#define BRIDGES_FINDER_TREENODE_HPP

#include <limits>
#include "Node.hpp"

namespace bridges_finder {

class TreeNode : public Node
{
public:
    TreeNode(const std::string& identity)
            : Node(identity), order(0), numberOfChildren(0),
                highestNeighbour(std::numeric_limits<int>::min()),
                lowestNeighbour(std::numeric_limits<int>::max()) {}

    TreeNode(const Node& node)
            : Node(node), order(0), numberOfChildren(0),
                highestNeighbour(std::numeric_limits<int>::min()),
                lowestNeighbour(std::numeric_limits<int>::max()) {}

    TreeNode(const TreeNode& node)
            : Node(node), numberOfChildren(node.numberOfChildren),
                highestNeighbour(node.highestNeighbour),
                lowestNeighbour(node.lowestNeighbour) {}

    const std::shared_ptr<TreeNode>& getParent() const {
        return parent;
    }

    void setParent(const std::shared_ptr<TreeNode>& parent) {
        this->parent = parent;
    }

    int getOrder() const {
        return order;
    }

    void setOrder(int order) {
        this->order = order;
    }

    int getNumberOfChildren() const {
        return numberOfChildren;
    }

    void setNumberOfChildren(int numberOfChildren) {
        this->numberOfChildren = numberOfChildren;
    }

    int getHighestNeighbour() const {
        return highestNeighbour;
    }

    void setHighestNeighbour(int highestNeighbour) {
        this->highestNeighbour = highestNeighbour;
    }

    int getLowestNeighbour() const {
        return lowestNeighbour;
    }

    void setLowestNeighbour(int lowestNeighbour) {
        this->lowestNeighbour = lowestNeighbour;
    }

private:
    std::shared_ptr<TreeNode> parent;
    int order;
    int numberOfChildren;
    int highestNeighbour;
    int lowestNeighbour;
};

} // bridges_finder

#endif //BRIDGES_FINDER_TREENODE_HPP
