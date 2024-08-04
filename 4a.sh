#!/bin/bash

# Read number of rows and columns
echo "Enter the number of rows:"
read m
echo "Enter the number of columns:"
read n

# Read matrix X
echo "Enter the elements of matrix X:"
for ((i=0; i<m; i++)); do
    for ((j=0; j<n; j++)); do
        echo -n "Enter element X[$i,$j]: "
        read x[$i,$j]
    done
done

# Read matrix Y
echo "Enter the elements of matrix Y:"
for ((i=0; i<m; i++)); do
    for ((j=0; j<n; j++)); do
        echo -n "Enter element Y[$i,$j]: "
        read y[$i,$j]
    done
done

# Display matrix X
echo "Matrix X:"
for ((i=0; i<m; i++)); do
    for ((j=0; j<n; j++)); do
        echo -n "${x[$i,$j]} "
    done
    echo
done

# Display matrix Y
echo "Matrix Y:"
for ((i=0; i<m; i++)); do
    for ((j=0; j<n; j++)); do
        echo -n "${y[$i,$j]} "
    done
    echo
done

# Calculate and display matrix sum
echo "Matrix Sum (X + Y):"
for ((i=0; i<m; i++)); do
    for ((j=0; j<n; j++)); do
        sum=$((x[$i,$j] + y[$i,$j]))
        echo -n "${sum} "
    done
    echo
done
