#!/bin/bash

clear  #clear user screen
>cputime.txt #empty cputime file
EPOCH=`date +%s%N | cut -b1-13` #get time at start

#NAME OF COMPILED PROCESS
FILENAME=$(echo './main')

VAR=`ps -u $USER r | grep $FILENAME | cut -d' ' -f1` #get process id
while ps -u $USER r | grep $VAR > /dev/null #while process is running
do
CURTIME=`date +%s%N | cut -b1-13` #get current time
ELAPSED=$(($CURTIME-$EPOCH)) #calculate time elapsed

#output cpu usage
echo "$ELAPSED "`ps -p $VAR --no-headers -o %cpu` >> cputime.txt
done