echo "Enter a number"
read a
if [ $a -eq 1 ]
then 
	echo "$a is neither prime nor composite"
elif [ $a -eq 2 ]
then
	echo "$a is prime"
else
	fl=0
	i=2
	lim=$((a/2))
	while [ $i -le $lim ]
	do
		rem=$((a%i))
		if [ $rem -eq 0 ]
		then 
			fl=1
		break
		fi   
			i=$((i+1))
	done
	if [ $fl -eq 1 ]
	then 
		echo "$a is not prime"
	else
		echo "$a is prime"
	fi
fi
