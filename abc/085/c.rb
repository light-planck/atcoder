# 入力の受け取り
N, Y = gets.split.map(&:to_i)

# 10000 円札 i 枚、5000 円札 j 枚、 1000 円札 k = N-i-j 枚
# として、条件を満たす組み合わせを全探索
(0..N).each do |i|
  (0..N).each do |j|
    k = N - i - j
    next if k < 0 # kは1000円札の枚数なので、0以上でなければならない

    total = (10_000 * i) + (5000 * j) + (1000 * k)
    if total == Y
      puts "#{i} #{j} #{k}"
      exit # 見つけたらプログラムを終了
    end
  end
end

# 条件を満たす組み合わせが存在しない場合
puts '-1 -1 -1'
