echo "Enter the lower bound"
read lb
echo "Enter the upper bound"
read ub
flag=0
for((i=lb;i<=ub;i++))
do
  for((j=2;j<=i/2;j++))
  do
    if [ $((i%j)) -eq 0 ]; then
    flag=1
    break
    fi
  done
  if [ $flag -eq 0 ]; then
  echo -ne " $i"
   fi
   flag=0
done
