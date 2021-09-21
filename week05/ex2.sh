#!/bin/sh

FILE="file" # file to read
LOCK="${FILE}.lock" # lock file

if [ ! -f $FILE ] # if file doesn't exist
then
    echo 0 > $FILE
fi

while [ -f $LOCK ] # while lock file exists
do
    :
done

ln $FILE $LOCK
for i in {1..1000}
do
    num=( $(cat FILE | tail -n 1) )
    num=$(( $num + 1 ))
    printf "\n%ld" "${num}" >> FILE
done
rm $LOCK