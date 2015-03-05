#!/bin/bash

>cputime.txt
EPOCH=`date +%s%N | cut -b1-13`

FILENAME='main'

VAR=`ps -u $USER r | grep $FILENAME | cut -d ' ' -f1` #get process id
while ps -u $USER r | grep $VAR > /dev/null #while process is running
do
CURTIME=`date +%s%N | cut -b1-13` #get current time
ELAPSED=$(($CURTIME-$EPOCH)) #calculate time elapsed
USAGE=`ps -p $VAR --no-headers -o %cpu`

#output cpu usage
echo "$ELAPSED $USAGE" >> cputime.txt
done

