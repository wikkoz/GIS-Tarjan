package tarjan.algorithm;

class Edge {
    private final Vertex first;
    private final Vertex second;

    Edge(Vertex first, Vertex second) {
        this.first = first;
        this.second = second;
    }

    Vertex getFirst() {
        return first;
    }

    Vertex getSecond() {
        return second;
    }
}
