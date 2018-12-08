package tarjan.algorithm;

import java.util.Map;

public class Graph<T extends Node> {
    private final Map<Vertex,T> nodes;
    private final Node root;
    private final TreeBuilder treeBuilder = new TreeBuilder();

    Graph(Map<Vertex, T> nodes) {
        this.nodes = nodes;
        this.root = root();
    }

    public Graph(Map<Vertex, T> nodes, Node root) {
        this.nodes = nodes;
        this.root = root;
    }

    public Graph buildTree() {
        return treeBuilder.buildTree(root);
    }

    private Node root() {
        return nodes.get(0);
    }
}
