#!/bin/bash
cd cmake-build-release

PREFIX=$(date +%H%M%S)

# Basic
#./bridges_finder_bm

# Repeated with standard deviation, max, median
#./bridges_finder_bm --benchmark_repetitions=10

# Standard deviation, max, and median
#./bridges_finder_bm --benchmark_display_aggregates_only=true --benchmark_repetitions=10

# Save to PREFIX_out.csv
./bridges_finder_bm --benchmark_display_aggregates_only=true --benchmark_repetitions=10 --benchmark_out_format=csv --benchmark_out="../${PREFIX}_out.csv"

# Also filter
#./bridges_finder_bm --benchmark_display_aggregates_only=true --benchmark_repetitions=10 --benchmark_out_format=csv --benchmark_out="../${PREFIX}_out.csv" --benchmark_filter=BM_BridgesFinder/0

cd ..