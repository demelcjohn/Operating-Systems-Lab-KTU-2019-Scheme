#!/bin/bash
echo "Smallest of 3 numbers"
echo "Enter 3 numbers"
read a
read b
read c
if [ $a -lt $b ];
then
  if [ $a -lt $c ];
  then
    echo "Smallest number is $a"
  else
    echo "Smallest number is $c"
  fi
else
if [ $b -lt $c ];
then
  echo "Smallest number is $b"
else
  echo "Smallest number is $c"
fi
fi
