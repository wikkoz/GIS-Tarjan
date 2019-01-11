# Tarjan Algorithm Benchmark in Modern C++.

## Requirements

- language: C++17
- compiler: [GCC 7.3.0](https://ftp.gnu.org/gnu/gcc/gcc-7.3.0/)
- build config: [CMake 3.9](https://cmake.org/cmake/help/v3.9/)
- environment: [Python 3.6.7](https://www.python.org/downloads/release/python-367/)
- modules: [benchmark (*google*)](https://github.com/google/benchmark), [JSON for Modern C++ (*nlohmann*)](https://github.com/nlohmann/json)

**Note**: *nlohmann* module should be downloaded automatically when configuring project using CMake. If not, try to download (single header) and put in `lib` folder.

## How to use

1. Build project using makefiles created with help of CMake and source files

   ```shell
   $ python ./compile.sh
   ```

   You should now have two executables produced:

   - `bridges_finder` - simple test of solution,
   - `bridges_finder_bm` - benchmark,

   located in `cmake-build-release`.

2. To run you them directly, go into that folder.

3. You can also run benchmark using prepared script

```shell
$ python ./benchmark.sh
```

It has a few examples of usage (to see more visit *google benchmark* docs).

## Benchmark

### Example

Running `benchmark.sh` for provided basic inputs results in:

```shell
2019-01-11 21:35:23
Running ./bridges_finder_bm
Run on (8 X 2301 MHz CPU s)
CPU Caches:
  L1 Data 32K (x8)
  L1 Instruction 32K (x8)
  L2 Unified 256K (x8)
  L3 Unified 6144K (x8)
Load Average: 0.17, 0.13, 0.24
---------------------------------------------------------------------
Benchmark                          Time             CPU   Iterations
---------------------------------------------------------------------
BM_BridgesFinder/0_mean         6884 ns         6868 ns           10 ../../input/in1.json
BM_BridgesFinder/0_median       6852 ns         6840 ns           10 ../../input/in1.json
BM_BridgesFinder/0_stddev       91.5 ns         86.2 ns           10 ../../input/in1.json
BM_BridgesFinder/0_max          7108 ns         7082 ns           10 ../../input/in1.json
BM_BridgesFinder/1_mean        11545 ns        11530 ns           10 ../../input/in2.json
BM_BridgesFinder/1_median      11540 ns        11525 ns           10 ../../input/in2.json
BM_BridgesFinder/1_stddev        185 ns          184 ns           10 ../../input/in2.json
BM_BridgesFinder/1_max         11938 ns        11908 ns           10 ../../input/in2.json
BM_BridgesFinder/2_mean        14699 ns        14694 ns           10 ../../input/in3.json
BM_BridgesFinder/2_median      14703 ns        14700 ns           10 ../../input/in3.json
BM_BridgesFinder/2_stddev        157 ns          157 ns           10 ../../input/in3.json
BM_BridgesFinder/2_max         15011 ns        15005 ns           10 ../../input/in3.json
```

## Bridges finder

### Example

Running `bridges_finder` for provided basic inputs results in:

```shell
../../input/in1.json
--------------------------
 node: neighbours
--------------------------
    D: A B C
    C: A B D
    A: B C D
    B: A C D
--------------------------
 bridges
--------------------------
 Not found

../../input/in2.json
--------------------------
 node: neighbours
--------------------------
    G: E F
    B: A D
    A: B C
    C: A D
    D: B C E
    E: D F G
    F: E G
--------------------------
 bridges
--------------------------
 E-D

../../input/in3.json
--------------------------
 node: neighbours
--------------------------
    H: G I
    G: D H I
    B: A C
    I: G H
    A: B
    C: B D
    D: C E F G
    E: D F
    F: D E
--------------------------
 bridges
--------------------------
 C-B
 D-C
 B-A
 G-D
```

### Searching for bridges

It consists of the following steps:

1. Build spanning tree
   - using `std::stack<std::shared_ptr<Node>>` and `std::unordered_set<std::string>` to go through all `Nodes` (*post-order*).
2. Number nodes
   - setting `order`,
   - using `std::transform` and `std::accumulate` to calculate `NOC`  of `Node` (*post-order*).
3. Calculate `H(v)` and `L(v)`
   - using `std::transform` and `std::accumulate` to calculate `H(v)` and `L(v)` for every node (post-order)
4. Find bridge edges
   - Check `H(v)` and `L(v)` of neighbors and if meet Tarjan rule, treat them as bridges.

**Note**: It lacks of performance because of used `std::shared_ptr` instead of `raw` pointer for referring to graph collection.