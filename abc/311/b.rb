N, D = gets.split.map(&:to_i)
S = Array.new(N) {gets}

ans = 0
now = 0

(0..D-1).each do |d|
  ok = true
  S.each do |s|
    ok = false if s[d] == "x"
  end
  
  now = ok ? now + 1 : 0
  ans = [ans, now].max
end

puts ans