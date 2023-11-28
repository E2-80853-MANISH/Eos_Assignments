#!/bin/bash
m=3
while [ $m -le 5 ]
echo -e “enter choice for print   :1. Date\n 2. Cal\n 3. Ls\n 4 . Pwd\n 5. Exit\n”
read m



do

case $m in
      1)date
          ;;
      2)cal
          ;;
     3)ls
          ;;
     4)pwd
          ;;
     5)exit
          ;; 

    *) echo "invalid input"  
esac

done
