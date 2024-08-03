# Read the number
echo "Enter a number:"
read num

# Reverse the number
reverse=$(echo $num | rev)

# Check if the original number and reversed number are the same
if [ "$num" == "$reverse" ]; then
    echo "$num is a palindrome."
else
    echo "$num is not a palindrome."
fi
#2nd method
: <<'END_COMMENT'
echo "read number"
read num
rev=0
original=$num
while [ "$num" -gt 0 ]
do
        rem=$((num%10))
        rev=$((rev*10+rem))
        num=$((num/10))
done
if [ "$original" -eq "$rev" ];then
        echo "palindrome"
else
        echo "not palindrome"
fi
