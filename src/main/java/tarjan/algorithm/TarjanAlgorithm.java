package tarjan.algorithm;

import com.google.common.collect.Lists;
import tarjan.algorithm.node.Node;
import tarjan.algorithm.node.TarjanNode;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.function.BiConsumer;
import java.util.stream.Collectors;

public class TarjanAlgorithm {
    private final TreeBuilder treeBuilder = new TreeBuilder();

    public void tarjanAlgorithm(Graph<Node> graph) {
        Graph<TarjanNode> tree = treeBuilder.buildTree(graph.getRoot());
        numberNodes(tree, orderingTree());
        numberNodes(tree, calculationLowestAndHighestNeigbour(graph, tree));
    }

    private void numberNodes(Graph<TarjanNode> tree, BiConsumer<TarjanNode, Integer> function) {
        List<TarjanNode> queue = Lists.newArrayList(tree.getRoot());
        Map<TarjanNode, Boolean> visitied = new HashMap<>(tree.getSize());
        int order = 0;
        while (!queue.isEmpty()) {
            TarjanNode node = queue.get(queue.size() - 1);
            boolean processedChildren = node.getNeighbours().isEmpty() || node.getNeighbours().stream()
                    .anyMatch(child -> visitied.getOrDefault(child, false));
            if (processedChildren) {
                visitied.put(node, true);
                function.accept(node, ++order);
                queue.remove(queue.size() - 1);
            } else {
                queue.addAll(node.getNeighbours());
            }
        }
    }

    private BiConsumer<TarjanNode, Integer> orderingTree() {
        return (node, order) -> {
            node.setOrder(order);
            node.setNumberOfChildren(node.getNeighbours().stream()
                    .map(TarjanNode::getNumberOfChildren)
                    .reduce(1, (a, b) -> a + b));
        };
    }

    private BiConsumer<TarjanNode, Integer> calculationLowestAndHighestNeigbour(Graph<Node> graph, Graph<TarjanNode> tree) {
        return (node, a) -> {
            int order = node.getOrder();
            Node graphNode = graph.findNode(node);
            List<TarjanNode> treeNeighbours = graphNode.getNeighbours().stream()
                    .map(tree::findNode)
                    .filter(treeNode -> !treeNode.equals(node.getParent()))
                    .collect(Collectors.toList());

            int smallestNeighbour = treeNeighbours.stream()
                    .map(treeNode -> Math.min(treeNode.getLowestNeighbour(), treeNode.getOrder()))
                    .reduce(order, Math::min);

            int highestNeighbour = treeNeighbours.stream()
                    .map(treeNode -> Math.max(treeNode.getHighestNeighbour(), treeNode.getOrder()))
                    .reduce(order, Math::max);

            node.setLowestNeighbour(smallestNeighbour);
            node.setHighestNeighbour(highestNeighbour);
        };
    }
}
