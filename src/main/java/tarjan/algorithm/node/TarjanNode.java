package tarjan.algorithm.node;

import tarjan.algorithm.Vertex;

import java.util.ArrayList;
import java.util.List;

public class TarjanNode extends AbstractNode {
    private int order;
    private int numberOfChildren = 0;
    private int highestNeighbour = Integer.MIN_VALUE;
    private int lowestNeighbour = Integer.MAX_VALUE;
    private TarjanNode parent;
    private List<TarjanNode> neighbours = new ArrayList<>();

    public TarjanNode(Vertex node) {
        super(node);
    }

    public void addNeighbour(TarjanNode neighbour) {
        neighbours.add(neighbour);
        neighbour.setParent(this);
    }

    public List<TarjanNode> getNeighbours() {
        return neighbours;
    }

    public int getOrder() {
        return order;
    }

    public void setOrder(int order) {
        this.order = order;
    }

    public int getNumberOfChildren() {
        return numberOfChildren;
    }

    public void setNumberOfChildren(int numberOfChildren) {
        this.numberOfChildren = numberOfChildren;
    }

    public int getHighestNeighbour() {
        return highestNeighbour;
    }

    public void setHighestNeighbour(int highestNeighbour) {
        this.highestNeighbour = highestNeighbour;
    }

    public int getLowestNeighbour() {
        return lowestNeighbour;
    }

    public TarjanNode getParent() {
        return parent;
    }

    public void setParent(TarjanNode parent) {
        this.parent = parent;
    }

    public void setNeighbours(List<TarjanNode> neighbours) {
        this.neighbours = neighbours;
    }

    public void setLowestNeighbour(int lowestNeighbour) {
        this.lowestNeighbour = lowestNeighbour;
    }
}
