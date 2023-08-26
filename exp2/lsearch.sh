#!/bin/bash
echo "Linear Search"
read -p "Enter the size of array : " n
echo "Enter the elements"
for((i=0;i<n;++i))
do
  read a[$i]
done
read -p "Enter the element to be searched : " ele
for((i=0;i<n;++i))
do
  if [ $ele -eq ${a[$i]} ];
  then
    break
  fi
done
if [ $i -eq $n ];
then
  echo "The number does not exist"
else
  echo "the number exist at position $i"
fi
