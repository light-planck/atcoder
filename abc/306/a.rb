* = gets.to_i
s = gets.chomp

s.each_char do |c|
  print c + c
end
puts ""