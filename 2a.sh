#!/bin/bash

echo "Enter the lower bound:"
read lb
echo "Enter the upper bound:"
read ub

# Loop through each number in the range
for ((i = lb; i <= ub; i++)); do
    if [ $i -lt 2 ]; then
        continue
    fi
    flag=0
    for ((j = 2; j <= i / 2; j++)); do
        if [ $((i % j)) -eq 0 ]; then
            flag=1
            break
        fi
    done
    if [ $flag -eq 0 ]; then
        echo "$i"
    fi
done
