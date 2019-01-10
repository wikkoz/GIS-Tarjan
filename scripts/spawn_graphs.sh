#!/bin/sh

for i in $(seq 100 100 10000); do
    filename="../input/$i.json"
    command="-t long_list -n $i -o $filename"
    echo "\"../${filename}\","
    python generate_graph.py ${command}
done
