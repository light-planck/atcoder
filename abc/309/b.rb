N = gets.to_i
A = Array.new(N) { gets.chomp }

B = Marshal.load(Marshal.dump(A))
(0...N).each do |i|
  (0...N).each do |j|
    next unless i == 0 || i == N - 1 || j == 0 || j == N - 1

    B[i][j + 1] = A[i][j] if i == 0 && j + 1 < N
    B[i + 1][j] = A[i][j] if i + 1 < N && j == N - 1
    B[i][j - 1] = A[i][j] if i == N - 1 && j > 0
    B[i - 1][j] = A[i][j] if i > 0 && j == 0
  end
end

puts B
