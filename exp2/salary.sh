#!/bin/bash
echo "Gross Salary Calculator"
read -p "Enter the basic salary : " salary
if [ $salary -lt 1500 ];
then
g_salary=$((salary+(salary*10/100)+(salary*90/100)))
echo "The gross salary is $g_salary"
else
g_salary=$((salary+500+(salary*98/100)))
echo "The gross salary is $g_salary"
fi
