#!/bin/bash

# Read number of rows and columns
echo "Enter the number of rows:"
read m
echo "Enter the number of columns:"
read n

# Initialize matrices
declare -a x
declare -a y

# Read matrix X
echo "Enter the elements of matrix X:"
for ((i=0; i<m; i++)); do
    for ((j=0; j<n; j++)); do
        index=$((i * n + j))
        echo -n "Enter element X[$i,$j]: "
        read x[$index]
    done
done

# Read matrix Y
echo "Enter the elements of matrix Y:"
for ((i=0; i<m; i++)); do
    for ((j=0; j<n; j++)); do
        index=$((i * n + j))
        echo -n "Enter element Y[$i,$j]: "
        read y[$index]
    done
done

# Display matrix X
echo "Input matrix X:"
for ((i=0; i<m; i++)); do
    for ((j=0; j<n; j++)); do
        index=$((i * n + j))
        echo -n "${x[$index]} "
    done
    echo
done

# Display matrix Y
echo "Input matrix Y:"
for ((i=0; i<m; i++)); do
    for ((j=0; j<n; j++)); do
        index=$((i * n + j))
        echo -n "${y[$index]} "
    done
    echo
done

# Calculate and display matrix sum
echo "Matrix Sum (X + Y):"
for ((i=0; i<m; i++)); do
    for ((j=0; j<n; j++)); do
        index=$((i * n + j))
        sum=$((x[$index] + y[$index]))
        echo -n "${sum} "
    done
    echo
done
