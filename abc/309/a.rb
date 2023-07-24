a, b = gets.split.map(&:to_i)

if b-a == 1 && a%3 != 0
  puts "Yes"
else
  puts "No"
end