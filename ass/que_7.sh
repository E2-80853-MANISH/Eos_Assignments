#!/bin/bash

echo -e " enter no for check no. is positive or negative "

read num

if [ $num -gt 0 ]
  then
  echo " $num is positive"
  else
  echo "$num is negative "

 fi 