#!/bin/bach

echo -e "enter a number\n   "

read m
i=2
flag=0;
while [ $i -lt $m ]
do
  if [ `expr $m % $i` -eq 0 ]
  then
      flag=1
     #  echo "$m not a prime no."
       break
   fi
   i=`expr $i + 1`

done 
if [ $flag == 1 ]
then 
     echo "$m is not prime"
else 
     echo "$m is prime "
fi          
 