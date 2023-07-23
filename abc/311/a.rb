n = gets.to_i
s = gets

cnt = {}
cnt.default = 0

s.chars.each_with_index do |c, i|
  cnt[c] += 1
  if cnt["A"] >= 1 && cnt["B"] >= 1 && cnt["C"] >= 1
    puts i+1
    break
  end
end
