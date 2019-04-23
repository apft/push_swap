#!/bin/sh

if [ ! -f "gen.sh" ]; then
	echo "Error: missing file"
	exit 1
fi

n_nbr=100
n_try=100
if [ $# -ge 2 ]; then
	n_nbr=$1
	n_try=$2
fi

max=0
for i in `seq ${n_try}`
do
	./gen.sh -5000 5000 ${n_nbr} > output
	grep "KO" output > /dev/null && echo "KO" && exit 2
	n_actions=$(grep -A 1 "OK" output | tail -n 1)
	if [ "${n_actions}" -gt $max ]; then
		max=${n_actions}
	fi
done
echo "max on \x1b[1m${n_try}\x1b[0m tries for \x1b[1m${n_nbr}\x1b[0m numbers: ${max}"
