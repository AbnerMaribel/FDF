#!/bin/bash

WHITE="\033[00m"
BLACK="\033[01;30m"
RED="\033[01;31m"
GREEN="\033[04;32m"
YELLOW="\033[01;33m"
BLUE="\033[01;34m"
MAGENTA="\033[01;35m"
CYAN="\033[01;36m"
TEST_C="\033[02;30m"

# __________________________________________________________________SUBFUNCTIONS

fdf_babushka()
{
    printf "\033[2K\r"
    printf "$RED"
    printf "F$MAGENTA"
    printf "D$BLUE"
    printf "F $CYAN"
    printf "compiled $WHITE "
    local i=0
    while [ $i -le $1 ]
    do
        printf " "
        i=$(( $i + 1 ))
    done
    printf "🦋"
}

fdf_babushka_fly()
{
    if [ $3 -eq 1 ]
    then
        local i=0
        while [ $i -le $1 ]
        do
            fdf_babushka $i
            i=$(( $i + 1 ))
            sleep $2
        done
    else
        local i=$1
        while [ $i -gt -3 ]
        do
            fdf_babushka $i
            i=$(( $i - 1 ))
            sleep $2
        done
    fi
}

allocate_space()
{
    local i=0
    while [[ $i -le $1 ]]
    do
        printf "\n"
        i=$(( $i + 1 ))
    done
    printf "🦋"
}

# __________________________________________________________________________MAIN

count=1
dir=1
while [ $count -le $1 ]
do
    fdf_babushka_fly $2 $3 $dir
    if [ $dir -eq 0 ]
    then
        dir=1
    else
        dir=0
    fi
    sleep $4
    count=$(( $count + 1 ))
done
printf "\n"