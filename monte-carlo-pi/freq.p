set terminal png
set output "pi500.png"
set key off
set grid
set time
set xlabel "bin-width:0.001" font ",14"
set ylabel "frequency of occurrence" font ",14"
set title "frequency distribution of area [M=500]" font ",14"

bin_width = 0.001;
bin_number(x) = floor(x/bin_width)
rounded(x) = bin_width * ( bin_number(x) + 0.5 )
plot 'pi500.txt' using (rounded($2)) smooth frequency with impulses