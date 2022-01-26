n, max_w = map(int, input().split())

w = []
v = []
for _ in range(n):
    wi, vi = map(int, input().split())
    w.append(wi)
    v.append(vi)

dp = [[0] * (max_w + 1) for _ in range(n + 1)]
dp[0][0] = 0

for i in range(n):
    for j in range(max_w + 1):
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j])

        if j + w[i] <= max_w:
            dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i])

print(max(dp[n]))