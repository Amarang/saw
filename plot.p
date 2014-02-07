set title "max R^2 vs steps"
set ylabel "max R^2"
set xlabel "steps"

set terminal postscript
set output 'plot.ps'

plot    "output.txt" using 1:4 with points title ""

! ps2pdf14 plot.ps plot.pdf
! rm plot.ps
