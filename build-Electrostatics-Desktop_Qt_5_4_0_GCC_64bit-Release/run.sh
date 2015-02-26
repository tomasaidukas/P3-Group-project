#!/bin/bash

>cputime.txt
EPOCH=`date +%s%N | cut -b1-13`

FILENAME='Electrostatics'

VAR=`ps -u $USER | grep $FILENAME | cut -d ' ' -f2` #get process id
while ps -u $USER | grep $VAR > /dev/null #while process is running
do
CURTIME=`date +%s%N | cut -b1-13` #get current time
ELAPSED=$(($CURTIME-$EPOCH)) #calculate time elapsed
CPUUSAGE=`ps -p $VAR --no-headers -o %cpu`
NUMCORES=`nproc`

#output cpu usage
echo "$ELAPSED "`bc <<< "scale=2; $CPUUSAGE / $NUMCORES"` >> cputime.txt
done

