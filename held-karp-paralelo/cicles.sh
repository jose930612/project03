#!/bin/bash

clear
g++ -std=c++11 leer.cpp main.cpp -fopenmp
export OMP_NUM_THREADS=10
echo -e "No. of Threads 10" > results.txt
echo -e "No. of Threads 10" > time_results.txt
for ((j=$1; j<=$2;j++))
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

g++ -std=c++11 leer.cpp main.cpp -fopenmp
export OMP_NUM_THREADS=22
echo -e "No. of Threads 10" >> results.txt
echo -e "No. of Threads 10" >> time_results.txt
for ((j=$1; j<=$2;j++))
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
