#!/bin/sh

if [ $# -ne 3 ]; then
	echo "usage: $0 {min} {max} {number of values}"
	exit
fi

export ARGS="$(seq ${1} ${2} | shuf -n ${3} | tr '\n' ' ' | sed 's/ $//')"

./push_swap $ARGS > out
./checker $ARGS < out

# number of actions
wc -l < out | bc

# args
echo $ARGS
