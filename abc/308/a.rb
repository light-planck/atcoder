s = gets.split.map(&:to_i)

ok = true

ok = false if s.sort != s
s.each do |x|
  ok = false if x < 100 || x > 675
  ok = false if x % 25 != 0
end

puts ok ? "Yes" : "No"