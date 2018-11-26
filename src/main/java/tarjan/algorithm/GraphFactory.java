package tarjan.algorithm;

import tarjan.reader.GraphConfig;

import java.util.ArrayList;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;

public class GraphFactory {
    public Graph createGraph(GraphConfig graphConfig) {
        Map<String, Vertex> vertices =  graphConfig.getVertices().stream()
                .map(Vertex::new)
                .collect(Collectors.toMap(Vertex::getIdentity, Function.identity()));

        graphConfig.getEdges().stream()
                .map(e -> new Edge(vertices.get(e.getFirstEdge()), vertices.get(e.getSecondEdge())))
                .forEach(e -> {
                    e.getFirst().addEdge(e);
                    e.getSecond().addEdge(e);
                });
        return new Graph(new ArrayList<>(vertices.values()));
    }
}