MOD = 998244353

n = int(input())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

MAX_C = 3001

# dp[i + 1][j] 数列cのi番目がjとなるような場合の数
# dp[i + 1][j] = dp[i][0] + dp[i][1] + ... + dp[i][j - 1] + dp[i][j]
dp = [[0] * (MAX_C) for _ in range(n + 1)]
dp[0][0] = 1

for i in range(n):
    # ここでループするのはセーフ
    sum_dp = sum(dp[i][:a[i] + 1]) % MOD

    for j in range(a[i], b[i] + 1):
        # この中でループを回すとTLE
        
        sum_dp += dp[i][j]
        sum_dp %= MOD
        dp[i + 1][j] += sum_dp

# dp[n][j]は末尾がjとなるような数列cの場合の数であるから
# すべての場合の数を計算するためsum(dp[n])する必要がある。
print(sum(dp[n]) % MOD)


# O(N^3)
# for i in range(n):
#     for j in range(MAX_C):
#         if a[i] <= j and j <= b[i]:       
#             # [l:r] => [l, r)に注意
#             dp[i + 1][j] += sum(dp[i][:j + 1])
#             dp[i + 1][j] %= MOD