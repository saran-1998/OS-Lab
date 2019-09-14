i=0
sum=0
while [ $i -lt 10 ]
do 
echo "Enter the number $i"
read a
sum=$(( $sum+$a ))
i=$(($i+1))
done
echo "Sum = $sum"
