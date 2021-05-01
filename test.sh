#! /bin/bash
# Made by dmilan
if [ $# -lt 2 ]; then
	echo "Error: not enough arguments"
	exit 1
fi

sum=0
min=100000000
max=0
max_steps=""
min_steps=""
steps=0
limit=20
echo
for i in `seq 1 $2`;
	do
		printf '|%-8.8s|' "$1: $i"
		ARG=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`;
		if [[ "$1" -lt "$limit" ]]; then
			printf ' %s |'  "$ARG"
		fi
		./push_swap $ARG | grep -E '(sa|sb|ss|ra|rb|rr|rra|rrb|rrr|pa|pb)' > steps
		steps=`cat steps | wc -l | awk '{ printf "%d\n", $0 }'`
		printf '%8.8s|'  "$steps"
		if [[ "$max" -lt "$steps" ]]; then
			max=$steps
			max_steps=$ARG
		fi
		if [[ "$min" -gt "$steps" ]]; then
			min=$steps
			min_steps=$ARG
		fi
		status=`cat steps | ./checker $ARG | grep -E '(OK|KO)'`
		sum=`expr $sum + $steps`
		printf '%s|\n'  "$status"

	done
if [[ "$1" -gt "$limit" ]]; then
	min_steps=""
	max_steps=""
fi
echo
avg=`expr $sum / $2`
printf '%s' "Average: "
printf '%s\n' "$avg"
printf '%s' "Max:     "
printf '%s' "$max"
if [[ "$1" -lt "$limit" ]]; then
	printf " - %s" "$max_steps"
fi
echo
rm steps
