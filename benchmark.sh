#!/bin/bash

# Directories for input files and benchmarking results
input_dir="/tmp/volsort_inputs"
output_file="benchmark_results.txt"

# Create the input directory if it doesn't exist
mkdir -p $input_dir

# Remove old output file if it exists
rm -f $output_file

# Array of input sizes
sizes=(10 100 1000 10000 100000 1000000 10000000)
# Sorting modes
modes=("STL" "QSORT" "MERGE" "QUICK")

# Generate input files
for size in "${sizes[@]}"; do
    echo "Generating input file with $size integers..."
    python -c "import random; print('\n'.join(map(str, random.sample(range($size * 10), $size))))" > "$input_dir/input_$size.txt"
done

# Benchmark each sorting mode with each input size
for mode in "${modes[@]}"; do
    for size in "${sizes[@]}"; do
        echo "Benchmarking $mode with $size integers..."
        # Time the sorting operation and redirect the output to /dev/null
        result=$( (time ./volsort -m $mode $input_dir/input_$size.txt > /dev/null) 2>&1 )
        # Extract real time and write to the output file
        elapsed_time=$(echo "$result" | grep real | awk '{print $2}')
        echo "$mode $size $elapsed_time" >> $output_file
    done
done

echo "Benchmarking complete. Results saved in $output_file."

