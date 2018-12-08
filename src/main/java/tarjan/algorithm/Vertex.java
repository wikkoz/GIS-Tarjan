package tarjan.algorithm;

import java.util.Objects;

public class Vertex {
    private String identity;

    public Vertex(String identity) {
        this.identity = identity;
    }

    public String getIdentity() {
        return identity;
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
