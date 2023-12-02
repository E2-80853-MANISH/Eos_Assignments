#!/bin/bash

echo -e "enter the year to check for leap year"

read y
if [ `expr $y % 400` -eq 0 -a `expr $y % 100` -eq 0 -o `expr $y % 4` -eq 0 ]
   then
       echo " $y year is leap year"
   else
       echo " $y year is not a leap year"
fi   