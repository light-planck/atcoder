n, x = map(int, input().split())
a = []
b = []
for _ in range(n):
    ai, bi = map(int, input().split())
    a.append(ai)
    b.append(bi)

# dp[i + 1][j] i回目までのジャンプで座標jに達しているか
dp =[[False] * (x + 1) for _ in range(n + 1)]
dp[0][0] = True

for i in range(n):
    for j in range(x + 1):
        if j - a[i] >= 0 and dp[i][j - a[i]]:
            dp[i + 1][j] = True
        if j - b[i] >= 0 and dp[i][j - b[i]]:
            dp[i + 1][j] = True

if dp[n][x]:
    print('Yes')
else:
    print('No')