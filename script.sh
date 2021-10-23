#!/bin/bash

if [ $# -ne 3 ]
then
	echo " usage: $0 stack_size loop_count push_swap_exe"
	exit 1
fi

rm -f tmp

for i in `seq 1 $2`
do
	ARG=$(python3 -c "import random;a = random.sample(range($1 + $1), $1); print(' '.join([str(i) for i in a]))")
	$3 $ARG | wc -l | tr -d ' ' >> tmp
	tail -n 1 tmp
done