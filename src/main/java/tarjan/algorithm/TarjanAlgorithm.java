package tarjan.algorithm;

import com.google.common.collect.Lists;
import com.google.common.collect.Sets;
import org.apache.commons.lang3.tuple.Pair;
import tarjan.algorithm.node.Node;
import tarjan.algorithm.node.TarjanNode;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.function.BiConsumer;
import java.util.stream.Collectors;

public class TarjanAlgorithm {
    private final TreeBuilder treeBuilder = new TreeBuilder();

    public Set<Pair<Vertex, Vertex>> tarjanAlgorithm(Graph<Node> graph) {
        Graph<TarjanNode> tree = treeBuilder.buildTree(graph.getRoot());
        numberNodes(tree, orderingTree());
        numberNodes(tree, calculationLowestAndHighestNeigbour(graph, tree));
        return findBridgeEdges(tree);
    }

    private void numberNodes(Graph<TarjanNode> tree, BiConsumer<TarjanNode, Integer> function) {
        List<TarjanNode> queue = Lists.newArrayList(tree.getRoot());
        Map<TarjanNode, Boolean> visited = new HashMap<>(tree.getSize());
        int order = 0;
        while (!queue.isEmpty()) {
            TarjanNode node = queue.get(queue.size() - 1);
            boolean processedChildren = node.getNeighbours().isEmpty() || node.getNeighbours().stream()
                    .anyMatch(child -> visited.getOrDefault(child, false));
            if (processedChildren) {
                visited.put(node, true);
                function.accept(node, ++order);
                queue.remove(queue.size() - 1);
            } else {
                queue.addAll(node.getNeighbours());
            }
        }
    }

    private Set<Pair<Vertex, Vertex>> findBridgeEdges(Graph<TarjanNode> tree) {
        return tree.getNodes().values().stream()
                .flatMap(node -> node.getNeighbours().stream()
                                .filter(treeNode -> treeNode.getHighestNeighbour() <= treeNode.getOrder() && treeNode.getLowestNeighbour() > treeNode.getOrder() - treeNode.getNumberOfChildren())
                                .map(treeNode -> (Pair.of(node.getVertex(), treeNode.getVertex()))))
                .collect(Collectors.toSet());
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
