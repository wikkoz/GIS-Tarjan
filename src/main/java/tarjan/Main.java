package tarjan;

import tarjan.algorithm.Graph;
import tarjan.algorithm.GraphFactory;
import tarjan.reader.GraphConfig;
import tarjan.reader.GraphEdgeConfig;

import java.util.Arrays;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        GraphConfig graphConfig = new GraphConfig();
        List<String> vertices = Arrays.asList("A", "B", "C", "D");
        List<GraphEdgeConfig> edges = Arrays.asList(new GraphEdgeConfig("A", "B"), new GraphEdgeConfig("A", "C"),
        new GraphEdgeConfig("A", "D"), new GraphEdgeConfig("B", "C"), new GraphEdgeConfig("D", "B"), new GraphEdgeConfig("D", "C"));
        graphConfig.setEdges(edges);
        graphConfig.setVertices(vertices);
        Graph graph = new GraphFactory().createGraph(graphConfig);
    }
}
