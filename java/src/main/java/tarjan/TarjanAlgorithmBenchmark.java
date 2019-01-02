package tarjan;

import org.openjdk.jmh.annotations.*;
import org.openjdk.jmh.infra.Blackhole;
import tarjan.algorithm.Graph;
import tarjan.algorithm.GraphFactory;
import tarjan.algorithm.TarjanAlgorithm;
import tarjan.algorithm.node.Node;
import tarjan.reader.GraphConfig;
import tarjan.reader.GraphReader;

import java.util.concurrent.TimeUnit;

@OutputTimeUnit(TimeUnit.MILLISECONDS)
@Warmup(iterations = 2)
@Measurement(iterations = 3, time = 20)
@BenchmarkMode(Mode.SampleTime)
@State(Scope.Benchmark)
public class TarjanAlgorithmBenchmark {

    @State(Scope.Benchmark)
    public static class GraphPreparator {

        @Param({"in3.json", "in2.json", "in1.json"})
        public String file;

        public GraphConfig graphConfig;

        @Setup(Level.Trial)
        public void prepareGraph() {
            graphConfig = GraphReader.readFile(file);

        }

        public GraphConfig getGraphConfig() {
            return graphConfig;
        }
    }

    @Benchmark
    public void tajanAlgorithm(Blackhole blackhole, GraphPreparator graphPreparator) {
        TarjanAlgorithm tarjanAlgorithm = new TarjanAlgorithm();
        Graph<Node> graph = new GraphFactory().createGraph(graphPreparator.getGraphConfig());
        blackhole.consume(tarjanAlgorithm.tarjanAlgorithm(graph));
    }
}
