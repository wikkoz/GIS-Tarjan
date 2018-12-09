package tarjan;

import tarjan.algorithm.Graph;
import tarjan.algorithm.GraphFactory;
import tarjan.algorithm.TarjanAlgorithm;
import tarjan.algorithm.node.Node;
import tarjan.reader.GraphConfig;
import tarjan.reader.GraphReader;

public class Main {

    public static void main(String[] args) {
        GraphConfig graphConfig = GraphReader.readFile("testGraph2.json");
        TarjanAlgorithm tarjanAlgorithm = new TarjanAlgorithm();
        Graph<Node> graph = new GraphFactory().createGraph(graphConfig);
        System.out.println(tarjanAlgorithm.tarjanAlgorithm(graph));
    }
}
