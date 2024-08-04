echo "enter the number of elements"
read n
echo "enter the array elements"
read -a num
largest=${num[0]}
for((i=1;i<n;i++))
do
        if [ ${num[i]} -gt $largest ]
        then
                largest=${num[i]}
        fi
done
echo "the largest number is $largest"
