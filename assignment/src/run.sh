#!/bin/bash 
EXEC=$1
NAIVEOUT=$2
CBLASOUT=$3

for i in `seq 10 10 500`;
do
    echo $i
    ./$EXEC $i 1 >> $NAIVEOUT
    ./$EXEC $i 2 >> $CBLASOUT
done  