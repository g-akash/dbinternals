#!/bin/bash
g++ sort.cpp 
./a.out $1 > 25261.txt
g++ hashblockjoin.cpp
./a.out $1 $2 > 25262.txt
g++ mergejoin.cpp
./a.out $1 $2 > 25263.txt
g++ nestedblockjoin.cpp
./a.out $1 $2 > 25264.txt
var1=$(wc -l < 25261.txt)
var2=$(wc -l < 25262.txt)
var3=$(wc -l < 25263.txt)
var4=$(wc -l < 25264.txt) 
g++ random.cpp
./a.out $var1 $var2 $var3 $var4 > inp.txt
rm 2526* 
