#!/bin/bash
echo "Armstrong Numbers"
read -p "Enter the lowest number in range : " a
read -p "Enter the largest number in range : " b
for((i = $a;i<=$b;i++))
do
  num=$i
  n=-1
  while [ $num -gt 0 ]
  do
    n=$((n+1))
    num=$((num/10))
  done
  ans=0
  num=$i
  while [ $num -ne 0 ]
  do
    r=$((num%10))
    v=r
    for((j=$n;j>0;j--))
    do
      v=$((v*r))
    done
    ans=$((ans+v))
    num=$((num/10))
  done
  if [ $ans -eq $i ];
  then
    echo "$i"
  fi
done
