package tarjan.algorithm;

import com.google.common.collect.Lists;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class TreeBuilder {
    public Graph buildTree(Node graphNode) {
        Map<Node, Boolean> visited = new HashMap<>();
        Map<Vertex, TarjanNode> treeNodes = new HashMap<>();
        List<Node> queue = Lists.newArrayList(graphNode);
        while (!queue.isEmpty()) {
            Node processedGraphNode = queue.remove(0);
            TarjanNode treeNode = getOrCreateNode(processedGraphNode, treeNodes);
            visited.put(processedGraphNode, true);
            processedGraphNode.getNeighbours().stream()
                    .filter(node -> !visited.getOrDefault(node, false))
                    .forEach(neighbourGraphNode -> {
                        queue.add(neighbourGraphNode);
                        visited.put(neighbourGraphNode, true);
                        Node childTreeNode = getOrCreateNode(neighbourGraphNode, treeNodes);
                        treeNode.addNeighbour(childTreeNode);
                    });
        }

        return new Graph<>(treeNodes, treeNodes.get(graphNode.getNode()));
    }


    private TarjanNode getOrCreateNode(Node graphNode, Map<Vertex, TarjanNode> treeNodes) {
        return treeNodes.computeIfAbsent(graphNode.getNode(), TarjanNode::new);
    }
}
