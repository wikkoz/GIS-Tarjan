package tarjan.reader;

public class GraphEdgeConfig {
    private String firstVertex;
    private String secondVertex;

    public GraphEdgeConfig() {
    }

    public GraphEdgeConfig(String firstVertex, String secondEdge) {
        this.firstVertex = firstVertex;
        this.secondVertex = secondVertex;
    }

    public String getFirstVertex() {
        return firstVertex;
    }

    public void setFirstVertex(String firstVertex) {
        this.firstVertex = firstVertex;
    }

    public String getSecondVertex() {
        return secondVertex;
    }

    public void setSecondVertex(String secondVertex) {
        this.secondVertex = secondVertex;
    }
}
