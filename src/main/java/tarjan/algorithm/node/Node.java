package tarjan.algorithm.node;

import tarjan.algorithm.Vertex;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Node extends AbstractNode{
    private List<Node> neighbours = new ArrayList<>();

    public Node(Vertex vertex) {
        super(vertex);
    }

    public void addNeighbour(Node neighbour) {
        neighbours.add(neighbour);
    }

    public void setNeighbours(List<Node> neighbours) {
        this.neighbours = neighbours;
    }

    public List<Node> getNeighbours() {
        return neighbours;
    }
}
