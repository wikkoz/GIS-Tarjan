package tarjan.reader;


import java.util.List;

public class GraphConfig {
    private List<String> vertices;
    private List<GraphEdgeConfig> edges;

    public List<String> getVertices() {
        return vertices;
    }

    public void setVertices(List<String> vertices) {
        this.vertices = vertices;
    }

    public List<GraphEdgeConfig> getEdges() {
        return edges;
    }

    public void setEdges(List<GraphEdgeConfig> edges) {
        this.edges = edges;
    }
}
