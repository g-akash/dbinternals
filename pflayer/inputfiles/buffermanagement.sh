#!/bin/bash

file1s[0]=1;
file1s[1]=2;
file1s[2]=3;
file1s[3]=4;
file1s[4]=5;
file1s[5]=6;


file2s[0]=1;
file2s[1]=2;
file2s[2]=3;
file2s[3]=4;
file2s[4]=5;
file2s[5]=6;


i=0;
for((i=0;i<6;i++));do
touch nestedjoindata.txt
echo "$((file1s[$i]+file2s[$2]))" >>nestedjoindata.txt
g++ nestedblockjoin.cpp;
./a.out file1s[$i] file2s[$i]; >input.txt
make lrumake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> nestedjoindata.txt

make mrumake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> nestedjoindata.txt

make lfumake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> nestedjoindata.txt

make mfumake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> nestedjoindata.txt

make rrmake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> nestedjoindata.txt


g++ belady.cpp
./a.out <output.txt >>sortdata.txt
done

g++ format.cpp
./a.out <nestedjoindata.txt > nestedjoindata.txt



#First do the plotting here


for((i=0;i<6;i++));do
touch mergejoindata.txt
echo "$((file1s[$i]+file2s[$2]))" >>mergejoindata.txt
g++ mergeblockjoin.cpp;
./a.out file1s[$i] file2s[$i]; >input.txt
make lrumake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> mergejoindata.txt

make mrumake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> mergejoindata.txt

make lfumake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> mergejoindata.txt

make mfumake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> mergejoindata.txt

make rrmake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> mergejoindata.txt


g++ belady.cpp
./a.out <output.txt >>sortdata.txt
done

g++ format.cpp
./a.out <mergejoindata.txt > mergejoindata.txt

#plot the data here


file1s[0]=1;
file1s[1]=2;
file1s[2]=3;
file1s[3]=4;
file1s[4]=5;
file1s[5]=6;


file2s[0]=1;
file2s[1]=2;
file2s[2]=3;
file2s[3]=4;
file2s[4]=5;
file2s[5]=6;


i=0;
for((i=0;i<6;i++));do
touch hashjoindata.txt
echo "$((file1s[$i]+file2s[$2]))" >>hashjoindata.txt
g++ hashblockjoin.cpp;
./a.out file1s[$i] file2s[$i]; >input.txt
make lrumake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> hashjoindata.txt

make mrumake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> hashjoindata.txt

make lfumake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> hashjoindata.txt

make mfumake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> hashjoindata.txt

make rrmake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> hashjoindata.txt



g++ belady.cpp
./a.out <output.txt >>sortdata.txt
done

g++ format.cpp
./a.out <hashjoindata.txt > hashjoindata.txt


#make the third plot here


files[0]=1;
files[1]=2;
files[2]=3;
files[3]=4;
files[4]=5;
files[5]=6;


i=0;
for((i=0;i<6;i++));do
touch sortdata.txt
echo "$((files[$i]))" >>sortdata.txt
g++ hashblockjoin.cpp;
./a.out file1s[$i]; >input.txt
make lrumake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> sortdata.txt

make mrumake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> sortdata.txt

make lfumake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> sortdata.txt

make mfumake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> sortdata.txt

make rrmake
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> sortdata.txt

g++ belady.cpp
./a.out <output.txt >>sortdata.txt
done

g++ format.cpp
./a.out <hashjoindata.txt > sortdata.txt


#plot the data here






#~ gnuplot <<- EOF
        #~ set xlabel "File sizes"
        #~ set ylabel "Percentage Hits"
        #~ set term png
        #~ set output "$nestedblockjoinfilesize.png"
        #~ plot "output.txt" using 1:2 with linespoints title "Nested Block Join vs File Size"
    #~ EOF
#~ gnuplot <<- EOF
        #~ set xlabel "File sizes"
        #~ set ylabel "Percentage Hits"
        #~ set term png
        #~ set output "$mergejoinfilesize.png"
        #~ plot "output.txt" using 1:2 with linespoints title "Merge Join vs File Size"
    #~ EOF
#~ gnuplot <<- EOF
        #~ set xlabel "File sizes"
        #~ set ylabel "Percentage Hits"
        #~ set term png
        #~ set output "$ExtrenalSortfilesize.png"
        #~ plot "output.txt" using 1:2 with linespoints title "External Sort vs File Size"
    #~ EOF
#~ gnuplot <<- EOF
        #~ set xlabel "File sizes"
        #~ set ylabel "Percentage Hits"
        #~ set term png
        #~ set output "$HashJoinfilesize.png"
        #~ plot "output.txt" using 1:2 with linespoints title "Hash Join vs File Size"
    #~ EOF
