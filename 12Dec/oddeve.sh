echo "Enter a number"
read a
rem=$((a%2))
if [ $rem -eq 0 ] 
then
echo "even number"
else
echo "odd number"
fi
