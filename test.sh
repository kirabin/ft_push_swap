#! /bin/bash
if [ $# -lt 2 ]; then
	echo "Error: not enough arguments"
	exit 1
fi

sum=0
steps=0
echo
echo "----------------------------"
for i in `seq 1 $2`;
	do
		printf '|%-8.8s|' "$1: $i"
		ARG=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`;
		./push_swap $ARG > steps
		steps=`cat steps | wc -l`
		printf '%8.8s|'  "$steps"
		status=`cat steps | ./checker $ARG`
		sum=`expr $sum + $steps`
		printf '%s|\n'  "$status"
	done
echo "----------------------------"
avg=`expr $sum / $2`
printf '%-10.10s' "Average:"
printf '%8.8s\n' "$avg"
rm steps
