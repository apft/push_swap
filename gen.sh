#!/bin/sh

[ "$#" -eq 1 ] && lim="$1" || lim=10

ARGS=""
for i in `seq 1 1 $lim`
do
	r=$RANDOM
   	[ $(($RANDOM % 2)) -eq 0 ] && r="-$r"
   	ARGS="$ARGS $r"
done
echo $ARGS
