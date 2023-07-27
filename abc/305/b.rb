p, q = gets.chomp.split

x = [0, 3, 4, 8, 9, 14, 23]
puts (x[p.ord - 'A'.ord] - x[q.ord - 'A'.ord]).abs