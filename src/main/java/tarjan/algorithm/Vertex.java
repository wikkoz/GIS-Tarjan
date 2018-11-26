package tarjan.algorithm;

import java.util.HashSet;
import java.util.Objects;
import java.util.Set;

public class Vertex {
    private Set<Edge> edges=  new HashSet<>();
    private String identity;

    Vertex(String identity) {
        this.identity = identity;
    }

    public Set<Edge> getEdges() {
        return edges;
    }

    String getIdentity() {
        return identity;
    }

    void addEdge(Edge edge) {
        edges.add(edge);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Vertex vertex = (Vertex) o;
        return Objects.equals(identity, vertex.identity);
    }

    @Override
    public int hashCode() {
        return Objects.hash(identity);
    }
}
