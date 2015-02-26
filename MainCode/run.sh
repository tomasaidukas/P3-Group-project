#!/bin/bash

clear  #clear user screen
>cputime.txt #empty cputime file
EPOCH=`date +%s%N | cut -b1-13` #get time at start

#NAME OF COMPILED PROCESS
FILENAME="./main"

VAR=`ps -u $USER r | grep $FILENAME | cut -d ' ' -f2` #get process id
while ps -u $USER r | grep $VAR > /dev/null #while process is running
do
CURTIME=`date +%s%N | cut -b1-13` #get current time
ELAPSED=$(($CURTIME-$EPOCH)) #calculate time elapsed
CPUUSAGE=`ps -p $VAR --no-headers -o %cpu`
NUMCORES=`nproc | cut -d$'\n' -f1`

#output cpu usage
echo "$ELAPSED "`bc <<< "scale=2; $CPUUSAGE / $NUMCORES"` >> cputime.txt
done
