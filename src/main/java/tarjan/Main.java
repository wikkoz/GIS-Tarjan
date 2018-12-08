package tarjan;

import tarjan.algorithm.Graph;
import tarjan.algorithm.GraphFactory;
import tarjan.algorithm.Vertex;
import tarjan.reader.GraphConfig;
import tarjan.reader.GraphEdgeConfig;
import tarjan.reader.GraphReader;

import java.util.Arrays;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        GraphConfig graphConfig = GraphReader.readFile("testGraph.json");
        Graph graph = new GraphFactory().createGraph(graphConfig);
        Graph tree = graph.buildTree();
    }
}
