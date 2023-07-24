*, p, q = gets.split.map(&:to_i)
d = gets.split.map(&:to_i)

ans = [p, (q + d.min)]
puts ans.min