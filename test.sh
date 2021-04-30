#! /bin/bash

sum=0
steps=0
echo
echo "----------------------------"
for i in `seq 1 $2`;
	do
		ARG=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`;
		./push_swap $ARG > steps
		steps=`cat steps | wc -l`
		status=`cat steps | ./checker $ARG`
		sum=`expr $sum + $steps`
		printf '|%-8.8s' "test $i"
		printf '|%8.8s'  "$steps"
		printf '|%8.8s|\n'  "$status"
	done
echo "----------------------------"
avg=`expr $sum / $2`
printf '%-10.10s' "Average:"
printf '%8.8s\n' "$avg"
rm steps
