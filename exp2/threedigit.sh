#!/bin/bash
echo "All 3 digit number with 1,2,3 and 0"
for((i=100;i<400;++i))
do
  num=$i
  flag=0
  while [ $num -ne 0 ]
  do
    r=$((num%10))
    if [ $r -ne 1 ] && [ $r -ne 2 ] && [ $r -ne 3 ] && [ $r -ne 0 ];
    then
      flag=1
      break
    fi
    num=$((num/10))
  done
  if [ $flag -eq 0 ];
  then
    echo "$i"
  fi
done
