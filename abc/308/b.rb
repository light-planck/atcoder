* = gets.chomp.split.map(&:to_i)
C = gets.chomp.split
D = gets.chomp.split
P = gets.chomp.split.map(&:to_i)

price = {"none" => P.first}
P.shift
D.zip(P).each do |d, p|
  price[d] = p
end

ans = 0
C.each do |c|
  ans += price[c].nil? ? price["none"] : price[c]
end

puts ans