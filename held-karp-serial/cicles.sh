#!/bin/bash

clear
g++ -std=c++11 leer.cpp main.cpp
for ((i=$1; i<=$2;i++))
do
    if [ $i -eq 1 ]; then
    echo -e "\t - No. of nodes $i" > results.txt
    echo -e "\t - No. of nodes $i" > time_results.txt
    else
    echo -e "\t - No. of nodes $i" >> results.txt
    echo -e "\t - No. of nodes $i" >> time_results.txt
    fi
    { time ./a.out $i 1>> results.txt; } 2>> time_results.txt
    echo "|-------------------------|" >> results.txt
    echo "|-------------------------|" >> results.txt
    echo "|-------------------------|" >> results.txt

    echo "|-------------------------|" >> time_results.txt
    echo "|-------------------------|" >> time_results.txt
    echo "|-------------------------|" >> time_results.txt
done