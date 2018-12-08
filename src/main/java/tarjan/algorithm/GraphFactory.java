package tarjan.algorithm;

import tarjan.algorithm.node.Node;
import tarjan.reader.GraphConfig;

import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;

public class GraphFactory {
    public Graph<Node> createGraph(GraphConfig graphConfig) {
        Map<String, Node> vertices = graphConfig.getVertices().stream()
                .map(Vertex::new)
                .collect(Collectors.toMap(Vertex::getIdentity, Node::new));

        graphConfig.getEdges()
                .forEach(e -> {
                    Node firstVertex = vertices.get(e.getFirstVertex());
                    Node secondVertex = vertices.get(e.getSecondVertex());
                    firstVertex.addNeighbour(secondVertex);
                    secondVertex.addNeighbour(firstVertex);
                });
        return new Graph<>(vertices.values()
                .stream()
                .collect(Collectors.toMap(Node::getVertex, Function.identity())));
    }
}