n = int(input())

happiness = []
for _ in range(n):
    a, b, c = map(int, input().split())
    happiness.append([a, b, c])

# dp[i + 1][j] i日目に活動jをしたときのそれまでの幸福度の最大値
dp = [[0] * 3 for _ in range(n + 1)]

for i in range(n):
    for j in range(3):
        for k in range(3):
            if j == k:
                continue

            dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + happiness[i][k])

print(max(dp[n]))