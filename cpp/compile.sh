#!/bin/bash
mkdir -p cmake-build-release && cd cmake-build-release
cmake -DCMAKE_BUILD_TYPE=Release -G "CodeBlocks - Unix Makefiles" ..
if [[ $? -eq 0 ]]; then
    cmake --build /home/lime/workspace/github/GIS-Tarjan/cpp/cmake-build-release --target bridges_finder_bm
fi
cd ..