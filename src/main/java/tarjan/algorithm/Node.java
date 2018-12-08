package tarjan.algorithm;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Node {
    private Vertex node;
    private int order;
    private List<Node> neighbours = new ArrayList<>();

    public Node(Vertex node) {
        this.node = node;
    }

    public void addNeighbour(Node neighbour) {
        neighbours.add(neighbour);
    }

    public void setNeighbours(List<Node> neighbours) {
        this.neighbours = neighbours;
    }

    public Vertex getNode() {
        return node;
    }

    public void setOrder(int order) {
        this.order = order;
    }

    public String getIdentity() {
        return node.getIdentity();
    }

    public List<Node> getNeighbours() {
        return neighbours;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Node node1 = (Node) o;
        return node.equals(node1.node);
    }

    @Override
    public int hashCode() {
        return Objects.hash(node);
    }
}
