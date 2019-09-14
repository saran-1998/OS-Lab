t=1;
i=0;
a=0;
while [ $i -lt 10 ]
do
a=$((a+t));
t=$((t+2));
i=$((i+1));
done
echo "Sum of first 10 odd numbers is $a"
