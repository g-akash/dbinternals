        set xlabel "File sizes" 
        set ylabel "Percentage Hits" 
        set term png 
        set yrange [0:100]
        set title "Plot of file sizes vs Percentage hits for Nested Block Join" 
        set output "nestedblockjoinfilesize.png" 
        plot "nestedplotdata.txt" using 1:2 with linespoints title "lru vs File Size", "nestedplotdata.txt" using 1:3 with linespoints title "mru vs File Size", "nestedplotdata.txt" using 1:4 with linespoints title "lfu vs File Size", "nestedplotdata.txt" using 1:5 with linespoints title "mfu vs File Size","nestedplotdata.txt" using 1:6 with linespoints title "belady vs File Size"
		

		set xlabel "File sizes" 
        set ylabel "Percentage Hits" 
        set term png
        set yrange [0:100]
        set title "Plot of file sizes vs Percentage hits for Hash Join" 
        set output "hashjoinfilesize.png" 
        plot "hashplotdata.txt" using 1:2 with linespoints title "lru vs File Size", "hashplotdata.txt" using 1:3 with linespoints title "mru vs File Size", "hashplotdata.txt" using 1:4 with linespoints title "lfu vs File Size", "hashplotdata.txt" using 1:5 with linespoints title "mfu vs File Size","hashplotdata.txt" using 1:6 with linespoints title "belady vs File Size"


		set xlabel "File sizes" 
        set ylabel "Percentage Hits" 
        set term png 
        set yrange [0:100]
        set title "Plot of file sizes vs Percentage hits for Merge Join"
        set output "mergejoinfilesize.png" 
        plot "mergeplotdata.txt" using 1:2 with linespoints title "lru vs File Size", "mergeplotdata.txt" using 1:3 with linespoints title "mru vs File Size", "mergeplotdata.txt" using 1:4 with linespoints title "lfu vs File Size", "mergeplotdata.txt" using 1:5 with linespoints title "mfu vs File Size","mergeplotdata.txt" using 1:6 with linespoints title "belady vs File Size"


		set xlabel "File sizes" 
        set ylabel "Percentage Hits" 
        set term png 
        set yrange [0:100]
        set title "Plot of file sizes vs Percentage hits for Concurrent Queries"
        set output "randomfilesize.png" 
        plot "randomplotdata.txt" using 1:2 with linespoints title "lru vs File Size", "randomplotdata.txt" using 1:3 with linespoints title "mru vs File Size", "randomplotdata.txt" using 1:4 with linespoints title "lfu vs File Size", "randomplotdata.txt" using 1:5 with linespoints title "mfu vs File Size","randomplotdata.txt" using 1:6 with linespoints title "belady vs File Size"


		set xlabel "File sizes" 
        set ylabel "Percentage Hits" 
        set term png 
        set yrange [0:100]
        set title "Plot of file sizes vs Percentage hits for External Sort"
        set output "sortfilesize.png" 
        plot "sortplotdata.txt" using 1:2 with linespoints title "lru vs File Size", "sortplotdata.txt" using 1:3 with linespoints title "mru vs File Size", "sortplotdata.txt" using 1:4 with linespoints title "lfu vs File Size", "sortplotdata.txt" using 1:5 with linespoints title "mfu vs File Size","sortplotdata.txt" using 1:6 with linespoints title "belady vs File Size"
