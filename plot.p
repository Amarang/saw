set title "final R^2 vs steps"
set ylabel "final R^2"
set xlabel "steps"

set terminal postscript
set output 'plot.ps'

plot    "output.txt" using 1:(abs($5*$5+$6*$6)) with points title ""

! ps2pdf14 plot.ps plot.pdf
! rm plot.ps
