#include <benchmark/benchmark.h>
#include "GraphConfig.hpp"
#include "GraphReader.hpp"
#include "Graph.hpp"
#include "BridgesFinder.hpp"

using bridges_finder::GraphConfig;
using bridges_finder::GraphReader;
using bridges_finder::Graph;
using bridges_finder::BridgesFinder;

const std::vector<std::string> inputs {
        "../../input/in1.json",
        "../../input/in2.json",
        "../../input/in3.json",
};

static void BM_BridgesFinder(benchmark::State& state) {
    GraphConfig config;
    const auto filename = inputs[state.range(0)];
    GraphReader::readFile(filename, config);
    for (auto _ : state) {
        Graph graph{config};
        const auto& solution = BridgesFinder::find(graph);
    }
    state.SetLabel(filename);
}

static void CustomArguments(benchmark::internal::Benchmark* b) {
    for (int i = 0; i < inputs.size(); i++) {
        b->Arg(i);
    }
}

BENCHMARK(BM_BridgesFinder)->Apply(CustomArguments)->ComputeStatistics("max", [](const std::vector<double>& v) -> double {
    return *(std::max_element(std::begin(v), std::end(v)));
});

BENCHMARK_MAIN();
