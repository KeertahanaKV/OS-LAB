#!/bin/bash

echo "Enter the dimensions for a matrix"
echo -n "Rows: "
read m
echo -n "Columns: "
read n

declare -A x
declare -A y
declare -A z

echo "Enter the elements of the 1st $m x $n matrix:"
for ((i=0; i<m; i++))
do
	for ((j=0; j<n; j++))
	do
		read x[$i,$j]
	done
done

echo "Enter the elements of the 2nd $m x $n matrix:"
for ((i=0; i<m; i++))
do
	for ((j=0; j<n; j++))
	do
		read y[$i,$j]
	done
done

echo "Input matrices are:"
echo "First matrix:"
for ((i=0; i<m; i++))
do
	for ((j=0; j<n; j++))
	do
		echo -ne "${x[$i,$j]}  "
	done
	echo
done

echo "Second matrix:"
for ((i=0; i<m; i++))
do
	for ((j=0; j<n; j++))
	do
		echo -ne "${y[$i,$j]}  "
	done
	echo
done

echo "The resultant matrix after performing addition:"
for ((i=0; i<m; i++))
do
	for ((j=0; j<n; j++))
	do
		z[$i,$j]=$((x[$i,$j] + y[$i,$j]))
		echo -ne "${z[$i,$j]}  "
	done
	echo
done
