# 入力の受け取り
N, Y = gets.split.map(&:to_i)

# 10000 円札 i 枚、5000 円札 j 枚、1000 円札 k 枚
# として、条件を満たす組み合わせを全探索
(0..N).each do |i|
  (0..N).each do |j|
    (0..N).each do |k|
      next if i + j + k != N

      total = (10_000 * i) + (5000 * j) + (1000 * k)
      if total == Y
        puts "#{i} #{j} #{k}"
        exit # 見つけたらプログラムを終了
      end
    end
  end
end

# 条件を満たす組み合わせが存在しない
puts '-1 -1 -1'
