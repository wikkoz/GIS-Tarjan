package tarjan.algorithm.node;

import tarjan.algorithm.Vertex;

import java.util.Objects;

public abstract class AbstractNode {
    private Vertex vertex;

    public AbstractNode(Vertex vertex) {
        this.vertex = vertex;
    }

    public Vertex getVertex() {
        return vertex;
    }

    public String getIdentity() {
        return vertex.getIdentity();
    }


    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        AbstractNode node1 = (AbstractNode) o;
        return vertex.equals(node1.vertex);
    }

    @Override
    public int hashCode() {
        return Objects.hash(vertex);
    }
}
