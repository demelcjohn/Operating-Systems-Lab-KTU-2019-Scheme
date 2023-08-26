#!/bin/bash
echo "Palindromic Prime"
read -p "Enter n : " n
i=$((n+1))
flag=0
while((flag==0))
do
  num=$i
  j=2
  while((j<num))
  do
    if [ $((num%j)) -eq 0 ];
    then
      break
    fi
    j=$((j+1))
  done
  if [ $j -eq $num ];
  then
    rev=0
    while((num!=0))
    do
      rev=$(((rev*10)+(num%10)))
      num=$((num/10))
    done
    if [ $rev -eq $i ];
    then
      flag=1
      echo "Smallest prime palindrome : $i"
    fi
  fi
  i=$((i+1))
done
