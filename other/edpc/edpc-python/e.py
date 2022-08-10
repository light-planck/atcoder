# INF = 10 ** 9ではWA
INF = 10 ** 18

n, MAX_W = map(int, input().split())

w = []
v = []
for _ in range(n):
    wi, vi = map(int, input().split())
    w.append(wi)
    v.append(vi)

MAX_V = 10 ** 5 + 100

# dp[i + 1][j] i番目までの品物を袋に入れ、価値がvとなるような最小の重さ
dp = [[INF] * (MAX_V + 1) for _ in range(n + 1)]
dp[0][0] = 0

for i in range(n):
    for j in range(MAX_V):
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j])

        if j + v[i] <= MAX_V:
            dp[i + 1][j + v[i]] = min(dp[i + 1][j + v[i]], dp[i][j] + w[i])

ans = 0
for j in range(MAX_V + 1):
    if dp[n][j] <= MAX_W:
        ans = j

print(ans)