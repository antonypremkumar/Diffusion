set datafile separator ","
set dgrid3d 100,100

set terminal pngcairo size 800, 600
set output "T.png"

set view map
set contour base
set cntrparam levels incremental 10,10,100

unset surface
set style data pm3d
set pm3d map

set palette defined(0 "blue", 1 "cyan", 2 "green", 3 "yellow", 4 "orange", 5 "red")

set xlabel "X-axis"
set ylabel "Y-axis"
set zlabel "Z-axis"

splot "T.csv" using 1:2:3

