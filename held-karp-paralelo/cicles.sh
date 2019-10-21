#!/bin/bash

clear
g++ -std=c++11 leer.cpp main.cpp -fopenmp
for ((i=1; i<=$1;i++))
do
    export OMP_NUM_THREADS=$i
    if [ $i -eq 1 ]; then
    echo -e "No. of Threads $i" > results.txt
    echo -e "No. of Threads $i" > time_results.txt
    else
    echo -e "No. of Threads $i" >> results.txt
    echo -e "No. of Threads $i" >> time_results.txt
    fi
    for ((j=$2; j<=$3;j++))
    do
        echo -e "\t - No. of nodes $j" >> results.txt
        echo -e "\t - No. of nodes $j" >> time_results.txt
        { time ./a.out $j 1>> results.txt; } 2>> time_results.txt
        echo "-------------------------" >> results.txt
        echo "-------------------------" >> time_results.txt
    done
    echo "|-------------------------|" >> results.txt
    echo "|-------------------------|" >> results.txt
    echo "|-------------------------|" >> results.txt

    echo "|-------------------------|" >> time_results.txt
    echo "|-------------------------|" >> time_results.txt
    echo "|-------------------------|" >> time_results.txt
done