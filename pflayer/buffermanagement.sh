#!/bin/bash +x

set +x
set +v
file1s[0]=10;
file1s[1]=50;
file1s[2]=60;
file1s[3]=90;
file1s[4]=150;
file1s[5]=80;


file2s[0]=20;
file2s[1]=20;
file2s[2]=40;
file2s[3]=60;
file2s[4]=50;
file2s[5]=200;

echo "Started Working for Nested Block Join....."
i=0;
for((i=0;i<6;i++));do
#~ echo "$i Hello Akash whwre are you kjabflbmasd,nlaksjhnlk,ajfnmlk,hdsnkfl,mvn ,fdamgmnvlkjsxbdfx vk,jnfdlk,jvbks,dkjf";
touch nestplotdata.txt
touch nestedjoindata.txt
#~ echo "Oh my gof";
 echo "$((${file1s[$i]}+${file2s[$i]}))" >>nestedjoindata.txt
#~ echo "$((${file1s[$i]}+${file2s[$i]}))"
g++ nestedblockjoin.cpp;
./a.out ${file1s[$i]} ${file2s[$i]} >inp.txt
make -f lrumake clean
make -f lrumake 
./a.out >output.txt
rm disk
#~ echo "Hello";
#~ cat output.txt
#~ echo "Yolo"
make -f lrumake clean
g++ stat.cpp
./a.out <output.txt >> nestedjoindata.txt

make -f mrumake clean
make -f mrumake
./a.out >output.txt
rm disk
make -f mrumake clean
g++ stat.cpp
./a.out <output.txt >> nestedjoindata.txt

make -f lfumake clean
make -f lfumake
./a.out >output.txt
rm disk
make -f lfumake clean
g++ stat.cpp
./a.out <output.txt >> nestedjoindata.txt

make -f mfumake clean
make -f mfumake
./a.out >output.txt
rm disk
make -f mfumake clean
g++ stat.cpp
./a.out <output.txt >> nestedjoindata.txt


g++ belady.cpp
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> nestedjoindata.txt
 
done

g++ format.cpp
./a.out <nestedjoindata.txt > nestedplotdata.txt

echo "Completed Working for Nested Block Join....."

#First do the plotting here



echo "Started Working for Merge Join....."



for((i=0;i<6;i++));do
touch mergejoindata.txt
touch mergeplotdata.txt
 echo "$((${file1s[$i]}+${file2s[$i]}))" >>mergejoindata.txt
g++ mergejoin.cpp;
./a.out ${file1s[$i]} ${file2s[$i]} >inp.txt
make -f lrumake clean
make -f lrumake
./a.out >output.txt
rm disk
make -f lrumake clean
g++ stat.cpp
./a.out <output.txt >> mergejoindata.txt

make -f mrumake clean
make -f mrumake
./a.out >output.txt
rm disk
make -f mrumake clean
g++ stat.cpp
./a.out <output.txt >> mergejoindata.txt

make -f lfumake clean
make -f lfumake
./a.out >output.txt
rm disk
make -f lfumake clean
g++ stat.cpp
./a.out <output.txt >> mergejoindata.txt

make -f mfumake clean
make -f mfumake
./a.out >output.txt
rm disk
make -f mfumake clean
g++ stat.cpp
./a.out <output.txt >> mergejoindata.txt


g++ belady.cpp
./a.out >output.txt 

g++ stat.cpp
./a.out <output.txt >> mergejoindata.txt
done

g++ format.cpp
./a.out <mergejoindata.txt > mergeplotdata.txt

#plot the data here

echo "Completed Working for Merge Join....."

echo "Started Working for Hash Join....."

file1s[0]=10;
file1s[1]=80;
file1s[2]=130;
file1s[3]=170;
file1s[4]=140;
file1s[5]=190;


file2s[0]=10;
file2s[1]=20;
file2s[2]=70;
file2s[3]=90;
file2s[4]=140;
file2s[5]=190;


i=0;
for((i=0;i<6;i++));do
touch hashjoindata.txt
touch hashplotdata.txt
 echo "$((${file1s[$i]}+${file2s[$i]}))" >>hashjoindata.txt
g++ hashblockjoin.cpp;
./a.out ${file1s[$i]} ${file2s[$i]} >inp.txt
make -f lrumake clean
make -f lrumake
./a.out >output.txt
rm disk
make -f lrumake clean
g++ stat.cpp
./a.out <output.txt >> hashjoindata.txt

make -f mrumake clean
make -f mrumake
./a.out >output.txt
rm disk
make -f mrumake clean
g++ stat.cpp
./a.out <output.txt >> hashjoindata.txt

make -f lfumake clean
make -f lfumake
./a.out >output.txt
rm disk
make -f lfumake clean
g++ stat.cpp
./a.out <output.txt >> hashjoindata.txt

make -f mfumake clean
make -f mfumake
./a.out >output.txt
rm disk
make -f mfumake clean
g++ stat.cpp
./a.out <output.txt >> hashjoindata.txt



g++ belady.cpp
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> hashjoindata.txt

done

g++ format.cpp
./a.out <hashjoindata.txt > hashplotdata.txt

echo "Completed Working for Hash Join....."

echo "Started Working for  Concurrent Queries....."

#make the third plot here

i=0;
for((i=0;i<6;i++));do
touch randomdata.txt
touch randomplotdata.txt
echo "$((${file1s[$i]}*4+${file2s[$i]}*3))" >>randomdata.txt
#g++ hashblockjoin.cpp;
#./a.out ${file1s[$i]} ${file2s[$i]} >inp.txt
./script.sh ${file1s[$i]} ${file2s[$i]}


make -f lrumake clean
make -f lrumake
./a.out >output.txt
rm disk
make -f lrumake clean
g++ stat.cpp
./a.out <output.txt >> randomdata.txt

make -f mrumake clean
make -f mrumake
./a.out >output.txt
rm disk
make -f mrumake clean
g++ stat.cpp
./a.out <output.txt >> randomdata.txt

make -f lfumake clean
make -f lfumake
./a.out >output.txt
rm disk
make -f lfumake clean
g++ stat.cpp
./a.out <output.txt >> randomdata.txt

make -f mfumake clean
make -f mfumake
./a.out >output.txt
rm disk
make -f mfumake clean
g++ stat.cpp
./a.out <output.txt >> randomdata.txt



g++ belady.cpp
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> randomdata.txt

done

g++ format.cpp
./a.out <randomdata.txt > randomplotdata.txt


echo "Completed Working for  Concurrent Queries....."

echo "Started Working for  External Sort....."

#make the forth plot of the combined randomized stuff.

files[0]=130;
files[1]=230;
files[2]=350;
files[3]=440;
files[4]=450;
files[5]=600;


i=0;
for((i=0;i<6;i++));do
touch sortdata.txt
touch sortplotdata.txt
 echo "$((${files[$i]}))" >>sortdata.txt
g++ sort.cpp;
./a.out ${files[$i]} >inp.txt
make -f lrumake clean
make -f lrumake
./a.out >output.txt
rm disk
make -f lrumake clean
g++ stat.cpp
./a.out <output.txt >> sortdata.txt

make -f mrumake clean
make -f mrumake
./a.out >output.txt
rm disk
make -f mrumake clean
g++ stat.cpp
./a.out <output.txt >> sortdata.txt

make -f lfumake clean
make -f lfumake
./a.out >output.txt
rm disk
make -f lfumake clean
g++ stat.cpp
./a.out <output.txt >> sortdata.txt

make -f mfumake clean
make -f mfumake
./a.out >output.txt
rm disk
make -f mfumake clean
g++ stat.cpp
./a.out <output.txt >> sortdata.txt


g++ belady.cpp
./a.out >output.txt
g++ stat.cpp
./a.out <output.txt >> sortdata.txt

done

g++ format.cpp
./a.out <sortdata.txt > sortplotdata.txt

echo "Compted Working for  External Sort....."

echo "Started Plotting....."
gnuplot plotting.gnu
echo "Completed Plotting....."

echo "Removing Extra Files....."
rm *.txt
#plot the data here
echo "All Extra Files Removed....."


#rm *.txt



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


