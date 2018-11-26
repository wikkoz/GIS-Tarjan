package tarjan.reader;

public class GraphEdgeConfig {
    private String firstEdge;
    private String secondEdge;

    public GraphEdgeConfig() {
    }

    public GraphEdgeConfig(String firstEdge, String secondEdge) {
        this.firstEdge = firstEdge;
        this.secondEdge = secondEdge;
    }

    public String getFirstEdge() {
        return firstEdge;
    }

    public void setFirstEdge(String firstEdge) {
        this.firstEdge = firstEdge;
    }

    public String getSecondEdge() {
        return secondEdge;
    }

    public void setSecondEdge(String secondEdge) {
        this.secondEdge = secondEdge;
    }
}
