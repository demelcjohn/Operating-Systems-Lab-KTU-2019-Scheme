echo "Number Pattern"
read -p "Enter the value of n : " n
for((i=1;i<=$n;++i))
do
  for((j=0;j<$i;++j))
  do
    echo -n "$i "
  done
  echo ""
done
