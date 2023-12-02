#!/bin /bash
echo -e "enter three no for maxmimum\n"
read a
read b
read c
if [ $a -gt $b ]
   then
    if [ $a -gt $c ]
    then
      echo "max= $a "
    else
      echo "max= $c "
    fi
else
      if [ $b -gt $c ]
      then
         echo "max= $b"
      else
         echo "max= $c"
      fi
fi      
     
