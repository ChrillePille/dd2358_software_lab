#set terminal dumb enhanced ansi256
#set term dumb 94 44
set terminal png
set autoscale
set output "flops_plot.png"
set xlabel "matrix size (n*n)"
set ylabel "Flops/s"
set title "Intel Core i7-8750H"
set border 3 lw 1
set tics nomirror
set key inside left
plot "naive_perf.dat" using 1:($3/1e9) with linespoints title "naive", \
     "cblas_perf.dat" using 1:($3/1e9) with linespoints title "OpenBLAS"