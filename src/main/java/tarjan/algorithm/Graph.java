package tarjan.algorithm;

import tarjan.algorithm.node.AbstractNode;

import java.util.Map;

public class Graph<T extends AbstractNode> {
    private final Map<Vertex,T> nodes;
    private final T root;

    Graph(Map<Vertex, T> nodes) {
        this.nodes = nodes;
        this.root = root();
    }

    public Graph(Map<Vertex, T> nodes, T root) {
        this.nodes = nodes;
        this.root = root;
    }

    public int getSize() {
        return nodes.size();
    }

    public T getRoot() {
        return root;
    }

    public T findNode(AbstractNode node) {
        return nodes.get(node.getVertex());
    }

    private T root() {
        return nodes.values().stream().findFirst().orElseThrow(() -> new IllegalArgumentException("Cannot find the root of graph"));
    }
}
