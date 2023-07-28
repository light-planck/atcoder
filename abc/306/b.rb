A = gets.chomp.split.map(&:to_i)

ans = 0
A.each_with_index do |a, i|
  ans += a * (1 << i)
end

puts ans