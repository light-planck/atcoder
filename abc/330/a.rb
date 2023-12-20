N, L = gets.split.map(&:to_i) # 配列から多重代入
A = gets.split.map(&:to_i) # 横1行のスペース区切りの整数を配列として受け取る

puts(A.count { |a| a >= L }) # 条件を満たす要素の数を数える
